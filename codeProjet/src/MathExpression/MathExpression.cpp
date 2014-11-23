#include "MathExpression.hpp"

float MathExpression::conversionUnion(Expression * arg1, Valeur valeur)
{
	if(strcmp(arg1->getType(), "integer") == 0) return (float)valeur.i;
	else return valeur.f;
}

bool MathExpression::estCompatible(Expression * arg1, Expression * arg2, std::string operation)
{
	   if(strcmp(arg1->getType(), "boolean") == 0 ||
          strcmp(arg2->getType(), "boolean") == 0)
   		{
		    std::cerr << "Syntaxe error : " << operation << " of booleans\n" << std::flush;
			return false;
    	}
		else if(strcmp(arg1->getType(), "string") == 0 ||
			    strcmp(arg2->getType(), "string") == 0)
		{
            std::cerr << "Syntaxe error : " << operation <<" of strings\n : " << std::flush;
            return false;
		}
		return true;
}

const char * MathExpression::deciderTypeResultat(Expression * arg1, Expression * arg2)
{
    if(strcmp( arg1->getType(), "real") == 0 ||
       strcmp( arg2->getType(), "real") == 0 )
    {
        return "real";
    }
    else return "integer";
}
