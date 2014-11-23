#ifndef TYPE_HPP
#define TYPE_HPP

class Type 
{

    public :

        // Nom du type
        virtual const char * getType() = 0;

        // Taille en bit prise en mémoire du type
        virtual int getTailleType() = 0;

        virtual void setType(const char *) = 0;       
    
};
#endif
