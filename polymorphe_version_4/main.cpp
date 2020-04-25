//
//  main.cpp
//  TP_polymorphe

#include "Polymorphe.h"
#include <iostream>
#include <queue> //priority queue
using namespace std;

double FacturableParUnite::applique_taxes(double prix) const //fonction appliquant la taxe pour les elements FacturableParUnite
{
    double prix_taxee = prix;
    prix_taxee += prix * 0.08; // taxe de vente basique
    prix_taxee += prix * 0.05; // taxe d'hebergement
    return prix_taxee;
}

double FacturableFraisFixe::applique_taxes(double prix) const //fonction appliquant la taxe pour les elements FacturableFraisFixe
{
    double prix_taxee = prix;
    prix_taxee += prix * 0.08; // taxe de vente basique
    prix_taxee += prix * 0.07; // taxe additionnelle
    return prix_taxee;
}


ElementFacturable::ElementFacturable(double prix)
    :prix(prix)
{}

FacturableParUnite::FacturableParUnite(int quantitee, double prix)
    : ElementFacturable(prix), quantitee(quantitee)
{}

FacturableFraisFixe::FacturableFraisFixe(double prix)
    : ElementFacturable(prix)
{}
//Constructeurs

ElementFacturable::~ElementFacturable()
{}
FacturableFraisFixe::~FacturableFraisFixe()
{}
FacturableParUnite::~FacturableParUnite()
{}

//destructeurs


void Menu(int* choix) //process d'affichage du menu
{

    cout << "1.    Ajouter des nuitees" << endl;
    cout << "2.    Ajouter des repas" << endl;
    cout << "3.    Ajouter un acces au spa" << endl;
    cout << "4.    Ajouter un acces au gym" << endl;
    cout << "5.    Afficher la facture et quitter" << endl;
    cin >> *choix;
}

int demander_quantitee() { //fonction pour demander la quantité souhaité (nombre de repas , nombre de nuit , etc ...)
    int quantitee = 0;
    cout << "Choisissez la quantitee souhaitee :" << endl;
    cin >> quantitee;
    return quantitee;
}

double taxes(ElementFacturable const& Element, double prix)  // passé en argument
{
    return Element.applique_taxes(prix);
}


int main()
{
    int choix = 0;
    bool continue_facture = 1;
    int quantitee_nuit = 0;
    int quantitee_repas = 0;
    bool gym_bool = 0;
    bool spa_bool = 0;
    double Facture = 0.0;
    double Delta_facture = 0.0;
    priority_queue<int> queue_int;
    // de type int car on a juste une priorité entre 1 et 4 à gérer (vector<int> donc ...)
   

    while (continue_facture)
    {
        while (choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5)
        {
            Menu(&choix);
            if (choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5)
            {
                cout << "[ERROR].    Mauvaise entrée, recommencez" << endl;
            }
        } // boucle : on s'assure que le choix est bien fait (chiffre compris entre 1 et 5)
        cout << string(100, '\n');
        switch (choix)
        {
        case 1:
            if (quantitee_nuit == 0) {
                cout << "Choisissez la quantitee souhaitee :" << endl;
                cin >> quantitee_nuit;
                queue_int.push(4);//Le plus important, donc la priorité la plus elevé

            }
            else {
                cout << "[ERROR].    Vous avez deja renseigné le nombre de nuit" << endl;
            }
            break;
        case 2:
            if (quantitee_repas == 0) {
                quantitee_repas = demander_quantitee();
                queue_int.push(3);
            }
            else {
                cout << "[ERROR].    Vous avez deja renseigné le nombre de repas" << endl;
            }
            break;
        case 3:
            if (spa_bool == 0) {
                queue_int.push(2);
                spa_bool = 1;
                cout << "[SUCCES].    Vous etes desormais inscrit au spa" << endl;
            }
            else {
                cout << "[ERROR].    Vous etes deja inscrit au spa" << endl;
            }
            break;
        case 4:
            if (gym_bool == 0) {
                queue_int.push(1);//Le moins important, donc la priorité la plus elevé
                gym_bool = 1;
                cout << "[SUCCES].    Vous etes desormais inscrit à la gym" << endl;
            }
            else {
                cout << "[ERROR].    Vous etes deja inscrit à la gym" << endl;
            }
            break;
        case 5:
            continue_facture = 0;
            break;
        default:
            cout << "[ERROR].    mauvaise valeur de choix" << endl;
            break;


        }
        choix = 0; // on reinitialise le choix pour le prochain menu


    }// tant que ce while est actif, on continue d'ajouter des items a la factures


    if (queue_int.empty()) {
        cout << "[Vous n'avez rien commandé, ce sera donc GRATUIT !]" << endl;
    }
    else {
        cout << "Votre Facture (en $) " << endl;

        while (!queue_int.empty()) {

            if (queue_int.top() == 4) {
                FacturableParUnite nuits(quantitee_nuit, 100.0);
                Delta_facture = taxes(nuits, nuits.prix * quantitee_nuit);
                Facture += Delta_facture;
                cout << "1.    Prix des nuits : " << Delta_facture << " $ " << endl;
            }
            if (queue_int.top() == 3) {
                FacturableParUnite repas(quantitee_repas, 20.0);
                Delta_facture = taxes(repas, repas.prix * quantitee_repas);
                Facture += Delta_facture;
                cout << "2.    Prix des repas : " << Delta_facture << " $ " << endl;
            }
            if (queue_int.top() == 2) {
                FacturableFraisFixe spa(75.0);
                Delta_facture = taxes(spa, spa.prix);
                Facture += Delta_facture;
                cout << "3.    Abonnement au spa : " << Delta_facture << " $ " << endl;
            }
            if (queue_int.top() == 1) {
                FacturableFraisFixe gym(50.0);
                Delta_facture = taxes(gym, gym.prix);
                Facture += Delta_facture;
                cout << "4.    Abonnement a la gym : " << Delta_facture << " $ " << endl;
            }

            queue_int.pop();
        }

        cout << "TOTAL :" << Facture << " $ " << endl;

    }


    return 0;
}
