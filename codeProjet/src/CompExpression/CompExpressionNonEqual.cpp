#include "CompExpressionNonEqual.hpp"

CompExpressionNonEqual::CompExpressionNonEqual()
{
}

CompExpressionNonEqual::CompExpressionNonEqual(Expression * arg1, Expression * arg2)
{
    if(!CompExpression::estCompatible(arg1, arg2, "la non égalité")) exit(1);

      if( arg1->getValeur().f != arg2->getValeur().f )
      {
          _valeur.b = true;
      }
      else _valeur.b = false;
    
    _operande1 = arg1;
    _operande2 = arg2;
}

CompExpressionNonEqual::~CompExpressionNonEqual()
{
}

void CompExpressionNonEqual::afficher()
{
    _operande1->afficher();
    std::cout << " != " << std::flush;
    _operande2->afficher();
}

Expression * CompExpressionNonEqual::getOperande1()
{
    return _operande1;
}

Expression * CompExpressionNonEqual::getOperande2()
{
    return _operande2;
}

const char * CompExpressionNonEqual::getType()
{
    return "boolean";
}

Valeur CompExpressionNonEqual::getValeur()
{
    return _valeur;
}

bool CompExpressionNonEqual::estCalculable()
{
}

