#include "AtomExpressionBoolean.hpp"

AtomExpressionBoolean::AtomExpressionBoolean()
{
}

AtomExpressionBoolean::AtomExpressionBoolean(bool variable)
{
	_valeur.b = variable;
}

AtomExpressionBoolean::~AtomExpressionBoolean()
{
}

void AtomExpressionBoolean::afficher()
{
	std::cout << _valeur.b << std::endl;
}

const char * AtomExpressionBoolean::getType()
{
	return _type;
}

bool AtomExpressionBoolean::estCalculable()
{
	return _estCalculable;
}

Valeur AtomExpressionBoolean::getValeur()
{
	return _valeur;
}
