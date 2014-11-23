#ifndef COMP_EXPRESSION_EQUAL_HPP
#define COMP_EXPRESSION_EQUAL_HPP

#include "CompExpression.hpp"

class CompExpressionEqual : public CompExpression
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

        CompExpressionEqual();
        CompExpressionEqual(Expression *, Expression *);
        virtual ~CompExpressionEqual();
        
        Expression * getOperande1();
        Expression * getOperande2();       
};

#endif
