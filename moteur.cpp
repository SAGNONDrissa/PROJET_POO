//moteur.cpp
#include <iostream>
using namespace std;
#include <math.h>
#include "moteur.hpp"
#include <string>

moteur::moteur(){   
    puissance = 0;
    consommation = 0;
};
float moteur::getPuissance(){return puissance;};
float moteur::getConsommation(){return consommation;};
string moteur::gettypeM(){return typeM;};
int moteur::getCylindree(){return cylindree;};

/*___________________MOTEUR THERMIQUE ET COMPAGNIE ____________________*/
moteurTHER::moteurTHER(int c){   
    cylindree = c;   Q = 0.055;
    typeM = "TH    ";  consommation = 0;
};

void moteurTHER::setCylindree(int c){cylindree = c;};

int moteurTHER::getK(){return K;};

float moteurTHER::calculerConsommation(){
    consommation = (Q * this->calculerPuissance()); // A COMPLETER
    return consommation;
};
float moteurTHER::calculerPrix(){return 0;};

moteurESS::moteurESS(int c):moteurTHER(c){K = 0.07; typeM = "ESS ";};

moteurDIES::moteurDIES(int c):moteurTHER(c){K = 0.06; typeM = "DIES";};

float moteurTHER::calculerPuissance(){
    puissance = cylindree * K; return puissance;
};  

// MOTEUR DIESEL
float moteurDIES::calculerConsommation(){   
    consommation = (Q * this->calculerPuissance()) / (log10(puissance / 6));
    return consommation;
};

float moteurDIES::calculerPrix(){ 
    if(cylindree==2200)
        prix = 2000+1000;
    else  prix = 2000;
    return prix;
};

// MOTEUR ESSENCE
float moteurESS::calculerConsommation(){   
    consommation = (Q * this->calculerPuissance());
    return consommation;
};
float moteurESS::calculerPrix(){ 
    if(cylindree==2200)
        prix = 0+1000;
    else  prix = 0;
    return prix;
};


/*___________________MOTEUR ELECTRIQUE ET COMPAGNIE ____________________*/
moteurELEC::moteurELEC(){puissance = 95.0 ; typeM = "ELEC"; cylindree = 0;};

float moteurELEC::calculerPuissance(){puissance = 95.0 ; return puissance;};

float moteurELEC::calculerConsommation(){consommation = 0; return consommation;};

float moteurELEC::calculerPrix(){return 3000;};

// MOTERU HYBRIDE
moteurHYB::moteurHYB(int c){
    mel = new moteurELEC(); //creation d'un objet moteurELEC
    mes = new moteurESS(c); //creation d'un objet moteurESS
    typeM = "HYB "; cylindree = mes->getCylindree();
};

float moteurHYB::calculerPuissance(){
    puissance = mel->calculerPuissance() + mes->calculerPuissance();
    return puissance;
};

float moteurHYB::calculerConsommation(){
    consommation = (mel->calculerConsommation() + mes->calculerConsommation())/2;
    return consommation;
};

float moteurHYB::calculerPrix(){prix = 3000;  return prix;};
