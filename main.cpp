#include <iostream>
using namespace std;

#include <math.h>
#include "moteur.hpp"
#include "chassis.hpp"
#include "voiture.hpp"
#include "configurator.hpp"
#include "dataBase.hpp"



int main(void){
        
    dataBase DB{};
    configurator CF{};
    Voiture *vp;
    int rep;
    for(;;){
        while(true){
            cout<<"\n configurator in process ..."<<endl;
            vp = CF.config();
            CF.afficher();
            DB.inserer(vp);
            cout<<"Continuez ? 1-OUI  0-NON : ";
            cin>>rep; 
            if(rep==0){
                break;
            }
        }
        DB.lister();

        dataBase *temp_db;
        temp_db = new dataBase();
        DB.selectionner();
        
        DB.filtrer(&DB, temp_db);

        temp_db->lister();

        cout<<"\nBYE BYE CMS.........."<<endl;

    }
    return 0;
}

// Path: PROJET_VOITURE/main.cpp