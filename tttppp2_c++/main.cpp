#include <iostream>
#include <stdio.h>
#include <fstream>
#include "Facturator2DaCount.h"
#include <string>
using namespace std;




int main(int argc, const char* argv[]) {
    Produit Facture;
    string line;
    int i, compteur = 0;

    string Fichier_entree;
    string FichierSortie;

    cout << "Indiquez l'Emplacement du fichier à lire : " << endl;
    cin >> Fichier_entree;
    cout << "Indiquez l'Emplacement du fichier à Ecrire : " << endl;
    cin >> FichierSortie;


    //verification des fichiers

    ofstream monFlux(FichierSortie.c_str());
    ifstream file(Fichier_entree.c_str());
    if (monFlux) {}
    else {
        cout << "ERREUR: Impossible d'ouvrir le fichier en Ecriture : Fin du programme." << endl;
    }

    if (file) {}
    else {
        cout << "ERREUR: Impossible d'ouvrir le fichier en Lecture : Fin du programme." << endl;
    }




    if (file) {


        while (getline(file, line)) {
            compteur++;
            if (compteur == 1) { strcpy_s(Facture.ID_produit, line.c_str()); }
            else if (compteur == 2) {
                // On recupere le descriptif, mais on n'en fait rien , peut etre pour un prochain programme ?
            }
            else if (compteur == 3) {
                Facture.prix = line;



                for (i = 0; i < 19; i++) { //19 car il faut eviter le dernier caractère "\0" de retour a la ligne
                    if (i == 4 || i == 9 || i == 14) {} // on ne fait rien , pour ne pas mettre les ":"
                    else {
                        monFlux << Facture.ID_produit[i];
                    }
                }

                monFlux << " " << Facture.prix << endl;
                compteur = 0;
            }
        } // end du while de parcours du file
    }


    file.close();

    return 0;
}
