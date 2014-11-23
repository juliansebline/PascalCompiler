#ifndef COMP_EXPRESSION_PLUS_PETIT_HPP
#define COMP_EXPRESSION_PLUS_PETIT_HPP

#include "CompExpression.hpp"

class CompExpressionPlusPetit : public CompExpression
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

        CompExpressionPlusPetit();
        CompExpressionPlusPetit(Expression *, Expression *);
        virtual ~CompExpressionPlusPetit();
        
        Expression * getOperande1();
        Expression * getOperande2();       
};

#endif
