#ifndef BOOL_EXPRESSION_NOT_HPP
#define BOOL_EXPRESSION_NOT_HPP

#include "BoolExpression.hpp"

class BoolExpressionNOT : public BoolExpression
{
    private:
        Valeur _valeur;
        bool _estCalculable;

    public:
        BoolExpressionNOT();
        BoolExpressionNOT(Expression *);
        virtual ~BoolExpressionNOT();
        virtual const char * getType();
        virtual Valeur getValeur();
        virtual bool estCalculable();
        virtual void afficher();
};
#endif
