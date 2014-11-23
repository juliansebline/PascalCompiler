#ifndef COMP_EXPRESSION_HPP
#define COMP_EXPRESSION_HPP

#include "../Expressions/Expression.hpp"
#include "../AtomExpression/AtomExpression.hpp"
#include "../AtomExpression/AtomExpressionInteger.hpp"
#include "../AtomExpression/AtomExpressionString.hpp"
#include "../AtomExpression/AtomExpressionBoolean.hpp"
#include "../AtomExpression/AtomExpressionChar.hpp"
#include "../AtomExpression/AtomExpressionReal.hpp"

class CompExpression : public Expression
{
    protected:
        bool estCompatible(Expression * , Expression *, std::string);
};

#endif
