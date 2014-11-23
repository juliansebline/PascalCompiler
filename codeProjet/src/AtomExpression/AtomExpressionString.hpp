#ifndef ATOMEXPRESSION_STRING_HPP
#define ATOMEXPRESSION_STRING_HPP

#include "AtomExpression.hpp"

class AtomExpressionString : public AtomExpression
{
	private:
		const char * _type = "string";
	public:
		AtomExpressionString();
		AtomExpressionString(char *);
		virtual ~AtomExpressionString();
		virtual void afficher();
		virtual const char * getType();
		virtual bool estCalculable();
		virtual Valeur getValeur();

		bool _estCalculable = true;
		Valeur _valeur;
		
};
#endif
