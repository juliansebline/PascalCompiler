#include "MathExpressionSlash.hpp"

using namespace std;

MathExpressionSlash::MathExpressionSlash()
{
}

MathExpressionSlash::MathExpressionSlash(Expression * arg1, Expression * arg2)
{
    if(!MathExpression::estCompatible(arg1, arg2, "slash")) exit(1); 
    
	if(arg1->estCalculable() && arg2->estCalculable()){
	
		float op1 = MathExpression::conversionUnion(arg1, arg1->getValeur());
		float op2 = MathExpression::conversionUnion(arg2, arg2->getValeur());
         _valeur.i = (int)op1 / (int)op2;
		 this->_estCalculable = true;
	} 
    
    _operande1 = arg1;
    _operande2 = arg2;  

     _typeResultat = MathExpression::deciderTypeResultat(arg1, arg2);
}

MathExpressionSlash::~MathExpressionSlash()
{

}

void MathExpressionSlash::afficher()
{
    cout << "( ";
    _operande1->afficher();
    cout << " / ";
    _operande2->afficher();
    cout << " ) ";
}

Expression * MathExpressionSlash::getOperande1()
{
    return _operande1;
}

Expression * MathExpressionSlash::getOperande2()
{
    return _operande2;
}

const char * MathExpressionSlash::getType()
{
    return _typeResultat;
}

bool MathExpressionSlash::estCalculable()
{
	return _estCalculable;
}

Valeur MathExpressionSlash::getValeur()
{
	return _valeur;
}
