#include "SymboleProc.hpp"

SymboleProc::SymboleProc()
{
    _table = new TableSymboles();
}

SymboleProc::~SymboleProc()
{
}

const char * SymboleProc::getNom()
{
    return _nomProc;
}

void SymboleProc::setNom(const char * nom)
{
    _nomProc =  nom;
}

void SymboleProc::setNbArguments(int nbArguments)
{
    _nbArguments = nbArguments;
}

int SymboleProc::getNbArguments()
{
    return _nbArguments;
}

const char * SymboleProc::getType()
{
	return _type;
}

void SymboleProc::setTableSymboles(TableSymboles * table)
{
	_table = table;
}

TableSymboles * SymboleProc::getTableSymboles()
{
    return _table;
}

void SymboleProc::ajouterALaTable(unsigned int indice, Symbole* symbole)
{
    _table->ajouter(indice, symbole);
}

void SymboleProc::afficher()
{
    _table->afficher();
}
