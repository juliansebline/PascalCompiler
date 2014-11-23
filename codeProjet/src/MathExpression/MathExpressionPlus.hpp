#ifndef MATH_EXPRESSION_PLUS_HPP
#define MATH_EXPRESSION_PLUS_HPP

#include "MathExpression.hpp"

class MathExpressionPlus : public MathExpression
{
    private:
        Expression * _operande1;
        Expression * _operande2;
        const char * _typeResultat;
            
    public:
        virtual const char * getType();
        virtual void afficher();
        
        MathExpressionPlus();
        MathExpressionPlus(Expression *, Expression *);
        virtual ~MathExpressionPlus();

        virtual bool estCalculable();
        virtual Valeur getValeur();

        Expression * getOperande1();
        Expression * getOperande2();

        bool _estCalculable = false;
        Valeur _valeur;

	
};
#endif
