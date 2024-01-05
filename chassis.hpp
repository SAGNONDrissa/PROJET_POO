// chassis.hpp
#ifndef __CHASSIS_H__
#define __CHASSIS_H__

    class chassis
    {
    protected :
        int nbportes;
        bool option;
        float L1,L2,l,h; // L1: longueur, L2: longueur toit, l: largeur, h: hauteur
        float cx, prix,R;
        string typeCh;
    public:
        chassis();
        void setNbportes(int nbportes);
        void setOption(bool option);
        int getNbportes();
        bool getOption();
        string gettypeCh();
        virtual float calculerCx()=0;
        virtual float calculerPrix()=0;
    };
    /*___________________COUPE ET COMPAGNIE ____________________*/
    class chassisCOUPE : public chassis
    {
        public:
            chassisCOUPE();
            float calculerCx();
            float calculerPrix();
    };

    /*___________________BERLINE ET COMPAGNIE ____________________*/
    class chassisBERLINE : public chassis
    {
    public:
        chassisBERLINE();
        virtual float calculerCx();
        virtual float calculerPrix();
    };

    // BERLINE STANDARD
    class chassisBerlineSTD : public chassisBERLINE
    {
    public:
        chassisBerlineSTD();
        float calculerCx();
        float calculerPrix();
    };

    // BERLINE BREAK
    class chassisBerlineBREAK : public chassisBERLINE
    {
    public:
        chassisBerlineBREAK();
        float calculerCx();
        float calculerPrix();
    };

    // BERLINE 4x4
    class chassisBerline4x4 : public chassisBERLINE
    { 
    public:
        chassisBerline4x4();
        float calculerCx();
        float calculerPrix();
    };
#endif // __CHASSIS_H__

