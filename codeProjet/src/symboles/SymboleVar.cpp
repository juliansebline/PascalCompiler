#include "SymboleVar.hpp"

SymboleVar::SymboleVar()
{
}

SymboleVar::~SymboleVar()
{
}

const char * SymboleVar::getNom()
{
    return _nomVar;
}

void SymboleVar::setNom(const char * nom)
{
    _nomVar =  nom;
}

void SymboleVar::setType(const char * typeVar)
{
	_typeVar = typeVar;
}

const char * SymboleVar::getType()
{
    return _typeVar;
}

void SymboleVar::afficher()
{

}
