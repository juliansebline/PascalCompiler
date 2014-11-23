#ifndef MATH_EXPRESSION_MULT_HPP
#define MATH_EXPRESSION_MULT_HPP

#include "MathExpression.hpp"

class MathExpressionMult : public MathExpression
{
    private:
        Expression * _operande1;
        Expression * _operande2;
        const char * _typeResultat;
            
    public:
        virtual const char * getType();
        virtual void afficher();
        
        MathExpressionMult();
        MathExpressionMult(Expression *, Expression *);
        virtual ~MathExpressionMult();
        
        Expression * getOperande1();
        Expression * getOperande2(); 

        bool _estCalculable = false;
        Valeur _valeur;

        virtual bool estCalculable();
        virtual Valeur getValeur();
};

#endif
