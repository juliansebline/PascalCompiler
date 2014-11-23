#include "SymboleConst.hpp"

SymboleConst::SymboleConst()
{
}

SymboleConst::~SymboleConst()
{
}

SymboleConst::SymboleConst(const char * nom, Valeur valeur, const char * typeValeur)
{
    setNom(nom);
    setValeur(valeur);
    setTypeValeur(typeValeur);
}

const char * SymboleConst::getNom()
{
    return _nomConst;
}

void SymboleConst::setNom(const char * nom)
{
    _nomConst = nom;
}

void SymboleConst::setTypeValeur(const char * type)
{
    if(strcmp(type, "boolean")){ _typeValeur = type; _objetTypeValeur = new TypeBoolean(); }
    else if(strcmp(type, "integer")) { _typeValeur = type; _objetTypeValeur = new TypeInteger(); }
    else if(strcmp(type, "char")) { _typeValeur = type; _objetTypeValeur = new TypeChar(); }
    else if(strcmp(type, "string")){ _typeValeur = type; _objetTypeValeur = new TypeString(); }
    else { _typeValeur = type; _objetTypeValeur = new TypeReal();}
}

void SymboleConst::setValeur(Valeur valeur)
{
	_valeur = valeur;
}

const char * SymboleConst::getType()
{
	return _type;
}

Valeur SymboleConst::getValeur()
{
	return _valeur;
}

const char * SymboleConst::getTypeValeur()
{
	return _typeValeur;
}

void SymboleConst::afficher()
{

}
