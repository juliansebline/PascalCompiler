#include "SymboleArg.hpp"

using namespace std;

SymboleArg::SymboleArg()
{
}

SymboleArg::~SymboleArg()
{
}

const char * SymboleArg::getNom()
{
    return _nomArgument;
}

void SymboleArg::setNom(const char * nom)
{
    _nomArgument =  nom;
}

void SymboleArg::setTypeArgument(const char * typeArgument)
{
	_typeArgument = typeArgument;
}

const char * SymboleArg::getTypeArgument()
{
    return _typeArgument;
}

const char * SymboleArg::getType()
{
	return _type;
}

void SymboleArg::afficher()
{

}
