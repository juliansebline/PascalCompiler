#include "CompExpressionEqual.hpp"

CompExpressionEqual::CompExpressionEqual()
{
}

CompExpressionEqual::CompExpressionEqual(Expression * arg1, Expression * arg2)
{
    if(!CompExpression::estCompatible(arg1, arg2, "l'égalité")) exit(1);

    if( arg1->getValeur().f == arg2->getValeur().f )
    {
        _valeur.b = true;
    }
    else _valeur.b = false;
    
    _operande1 = arg1;
    _operande2 = arg2;
}

CompExpressionEqual::~CompExpressionEqual()
{
}

void CompExpressionEqual::afficher()
{
    _operande1->afficher();
    std::cout << " = " << std::flush;
    _operande2->afficher();
}

Expression * CompExpressionEqual::getOperande1()
{
    return _operande1;
}

Expression * CompExpressionEqual::getOperande2()
{
    return _operande2;
}

const char * CompExpressionEqual::getType()
{
    return "boolean";
}

Valeur CompExpressionEqual::getValeur()
{
    return _valeur;
}

bool CompExpressionEqual::estCalculable()
{
}

