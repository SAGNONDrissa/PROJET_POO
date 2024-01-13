// entrepot.cpp
#ifndef __ENTREPOT__
#define __ENTREPOT__
    #include "chassis.hpp"
    #include "moteur.hpp"
    #include <list>
    class entrepot
    {
    private:
        list <chassis*> stockChassis;
        list <moteur*> stockMoteur;
    public:
        entrepot();
        void ajouterChassis(chassis *ch);
        void ajouterMoteur(moteur *m);
        void lister();
        void retirerChassis(chassis *ch);
        void retirerMoteur(moteur *m);
    };
#endif
    