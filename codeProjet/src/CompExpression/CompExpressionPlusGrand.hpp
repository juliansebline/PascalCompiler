#ifndef COMP_EXPRESSION_PLUS_GRAND_HPP
#define COMP_EXPRESSION_PLUS_GRAND_HPP

#include "CompExpression.hpp"

class CompExpressionPlusGrand : public CompExpression
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

        CompExpressionPlusGrand();
        CompExpressionPlusGrand(Expression *, Expression *);
        virtual ~CompExpressionPlusGrand();
        
        Expression * getOperande1();
        Expression * getOperande2();       
};

#endif
