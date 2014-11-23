#include "MathExpressionMoins.hpp"

MathExpressionMoins::MathExpressionMoins()
{
}

MathExpressionMoins::MathExpressionMoins(Expression * arg1, Expression * arg2)
{
     if(!MathExpression::estCompatible(arg1, arg2, "soustraction")) exit(1); 

	if(arg1->estCalculable() && arg2->estCalculable()){
		float op1 = MathExpression::conversionUnion(arg1, arg1->getValeur());
		float op2 = MathExpression::conversionUnion(arg2, arg2->getValeur());
		 _valeur.f = op1 - op2;
		 this->_estCalculable = true;
	}

    _operande1 = arg1;
    _operande2 = arg2; 

    _typeResultat = MathExpression::deciderTypeResultat(arg1, arg2);
}

MathExpressionMoins::~MathExpressionMoins()
{

}

void MathExpressionMoins::afficher()
{
    _operande1->afficher();
   std:: cout << " - " << std::flush;
    _operande2->afficher();
}

Expression * MathExpressionMoins::getOperande1()
{
    return _operande1;
}

Expression * MathExpressionMoins::getOperande2()
{
    return _operande2;
}

const char * MathExpressionMoins::getType()
{
    return _typeResultat;
}

Valeur MathExpressionMoins::getValeur()
{
	return _valeur;
}

bool MathExpressionMoins::estCalculable()
{
	return _estCalculable;
}
