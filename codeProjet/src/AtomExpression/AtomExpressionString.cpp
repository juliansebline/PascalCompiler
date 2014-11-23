#include "AtomExpressionString.hpp"

AtomExpressionString::AtomExpressionString()
{
}

AtomExpressionString::AtomExpressionString(char * variable)
{
	_valeur.s = variable;
}

AtomExpressionString::~AtomExpressionString()
{
}

void AtomExpressionString::afficher()
{
	std::cout << _valeur.s << std::flush;
}
 
const char * AtomExpressionString::getType()
{
	return _type;
}

bool AtomExpressionString::estCalculable()
{
	return _estCalculable;
}

Valeur AtomExpressionString::getValeur()
{
	return _valeur;
}
