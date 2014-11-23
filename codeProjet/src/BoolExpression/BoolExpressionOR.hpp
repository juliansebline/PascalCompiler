#ifndef BOOL_EXPRESSION_OR_HPP
#define BOOL_EXPRESSION_OR_HPP

#include "BoolExpression.hpp"

class BoolExpressionOR : public BoolExpression
{
    private:
        Valeur _valeur;
        bool _estCalculable;

    public:
        BoolExpressionOR();
        BoolExpressionOR(Expression *, Expression *);
        virtual ~BoolExpressionOR();
        virtual const char * getType();
        virtual Valeur getValeur();
        virtual bool estCalculable();
        virtual void afficher();
        
};
#endif
