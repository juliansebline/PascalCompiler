#include "SymboleTemp.hpp"

SymboleTemp::SymboleTemp()
{
}

SymboleTemp::~SymboleTemp()
{
}

const char * SymboleTemp::getNom()
{
    return _nomTemp;
}

void SymboleTemp::setNom(const char * nom)
{
    _nomTemp =  nom;
}