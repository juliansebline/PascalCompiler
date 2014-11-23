#ifndef ATOMEXPRESSION_HPP
#define ATOMEXPRESSION_HPP

#include "../Expressions/Expression.hpp"

#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>

class AtomExpression : public Expression
{
    public:
        virtual void afficher() = 0;
};

#endif
