#ifndef BOOL_EXPRESSION_AND_HPP
#define BOOL_EXPRESSION_AND_HPP

#include "BoolExpression.hpp"

class BoolExpressionAND : public BoolExpression
{
    private:
        Valeur _valeur;
        bool _estCalculable;

    public:
        BoolExpressionAND();
        BoolExpressionAND(Expression *, Expression *);
        virtual ~BoolExpressionAND();
        virtual const char * getType();
        virtual Valeur getValeur();
        virtual void afficher();
        virtual bool estCalculable();
};
#endif
