// database.hpp
#ifndef __DATABASE_H__
#define __DATABASE_H__
    #include "voiture.hpp"
    #include <list>

    class dataBase
    {
    private:
        /* data */
        Voiture *car;
        list<Voiture*> carsDB;
        int choix; bool status;

    public:
        dataBase(/* args */);
        void inserer(Voiture *vp);
        void lister();
        void selectionner(); 
        void filtrer(dataBase *db, dataBase *temp_db);
        void retirer(Voiture *vp);
    };
#endif 