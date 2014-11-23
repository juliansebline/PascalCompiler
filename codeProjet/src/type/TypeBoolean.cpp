#include "TypeBoolean.hpp"

TypeBoolean::TypeBoolean()
{
	_taille = sizeof(bool);
}

TypeBoolean::~TypeBoolean()
{
}

const char * TypeBoolean::getType()
{
    return _type;
}

bool TypeBoolean::getValeur()
{
    return _valeur;
}


int TypeBoolean::getTailleType()
{
    return _taille;
}

void TypeBoolean::setType(const char * type)
{
    _type = type;
}

void TypeBoolean::setValeur(bool valeur)
{
    _valeur = valeur;
}

