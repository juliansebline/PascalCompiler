#ifndef TYPE_REAL_HPP
#define TYPE_REAL_HPP

#include "Type.hpp"

class TypeReal : public Type
{
    private:
        int _taille;
        float _valeur;
        const char * _type;

    public:
        
       TypeReal();
       virtual ~TypeReal();
       virtual const char * getType();
       virtual void setType(const char *);       
       virtual int getTailleType();
       
       void setValeur(float);
       float getValeur();
};

#endif
