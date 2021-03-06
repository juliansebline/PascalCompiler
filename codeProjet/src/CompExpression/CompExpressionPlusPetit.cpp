#include "CompExpressionPlusPetit.hpp"

CompExpressionPlusPetit::CompExpressionPlusPetit()
{
}

CompExpressionPlusPetit::CompExpressionPlusPetit(Expression * arg1, Expression * arg2)
{
      if(!CompExpression::estCompatible(arg1, arg2, "du plus petit")) exit(1);

      if( arg1->getValeur().f < arg2->getValeur().f )
      {
          _valeur.b = true;
      }
      else _valeur.b = false;
    
    _operande1 = arg1;
    _operande2 = arg2;
}

CompExpressionPlusPetit::~CompExpressionPlusPetit()
{
}

void CompExpressionPlusPetit::afficher()
{
    _operande1->afficher();
    std::cout << " = " << std::flush;
    _operande2->afficher();
}

Expression * CompExpressionPlusPetit::getOperande1()
{
    return _operande1;
}

Expression * CompExpressionPlusPetit::getOperande2()
{
    return _operande2;
}

const char * CompExpressionPlusPetit::getType()
{
    return "boolean";
}

Valeur CompExpressionPlusPetit::getValeur()
{
    return _valeur;
}

bool CompExpressionPlusPetit::estCalculable()
{
}

