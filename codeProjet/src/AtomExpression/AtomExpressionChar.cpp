#include "AtomExpressionChar.hpp"

AtomExpressionChar::AtomExpressionChar()
{
}

AtomExpressionChar::AtomExpressionChar(char variable)
{
	_valeur.c = variable;
}

AtomExpressionChar::~AtomExpressionChar()
{
	
}

void AtomExpressionChar::afficher()
{
	std::cout << _valeur.c << std::endl;
}

const char * AtomExpressionChar::getType()
{
	return _type;
}

bool AtomExpressionChar::estCalculable()
{
	return _estCalculable;
}

Valeur AtomExpressionChar::getValeur()
{
	return _valeur;
}
