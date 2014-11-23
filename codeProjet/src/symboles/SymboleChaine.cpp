#include "SymboleChaine.hpp"

SymboleChaine::SymboleChaine()
{
}

SymboleChaine::~SymboleChaine()
{
}

const char * SymboleChaine::getNom()
{
	return _nomChaine;
}

void SymboleChaine::setNom(const char * nom)
{
    _nomChaine =  nom;
}
