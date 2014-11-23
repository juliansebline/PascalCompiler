#include "CompExpressionPlusPetitEqual.hpp"

CompExpressionPlusPetitEqual::CompExpressionPlusPetitEqual()
{
}

CompExpressionPlusPetitEqual::CompExpressionPlusPetitEqual(Expression * arg1, Expression * arg2)
{
  if(!CompExpression::estCompatible(arg1, arg2, "plus petit égal")) exit(1);

  if( arg1->getValeur().f <= arg2->getValeur().f )
  {
      _valeur.b = true;
  }
  else _valeur.b = false;
    
    _operande1 = arg1;
    _operande2 = arg2;
}

CompExpressionPlusPetitEqual::~CompExpressionPlusPetitEqual()
{
}

void CompExpressionPlusPetitEqual::afficher()
{
    _operande1->afficher();
    std::cout << " = " << std::flush;
    _operande2->afficher();
}

Expression * CompExpressionPlusPetitEqual::getOperande1()
{
    return _operande1;
}

Expression * CompExpressionPlusPetitEqual::getOperande2()
{
    return _operande2;
}

const char * CompExpressionPlusPetitEqual::getType()
{
    return "boolean";
}

Valeur CompExpressionPlusPetitEqual::getValeur()
{
    return _valeur;
}

bool CompExpressionPlusPetitEqual::estCalculable()
{
}

