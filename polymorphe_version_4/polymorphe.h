//
//  Polymorphe.h
//  TP_polymorphe


#ifndef Polymorphe_h
#define Polymorphe_h

#include <stdio.h>

class ElementFacturable // chaque element Unitaire ou fixe est défini par la fonction ci dessus
{
public:
    double prix;

    ElementFacturable(double prix);
    virtual double applique_taxes(double prix) const = 0; // ici le const = 0 permet de définir la fonction virtuelle pure
    // applique taxe n'est que utiisable par les classe hérités (FacturableParUnite etFacturableFraisFixe)
    virtual ~ElementFacturable();



};

class FacturableParUnite : public ElementFacturable  //Une classe pour les nuitees et les repas , ou tout autre element de facture unitaire
{
public:
    FacturableParUnite(int quantitee, double prix);
    virtual double applique_taxes(double prix) const;
    virtual ~FacturableParUnite();

private:
    int quantitee;

};

class FacturableFraisFixe : public ElementFacturable  //la gym et le spa sont des  ElementFacturable de la classe FacturableFraisFixe
{
public:
    FacturableFraisFixe(double prix);
    virtual double applique_taxes(double prix) const;
    virtual ~FacturableFraisFixe();




};
#endif /* Polymorphe_h */
