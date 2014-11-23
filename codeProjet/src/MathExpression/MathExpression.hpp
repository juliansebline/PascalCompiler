#ifndef MATH_EXPRESSION_HPP
#define MATH_EXPRESSION_HPP

#include "../Expressions/Expression.hpp"
#include "../AtomExpression/AtomExpressionChar.hpp"
#include "../AtomExpression/AtomExpressionInteger.hpp"
#include "../AtomExpression/AtomExpressionReal.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

class MathExpression : public Expression
{
    protected:

        float conversionUnion(Expression *, Valeur);
        bool estCompatible(Expression *, Expression *, std::string);
        const char * deciderTypeResultat(Expression *, Expression *);
};

#endif
