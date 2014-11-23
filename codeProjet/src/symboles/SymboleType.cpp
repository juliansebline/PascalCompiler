#include "SymboleType.hpp"

SymboleType::SymboleType()
{
}

SymboleType::~SymboleType()
{
}

const char * SymboleType::getNom()
{
    return _nomType;
}

void SymboleType::setNom(const char * nom)
{
    _nomType =  nom;
}

