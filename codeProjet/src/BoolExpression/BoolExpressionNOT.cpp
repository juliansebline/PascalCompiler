#include "BoolExpressionNOT.hpp"

BoolExpressionNOT::BoolExpressionNOT()
{
}

BoolExpressionNOT::BoolExpressionNOT(Expression * arg1)
{
     if(strcmp(arg1->getType(), "boolean") != 0)
     {
         std::cout << "L'opérande du NOT n'est sont pas un booléen." << std::endl;
         exit(1);
     }

     if(arg1->getValeur().b) _valeur.b = false;
     else _valeur.b = true;
}

BoolExpressionNOT::~BoolExpressionNOT()
{
}

const char * BoolExpressionNOT::getType()
{
    return "boolean";
}

Valeur BoolExpressionNOT::getValeur()
{
    return _valeur;
}

bool BoolExpressionNOT::estCalculable()
{
    return _estCalculable;
}

void BoolExpressionNOT::afficher()
{

}
