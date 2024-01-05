// chassis.cpp
#include <iostream>
using namespace std;

#include "chassis.hpp"
#include <string>

chassis::chassis(){
    nbportes=0;    option=false;
    L1=4.6;    L2=0;    l=0;    h=0;    R=0.03;
};

void chassis::setNbportes(int nbportes){
    this->nbportes=nbportes;
};

void chassis::setOption(bool option){
    this->option=option;
};

int chassis::getNbportes(){
    return nbportes;
};

bool chassis::getOption(){
    return option;
};

string chassis::gettypeCh(){return typeCh;};
/*___________________COUPE ET COMPAGNIE ____________________*/
chassisCOUPE::chassisCOUPE(){
    L1=4.6; l=1.3; h=2.2;
    typeCh = "CC      ";
    nbportes = 2;
};

float chassisCOUPE::calculerCx(){
    cx = R*l*(L1/2)*h;
    return cx;
};
float chassisCOUPE::calculerPrix(){
    if(option)   prix = 2000+1500;
    else         prix = 2000+0;
    return prix;
};

/*___________________BERLINE ET COMPAGNIE ____________________*/
chassisBERLINE::chassisBERLINE(){
    L1=4.6; nbportes = 4;
};
float chassisBERLINE::calculerCx(){return cx;};
float chassisBERLINE::calculerPrix(){return prix;};
// BERLINE STANDARD
chassisBerlineSTD::chassisBerlineSTD(){
    l=2.2; h=1.4; L2=2; typeCh = "BL STD  ";
};

float chassisBerlineSTD::calculerCx(){
    cx= R*((L1-h/2+L2)/2 *l*h+(h/2));
    return cx;
};

float chassisBerlineSTD::calculerPrix(){
    if(option==true)   prix= 1500;
    else               prix= 0;
    return prix;
};

// BERLINE BREAK

chassisBerlineBREAK::chassisBerlineBREAK(){
    l=2.2;    h=1.4;  L2=3.2; typeCh = "BL BREAK";
};

float chassisBerlineBREAK::calculerCx(){
    cx= R*(L1+L2)/2 *l*h;
    return cx;
};

float chassisBerlineBREAK::calculerPrix(){
    if(option==true)   prix= 1000+1500;
    else               prix= 3000+0;
    return prix;
};

// BERLINE 4x4
chassisBerline4x4::chassisBerline4x4(){
    l=2.5;    h=1.3; typeCh = "BL 4x4  ";
};

float chassisBerline4x4::calculerCx(){
    cx= R*L1*l*h;   return cx;
};

float chassisBerline4x4::calculerPrix(){
    if(option==true)   prix= 3000+1500;
    else               prix= 3000+0;
    return prix;
};

// Path: PROJET_VOITURE/berline.cpp