#ifndef COMP_EXPRESSION_PLUS_PETIT_EQUAL_HPP
#define COMP_EXPRESSION_PLUS_PETIT_EQUAL_HPP

#include "CompExpression.hpp"

class CompExpressionPlusPetitEqual : public CompExpression
{
    private:
        Expression * _operande1;
        Expression * _operande2;
        Valeur _valeur;
            
    public:
        virtual const char * getType();
        virtual Valeur getValeur();
        virtual void afficher();
        virtual bool estCalculable();

        CompExpressionPlusPetitEqual();
        CompExpressionPlusPetitEqual(Expression *, Expression *);
        virtual ~CompExpressionPlusPetitEqual();
        
        Expression * getOperande1();
        Expression * getOperande2();       
};

#endif
