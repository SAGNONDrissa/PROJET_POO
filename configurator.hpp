// configurateur.hpp
#ifndef __CONFIGURATOR_H__
#define __CONFIGURATOR_H__
    #include "voiture.hpp"

    class configurator
    {
    protected:
        Voiture *car;
    public:
        configurator();
        Voiture *config();
        void afficher();
    };
    
#endif // __CONFIGURATOR_H__

// Path: PROJET_VOITURE/voiture.h