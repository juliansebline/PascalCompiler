#include "TypeReal.hpp"

TypeReal::TypeReal()
{
}

TypeReal::~TypeReal()
{
}

const char * TypeReal::getType()
{
    return _type;
}

float TypeReal::getValeur()
{
    return _valeur;
}


int TypeReal::getTailleType()
{
    return _taille;
}

void TypeReal::setType(const char * type)
{
    _type = type;
}

void TypeReal::setValeur(float valeur)
{
    _valeur = valeur;
}

