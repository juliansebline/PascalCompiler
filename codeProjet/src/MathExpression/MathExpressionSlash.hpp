#ifndef MATH_EXPRESSION_SLASH_HPP
#define MATH_EXPRESSION_SLASH_HPP

#include "MathExpression.hpp"

class MathExpressionSlash : public MathExpression
{
    private:
        Expression * _operande1;
        Expression * _operande2;
        const char * _typeResultat;
            
    public:
        virtual const char * getType();
        virtual void afficher();
        
        MathExpressionSlash();
        MathExpressionSlash(Expression *, Expression *);
        virtual ~MathExpressionSlash();
        
        Expression * getOperande1();
        Expression * getOperande2();   

        bool _estCalculable = false;
        Valeur _valeur;

        virtual bool estCalculable();
        virtual Valeur getValeur();
};

#endif
