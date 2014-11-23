#include "BoolExpression.hpp"

bool BoolExpression::estCompatible(Expression * arg1, Expression * arg2, std::string type)
{
    if(strcmp(arg1->getType(), "boolean") == 0 &&
       strcmp(arg2->getType(), "boolean") == 0)
    {        
        return true;
    } 
      
    std::cout << "Les opérandes du " << type << " ne sont pas compatibles." << std::endl;
    return false;
}
