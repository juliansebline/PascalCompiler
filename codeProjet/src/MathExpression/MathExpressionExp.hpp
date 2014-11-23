#ifndef MATH_EXPRESSION_EXP_HPP
#define MATH_EXPRESSION_EXP_HPP

#include "MathExpression.hpp"

class MathExpressionExp : public MathExpression
{
    private:
        Expression * _operande1;
        Expression * _operande2;
        const char * _typeResultat;
            
    public:
        virtual const char * getType();
        virtual void afficher();
        
        MathExpressionExp();
        MathExpressionExp(Expression *, Expression *);
        virtual ~MathExpressionExp();
        
        Expression * getOperande1();
        Expression * getOperande2();

        bool _estCalculable = false;
        Valeur _valeur;

        virtual	bool estCalculable();
        virtual Valeur getValeur();
};

#endif
