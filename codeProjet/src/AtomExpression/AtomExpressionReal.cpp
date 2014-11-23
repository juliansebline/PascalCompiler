#include "AtomExpressionReal.hpp"

AtomExpressionReal::AtomExpressionReal()
{
}

AtomExpressionReal::AtomExpressionReal(float variable)
{
	_valeur.f = variable;
}

AtomExpressionReal::~AtomExpressionReal()
{
}

void AtomExpressionReal::afficher()
{
	std::cout << _valeur.f << std::endl;
}

const char * AtomExpressionReal::getType()
{
	return _type;
}

bool AtomExpressionReal::estCalculable()
{
	return _estCalculable;
}

Valeur AtomExpressionReal::getValeur()
{
	return _valeur;
}
