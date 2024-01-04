#ifndef __VOITURE_H__
#define __VOITURE_H__

#include "moteur.hpp"
#include "chassis.hpp"
#include <string>


class Voiture
{
private:
    /* data */
    moteur *m;
    chassis *ch;
    float prix,Puissance,vitesseMax;
    string option,typeM,typeCh;
    int cylindree, nbportes;
    
public:
    Voiture(moteur *m, chassis *c);
    float calculerPrix();
    float calculerVitesseMax();
    int getNbportes();
    string gettypeCh();
    string gettypeM();
    string getOption();
    float getPuissance();
    string getCylindree();
};

#endif // __VOITURE_H__