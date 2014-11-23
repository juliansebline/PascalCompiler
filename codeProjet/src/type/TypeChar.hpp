#ifndef TYPE_CHAR_HPP
#define TYPE_CHAR_HPP

#include "Type.hpp"

class TypeChar : public Type
{
    private:
        int _taille;
        char _valeur;
        const char * _type;

    public:
        
       TypeChar();
       virtual ~TypeChar();
       virtual const char * getType();
       virtual void setType(const char *);       
       virtual int getTailleType();
       
       void setValeur(char);
       char getValeur();
};

#endif
