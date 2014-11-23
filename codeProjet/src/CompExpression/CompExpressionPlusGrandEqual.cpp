#include "CompExpressionPlusGrandEqual.hpp"

CompExpressionPlusGrandEqual::CompExpressionPlusGrandEqual()
{
}

CompExpressionPlusGrandEqual::CompExpressionPlusGrandEqual(Expression * arg1, Expression * arg2)
{
  if(!CompExpression::estCompatible(arg1, arg2, "l'égalité")) exit(1);

  if( arg1->getValeur().f >= arg2->getValeur().f )
  {
      _valeur.b = true;
  }
  else _valeur.b = false;
    
    _operande1 = arg1;
    _operande2 = arg2;
}

CompExpressionPlusGrandEqual::~CompExpressionPlusGrandEqual()
{
}

void CompExpressionPlusGrandEqual::afficher()
{
    _operande1->afficher();
    std::cout << " = " << std::flush;
    _operande2->afficher();
}

Expression * CompExpressionPlusGrandEqual::getOperande1()
{
    return _operande1;
}

Expression * CompExpressionPlusGrandEqual::getOperande2()
{
    return _operande2;
}

const char * CompExpressionPlusGrandEqual::getType()
{
    return "b";
}

Valeur CompExpressionPlusGrandEqual::getValeur()
{
    return _valeur;
}

bool CompExpressionPlusGrandEqual::estCalculable()
{
}

