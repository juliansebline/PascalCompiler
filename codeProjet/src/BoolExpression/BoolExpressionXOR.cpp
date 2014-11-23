#include "BoolExpressionXOR.hpp"

BoolExpressionXOR::BoolExpressionXOR()
{
}

BoolExpressionXOR::BoolExpressionXOR(Expression * arg1, Expression * arg2)
{
     if(!BoolExpression::estCompatible(arg1, arg2 ,"XOR")) exit(1);

     if(arg1->estCalculable() && arg2->estCalculable()) this->_estCalculable = true;
     else
     {
         std::cout << "Le calcul du XOR n'est pas possible car l'une des deux opérandes n'est pas calculable" << std::endl;
         exit(1);
     }

     if(arg1->getValeur().b == arg2->getValeur().b) _valeur.b = false;
     else _valeur.b = true;
}

BoolExpressionXOR::~BoolExpressionXOR()
{
}

const char * BoolExpressionXOR::getType()
{
    return "b";
}

Valeur BoolExpressionXOR::getValeur()
{
    return _valeur;
}

bool BoolExpressionXOR::estCalculable()
{
    return _estCalculable;
}

void BoolExpressionXOR::afficher()
{

}
