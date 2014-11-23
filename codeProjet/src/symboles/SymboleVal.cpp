#include "SymboleVal.hpp"

SymboleVal::SymboleVal()
{
}

SymboleVal::~SymboleVal()
{
}

const char * SymboleVal::getNom()
{
    return _nomVal;
}

void SymboleVal::setNom(const char * nom)
{
    _nomVal =  nom;
}
