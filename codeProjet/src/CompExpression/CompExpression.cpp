#include "CompExpression.hpp"

bool CompExpression::estCompatible(Expression * arg1, Expression * arg2, std::string type)
{
    const char * typeArg1 = arg1->getType();
    const char * typeArg2 = arg2->getType();

    if(strcmp(typeArg1, typeArg2) != 0)
    {
       if((strcmp(typeArg1, "integer") != 0 && strcmp(typeArg1, "real") != 0 && strcmp(typeArg1, "char") != 0) &&
          (strcmp(typeArg2, "integer") != 0 && strcmp(typeArg2, "real") != 0 && strcmp(typeArg1, "char") != 0))
           {
             std::cout << "Les opérandes de " << type <<" ne sont pas compatibles\n" << std::flush;
             return false;
           }
    }

    return true;
}
