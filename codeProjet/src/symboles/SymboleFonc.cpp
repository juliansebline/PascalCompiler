#include "SymboleFonc.hpp"

SymboleFonc::SymboleFonc()
{
    _table = new TableSymboles();
}

SymboleFonc::~SymboleFonc()
{
}

const char * SymboleFonc::getNom()
{
    return _nomFonc;
}

void SymboleFonc::setNom(const char * nom)
{
    _nomFonc = nom;
    _table->setNom(nom);
}

void SymboleFonc::setTableSymboles(TableSymboles * table)
{
	_table = table;
}

TableSymboles * SymboleFonc::getTableSymboles()
{
    return _table;
}

void SymboleFonc::setTypeRetour(const char * typeRetour)
{
    _typeRetour = typeRetour;
}

const char * SymboleFonc::getTypeRetour()
{
    return _typeRetour;
}

const char * SymboleFonc::getType()
{
    return _type;
}

void SymboleFonc::setNbArguments(int nbArguments)
{
    _nbArguments = nbArguments;
}

int SymboleFonc::getNbArguments()
{
    return _nbArguments;
}

void SymboleFonc::ajouterALaTable(unsigned int indice, Symbole* symbole)
{
    _table->ajouter(indice, symbole);
}

void SymboleFonc::afficher()
{
    _table->afficher();
}
