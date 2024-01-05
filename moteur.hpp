// moteur.hpp
#ifndef __MOTEUR_H__
#define __MOTEUR_H__
    #include <iostream>
    using namespace std;
    #include <string>

    class moteur
    {
    protected: 
        float puissance, consommation, prix;
        string typeM;
        int cylindree;
    public:
        moteur();
        virtual float calculerPuissance()=0;
        virtual float calculerConsommation()=0;
        virtual float calculerPrix()=0;
        float getPuissance();
        float getConsommation();
        string gettypeM();
        int getCylindree();
    };
    
    //__________ MOTEUR THERMIQUE ET COMPAGNIE __________
    class moteurTHER : public moteur
    {
    protected:
        float K,Q;
    public:
        moteurTHER(int c);
        void setCylindree(int c);
        int getK();
        float calculerPuissance();
        virtual float calculerConsommation();
        virtual float calculerPrix();
    };

    // MOTEUR DIESEL
    class moteurDIES : public moteurTHER
    {
    public:
        moteurDIES(int c);
        float calculerConsommation();
        float calculerPrix();
    };

    // MOTEUR ESSENCE 
    class moteurESS : public moteurTHER
    {
    public:
        moteurESS(int c);
        float calculerConsommation();
        float calculerPrix();
    };

    //__________ MOTEUR ELECTRIQUE ET COMPAGNIE __________
    class moteurELEC : public moteur
    {
    public:
        moteurELEC();
        float calculerPuissance();
        float calculerConsommation();
        float calculerPrix();
    };

    //__________ MOTEUR HYBRIDE
    class moteurHYB : public moteur {
    protected:
        moteurELEC *mel;
        moteurESS *mes;        
    public:
        moteurHYB(int c);
        float calculerPuissance();
        float calculerConsommation();
        float calculerPrix();
    };
#endif // __MOTEUR_H__