//configurator.cpp 
#include <iostream>
using namespace std;

#include <string>
#include "configurator.hpp"
#include "voiture.hpp"
#include "chassis.hpp"
#include "moteur.hpp"

configurator::configurator(){
    /*Constructeur*/
}

Voiture *configurator::config(){
    moteur *m;
    chassis *ch;
    int choix_nrg;
    int choix_cyl, choix_mth;
    int typeCh;
    bool option;
    cout << "\n________________________________________________________\n";
    cout << "Chassis !!!"<<endl;
    cout << "Option ? 0-STD  1-LUXE    : ";
    cin >> option;
    cout << "Type ? 1-COUPE ou 2-Berline    : ";
    cin>>typeCh;
    if(typeCh==1){
        ch = new chassisCOUPE();
    }else if(typeCh==2){
        int typeBn;
        ch = new chassisBERLINE();
        cout<<"Chassis Berline !!!"<<endl;
        cout<<"Modele ? 1-STD  2-4x4  3-BREAK    : ";
        cin>>typeBn; 
        if(typeBn == 1){
            ch = new chassisBerlineSTD();
        }else if(typeBn ==2){
            ch = new chassisBerline4x4();
        }else if(typeBn ==3){
            ch = new chassisBerlineBREAK();
        }
    }
    ch->setOption(option);
    cout << "__________________________________\n";
    cout << "Moteur !!! \n"<<endl;
    cout << "TYPE ? (1-THER   2-ELEC  3-HYB)?    : ";
    cin >> choix_nrg;
    if(choix_nrg==1){
        cout << "Cylindree (valeur entiere)?    : ";
        cin >> choix_cyl;
        m = new moteurTHER(choix_cyl);
        cout<< "Entrer 1-moteurDIES ou 2-moteurESS ?    : "; 
        cin >> choix_mth;
        if (choix_mth==1){
            m=new moteurDIES(choix_cyl);
        }else 
            m=new moteurESS(choix_cyl); 
    }else if(choix_nrg == 2){
        m = new moteurELEC();
    }else if(choix_nrg == 3){
        cout << "Cylindree (valeur entiere)?    : ";
        cin >> choix_cyl;
        moteurELEC *mel; moteurESS *mes;
        m=new moteurHYB(choix_cyl);
    }
    car = new Voiture(m,ch);
    return car;
};

void configurator::afficher(){
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<" | "<<car->gettypeCh()<<" | "<<car->getNbportes()<<" P | "<<car->getOption()<<" | "<<car->getCylindree()<<" | "<<car->gettypeM()<<" | "<<car->getPuissance()<<" CV | "<<car->calculerVitesseMax()<<" Km/h | "<< car->calculerPrix()<<" € |"<<endl;
}