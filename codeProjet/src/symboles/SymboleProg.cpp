#include "SymboleProg.hpp"

using namespace std;

SymboleProg::SymboleProg()
{
    _principale = new TableSymboles();
}

SymboleProg::SymboleProg(TableSymboles * tablePrincipale)
{
    _principale = tablePrincipale;
}

SymboleProg::~SymboleProg()
{
}

void SymboleProg::ajouterALaTable(unsigned int indice, Symbole* symbole)
{
    _principale->ajouter(indice, symbole);
}

const char * SymboleProg::getNom()
{
    return _nom;
}

const char * SymboleProg::getType()
{
    return _type;
}

void SymboleProg::setNom(const char * nom)
{
    _nom = nom;
	_principale->setNom(_nom);
}

TableSymboles * SymboleProg::getTableSymboles()
{
    return _principale;
}

void SymboleProg::afficher()
{
    _principale->afficher();
}
