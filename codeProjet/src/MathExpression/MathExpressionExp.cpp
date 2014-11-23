#include "MathExpressionExp.hpp"

using namespace std;

MathExpressionExp::MathExpressionExp()
{
}

MathExpressionExp::MathExpressionExp(Expression * arg1, Expression * arg2)
{
     if(!MathExpression::estCompatible(arg1, arg2, "puissance")) exit(1); 

	if(arg1->estCalculable() && arg2->estCalculable()){
		float op1 = MathExpression::conversionUnion(arg1, arg1->getValeur());
		float op2 = MathExpression::conversionUnion(arg2, arg2->getValeur());
		 _valeur.f = pow(op1, op2);
		 this->_estCalculable = true;
	}

    _operande1 = arg1;
    _operande2 = arg2;  

    _typeResultat = MathExpression::deciderTypeResultat(arg1, arg2);
}

MathExpressionExp::~MathExpressionExp()
{

}

void MathExpressionExp::afficher()
{
    std::cout << "( " << std::flush;
    _operande1->afficher();
    std::cout << " ^ " << std::flush;
    _operande2->afficher();
    std::cout << " ) " << std::flush;
}

Expression * MathExpressionExp::getOperande1()
{
    return _operande1;
}

Expression * MathExpressionExp::getOperande2()
{
    return _operande2;
}

const char * MathExpressionExp::getType()
{
    return _typeResultat;
}

bool MathExpressionExp::estCalculable()
{
	return _estCalculable;
}

Valeur MathExpressionExp::getValeur()
{
	return _valeur;
}
