#ifndef COMP_EXPRESSION_PLUS_GRAND_EQUAL_HPP
#define COMP_EXPRESSION_PLUS_GRAND_EQUAL_HPP

#include "CompExpression.hpp"

class CompExpressionPlusGrandEqual : public CompExpression
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

        CompExpressionPlusGrandEqual();
        CompExpressionPlusGrandEqual(Expression *, Expression *);
        virtual ~CompExpressionPlusGrandEqual();
        
        Expression * getOperande1();
        Expression * getOperande2();       
};

#endif
