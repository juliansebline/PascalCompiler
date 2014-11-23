#include "TypeString.hpp"

TypeString::TypeString()
{
}

TypeString::~TypeString()
{
}

const char * TypeString::getType()
{
    return _type;
}

char * TypeString::getValeur()
{
    return _valeur;
}


int TypeString::getTailleType()
{
    return _taille;
}

void TypeString::setType(const char * type)
{
    _type = type;
}

void TypeString::setValeur(char * valeur)
{
    _valeur = valeur;
}

