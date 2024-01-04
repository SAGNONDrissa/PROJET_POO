#include <iostream>
using namespace std;
#include <string>
#include <math.h>
#include "voiture.hpp"


Voiture::Voiture(moteur *m, chassis *ch){
    this->m=m;
    this->ch=ch;
    prix=25000;
    vitesseMax=0;
    this->nbportes = ch->getNbportes();
    this->Puissance = m->calculerPuissance();
    this->option = ch->getOption();
    this->typeCh = ch->gettypeCh();
    this->typeM = m->gettypeM();
    if(!(ch->getOption())){option = "STRD";} else option = "LUXE";
    this->cylindree = m->getCylindree();
}

float Voiture::calculerPrix(){
    prix=25000+m->calculerPrix()+ch->calculerPrix();
    return prix;
}

float Voiture::calculerVitesseMax(){
    vitesseMax=2*(m->calculerPuissance())*(1-ch->calculerCx());
    return vitesseMax;
}

int Voiture::getNbportes(){return nbportes;};
string Voiture::gettypeCh(){return typeCh;};
string Voiture::gettypeM(){return typeM;};
string Voiture::getOption(){return option;};
float Voiture::getPuissance(){return Puissance;};
string Voiture::getCylindree(){
    if(cylindree!=0)   return "c"+to_string(cylindree);
    else return "*****";
};

// Path: PROJET_VOITURE/berline.cpp