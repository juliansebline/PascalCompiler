#include "SymboleChamps.hpp"

SymboleChamps::SymboleChamps()
{
}

SymboleChamps::~SymboleChamps()
{
}

const char * SymboleChamps::getNom()
{
    return _nomChamps;
}

void SymboleChamps::setNom(const char * nom)
{
    _nomChamps =  nom;
}
