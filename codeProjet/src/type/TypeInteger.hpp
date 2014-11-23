#ifndef TYPE_INTEGER_HPP
#define TYPE_INTEGER_HPP

#include "Type.hpp"


class TypeInteger : public Type
{
    private:
        int _taille;
        const char * _type = "integer";

    public:
        
       TypeInteger();
       virtual ~TypeInteger();
       virtual const char * getType();
       virtual void setType(const char *);       
       virtual int getTailleType();
};

#endif
