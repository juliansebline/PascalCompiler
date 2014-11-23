#ifndef BOOL_EXPRESSION_HPP
#define BOOL_EXPRESSION_HPP

#include <typeinfo>
#include <cstring>
#include "../Expressions/Expression.hpp"


class BoolExpression : public Expression
{
    public:
        bool estCompatible(Expression *, Expression *, std::string);
};
#endif
