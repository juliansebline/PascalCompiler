#include "TypeChar.hpp"

TypeChar::TypeChar()
{
}

TypeChar::~TypeChar()
{
}

const char * TypeChar::getType()
{
    return _type;
}

char TypeChar::getValeur()
{
    return _valeur;
}


int TypeChar::getTailleType()
{
    return _taille;
}

void TypeChar::setType(const char * type)
{
    _type = type;
}

void TypeChar::setValeur(char valeur)
{
    _valeur = valeur;
}

