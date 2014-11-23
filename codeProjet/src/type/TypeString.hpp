#ifndef TYPE_STRING_HPP
#define TYPE_STRING_HPP

#include "Type.hpp"

class TypeString : public Type
{
    private:
        int _taille;
        char * _valeur;
        const char * _type;

    public:
        
       TypeString();
       virtual ~TypeString();
       virtual const char * getType();
       virtual void setType(const char *);       
       virtual int getTailleType();
       
       void setValeur(char *);
       char * getValeur();
};

#endif
