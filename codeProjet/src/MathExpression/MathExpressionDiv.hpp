#ifndef MATH_EXPRESSION_DIV_HPP
#define MATH_EXPRESSION_DIV_HPP

#include "MathExpression.hpp"

class MathExpressionDiv : public MathExpression
{
    private:
        Expression * _operande1;
        Expression * _operande2;
        const char * _typeResultat;
            
    public:
        MathExpressionDiv();
        MathExpressionDiv(Expression *, Expression *);
        virtual ~MathExpressionDiv();

        virtual const char * getType();
        virtual void afficher();
        virtual bool estCalculable();
        virtual Valeur getValeur();
        
        Expression * getOperande1();
        Expression * getOperande2();

        bool _estCalculable = false;
        Valeur _valeur;
};

#endif
