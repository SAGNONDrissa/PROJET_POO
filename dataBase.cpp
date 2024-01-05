// database.cpp
#include <iomanip>
#include <iostream>
using namespace std;
#include <list> 
#include "dataBase.hpp"
#include "voiture.hpp"

dataBase::dataBase(/* args */)
{
};

void dataBase::inserer(Voiture *vp)
{        
    car = vp;
    carsDB.push_back(car);
};

void dataBase::lister()
{
    cout<<setprecision(2);
    cout<<"\n Liste des modeles en commande***************"<<endl;
    cout<<"  _____________________________________________________________________________"<<endl;
    for (auto i = carsDB.begin(); i != carsDB.end(); i++)
    {           
        if((*i)->gettypeM()=="ELEC"){
            cout<<fixed<<" | "<<(*i)->gettypeCh()<<" | "<<(*i)->getNbportes()<<" P | "<<(*i)->getOption()<<" | "<<(*i)->getCylindree()<<" | "<<(*i)->gettypeM()<<" |  "<<(*i)->getPuissance()<<" CV | "<<(*i)->calculerVitesseMax()<<" Km/h | "<< (*i)->calculerPrix()<<" € |"<<endl;    
        }else
            cout<<fixed<<" | "<<(*i)->gettypeCh()<<" | "<<(*i)->getNbportes()<<" P | "<<(*i)->getOption()<<" | "<<(*i)->getCylindree()<<" | "<<(*i)->gettypeM()<<" | "<<(*i)->getPuissance()<<" CV | "<<(*i)->calculerVitesseMax()<<" Km/h | "<< (*i)->calculerPrix()<<" € |"<<endl;
        cout<<" |__________|_____|______|_______|______|___________|_____________|____________|"<<endl;        
    }
};

void dataBase::selectionner()
{       
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"CHOIX CRITERE :  ";
    cout<<"1: berline; 2: 4x4; 3: break; 4: coupe; 5: HDI; 6: ESS; 7 : ELEC; 8: LUXE  \n Votre choix ? ";
    cin>>choix;
};

void dataBase::filtrer(dataBase *db, dataBase *temp_db){
    cout<<"filttrage en cours ..."<<"choix : "<<choix<<endl;
    switch (choix)
    {
    case 1:

        for (auto i = db->carsDB.begin(); i != db->carsDB.end(); i++){
            if((*i)->gettypeCh()=="BL STD  "){
                temp_db->carsDB.push_back(*i);
            }
        }
        break;
    case 2:
        for (auto i = db->carsDB.begin(); i != db->carsDB.end(); i++){
            if((*i)->gettypeCh()=="BL 4x4  "){
                temp_db->carsDB.push_back(*i);
            }
        }
        break;
    case 3:
        for (auto i = db->carsDB.begin(); i != db->carsDB.end(); i++){
            if((*i)->gettypeCh()=="BL BREAK"){
                temp_db->carsDB.push_back(*i);
            }
        }
        break;
    case 4:
        for (auto i = db->carsDB.begin(); i != db->carsDB.end(); i++){
            if((*i)->gettypeCh()=="CC      "){
                temp_db->carsDB.push_back(*i);
            }
        }
        break;
    case 5:
        for (auto i = db->carsDB.begin(); i != db->carsDB.end(); i++){
            if((*i)->gettypeM()=="HYB "){
                temp_db->carsDB.push_back(*i);
            }
        }
        break;
    case 6:
        for (auto i = db->carsDB.begin(); i != db->carsDB.end(); i++){
            if((*i)->gettypeM()=="ESS "){
                temp_db->carsDB.push_back(*i);
            }
        }
        break;
    case 7:
        for (auto i = db->carsDB.begin(); i != db->carsDB.end(); i++){
            if((*i)->gettypeM()=="ELEC"){
                temp_db->carsDB.push_back(*i);
            }
        }
        break;
    case 8:
        for (auto i = db->carsDB.begin(); i != db->carsDB.end(); i++){
            if((*i)->getOption()=="LUXE"){
                temp_db->carsDB.push_back(*i);
            }
        }
        break;
    
    default:
        cout<<"No choice"<<endl;
        break;
    }



}
