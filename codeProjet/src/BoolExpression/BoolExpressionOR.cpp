#include "BoolExpressionOR.hpp"

BoolExpressionOR::BoolExpressionOR()
{
}

BoolExpressionOR::BoolExpressionOR(Expression * arg1, Expression * arg2)
{
     if(!BoolExpression::estCompatible(arg1, arg2 ,"OR")) exit(1);

     if(arg1->estCalculable() && arg2->estCalculable()) this->_estCalculable = true;
     else
     {
         std::cout << "Le calcul du XOR n'est pas possible car l'une des deux opérandes n'est pas calculable" << std::endl;
         exit(1);
     }

     if(arg1->getValeur().b || arg2->getValeur().b) _valeur.b = true;
     else _valeur.b = false;
}

BoolExpressionOR::~BoolExpressionOR()
{
}

const char * BoolExpressionOR::getType()
{
    return "boolean";
}

Valeur BoolExpressionOR::getValeur()
{
    return _valeur;
}

bool BoolExpressionOR::estCalculable()
{
    return _estCalculable;
}

void BoolExpressionOR::afficher()
{

}
