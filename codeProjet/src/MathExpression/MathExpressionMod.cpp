#include "MathExpressionMod.hpp"

MathExpressionMod::MathExpressionMod()
{
}

MathExpressionMod::MathExpressionMod(Expression * arg1, Expression * arg2)
{
     if(!MathExpression::estCompatible(arg1, arg2, "modulo")) exit(1); 

	if(arg1->estCalculable() && arg2->estCalculable()){
		float op1 = MathExpression::conversionUnion(arg1, arg1->getValeur());
		float op2 = MathExpression::conversionUnion(arg2, arg2->getValeur());
		 _valeur.f = (int)op1 % (int)op2;
		 this->_estCalculable = true;
	}

    _operande1 = arg1;
    _operande2 = arg2;  

    _typeResultat = MathExpression::deciderTypeResultat(arg1, arg2);
}

MathExpressionMod::~MathExpressionMod()
{

}

void MathExpressionMod::afficher()
{
    std::cout << "( " << std::flush;
    _operande1->afficher();
    std::cout << " % " << std::flush;
    _operande2->afficher();
    std::cout << " ) " << std::flush;
}

Expression * MathExpressionMod::getOperande1()
{
    return _operande1;
}

Expression * MathExpressionMod::getOperande2()
{
    return _operande2;
}

const char * MathExpressionMod::getType()
{
    return _typeResultat;
}

bool MathExpressionMod::estCalculable()
{
	return _estCalculable;
}

Valeur MathExpressionMod::getValeur()
{
	return _valeur;
}
