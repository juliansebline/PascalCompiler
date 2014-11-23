#ifndef BOOL_EXPRESSION_XOR_HPP
#define BOOL_EXPRESSION_XOR_HPP

#include "BoolExpression.hpp"

class BoolExpressionXOR : public BoolExpression
{
    private:
        Valeur _valeur;
        bool _estCalculable;

    public:
        BoolExpressionXOR();
        BoolExpressionXOR(Expression *, Expression *);
        virtual ~BoolExpressionXOR();
        virtual const char * getType();
        virtual Valeur getValeur();
        virtual bool estCalculable();
        virtual void afficher();
};
#endif
