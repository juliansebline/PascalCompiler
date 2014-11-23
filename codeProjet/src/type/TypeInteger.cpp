#include "TypeInteger.hpp"

TypeInteger::TypeInteger()
{
}

TypeInteger::~TypeInteger()
{
}

const char * TypeInteger::getType()
{
    return _type;
}

int TypeInteger::getTailleType()
{
    return _taille;
}

void TypeInteger::setType(const char * type)
{
   _type = type;
}
