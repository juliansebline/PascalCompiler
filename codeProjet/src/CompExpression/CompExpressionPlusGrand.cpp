#include "CompExpressionPlusGrand.hpp"

CompExpressionPlusGrand::CompExpressionPlusGrand()
{
}

CompExpressionPlusGrand::CompExpressionPlusGrand(Expression * arg1, Expression * arg2)
{
  if(!CompExpression::estCompatible(arg1, arg2, "du plus grand")) exit(1);

  if( arg1->getValeur().f > arg2->getValeur().f )
  {
      _valeur.b = true;
  }
  else _valeur.b = false;
    
    _operande1 = arg1;
    _operande2 = arg2;
}

CompExpressionPlusGrand::~CompExpressionPlusGrand()
{
}

void CompExpressionPlusGrand::afficher()
{
    _operande1->afficher();
    std::cout << " > " << std::flush;
    _operande2->afficher();
}

Expression * CompExpressionPlusGrand::getOperande1()
{
    return _operande1;
}

Expression * CompExpressionPlusGrand::getOperande2()
{
    return _operande2;
}

const char * CompExpressionPlusGrand::getType()
{
    return "boolean";
}

Valeur CompExpressionPlusGrand::getValeur()
{
    return _valeur;
}

bool CompExpressionPlusGrand::estCalculable()
{
}

