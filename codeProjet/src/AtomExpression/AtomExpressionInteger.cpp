#include "AtomExpressionInteger.hpp"

AtomExpressionInteger::AtomExpressionInteger()
{
}

AtomExpressionInteger::AtomExpressionInteger(int variable)
{
	_valeur.i = variable;
}

AtomExpressionInteger::~AtomExpressionInteger()
{
}

void AtomExpressionInteger::afficher()
{
	std::cout << _valeur.i << std::flush;
}
 
const char * AtomExpressionInteger::getType()
{
	return _type;
}

bool AtomExpressionInteger::estCalculable()
{
	return _estCalculable;
}

Valeur AtomExpressionInteger::getValeur()
{
	return _valeur;
}
