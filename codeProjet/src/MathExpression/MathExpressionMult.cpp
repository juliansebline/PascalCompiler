#include "MathExpressionMult.hpp"

using namespace std;

MathExpressionMult::MathExpressionMult()
{
}

MathExpressionMult::MathExpressionMult(Expression * arg1, Expression * arg2)
{
     if(!MathExpression::estCompatible(arg1, arg2, "multiplication")) exit(1); 

	if(arg1->estCalculable() && arg2->estCalculable()){
		float op1 = MathExpression::conversionUnion(arg1, arg1->getValeur());
		float op2 = MathExpression::conversionUnion(arg2, arg2->getValeur());
		 _valeur.f = op1 * op2;
		 this->_estCalculable = true;
	}  
    
    _operande1 = arg1;
    _operande2 = arg2; 

    _typeResultat = MathExpression::deciderTypeResultat(arg1, arg2);
}

MathExpressionMult::~MathExpressionMult()
{

}

void MathExpressionMult::afficher()
{
    std::cout << "( " << std::flush;
    _operande1->afficher();
    std::cout << " * " << std::flush;
    _operande2->afficher();
    std::cout << " ) " << std::flush;
}

Expression * MathExpressionMult::getOperande1()
{
    return _operande1;
}

Expression * MathExpressionMult::getOperande2()
{
    return _operande2;
}

const char * MathExpressionMult::getType()
{
    return _typeResultat;
}

Valeur MathExpressionMult::getValeur()
{
	return _valeur;
}

bool MathExpressionMult::estCalculable()
{
	return _estCalculable;
}
