#include "SymboleEtiq.hpp"

SymboleEtiq::SymboleEtiq()
{
}

SymboleEtiq::~SymboleEtiq()
{
}

const char * SymboleEtiq::getNom()
{
    return _nomEtiq;
}

void SymboleEtiq::setNom(const char * nom)
{
    _nomEtiq =  nom;
}
