#ifndef TYPE_BOOLEAN_HPP
#define TYPE_BOOLEAN_HPP

#include "Type.hpp"

class TypeBoolean : public Type
{
    private:
        int _taille;
        bool _valeur;
        const char * _type;

    public:
        
       TypeBoolean();
       virtual ~TypeBoolean();
       virtual const char * getType();
       virtual void setType(const char *);     
       virtual int getTailleType();
       
       void setValeur(bool);
       bool getValeur();
};

#endif
