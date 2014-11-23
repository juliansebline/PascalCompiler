#ifndef ATOMEXPRESSION_INTEGER_HPP
#define ATOMEXPRESSION_INTEGER_HPP

#include "AtomExpression.hpp"

class AtomExpressionInteger : public AtomExpression
{
	private:
		const char * _type = "integer";
	public:
		AtomExpressionInteger();
		AtomExpressionInteger(int);		
		virtual ~AtomExpressionInteger();

		virtual void afficher();
		virtual const char * getType();
		virtual bool estCalculable();	        
	    	virtual Valeur getValeur();

		bool _estCalculable = true;
		Valeur _valeur;	
};
#endif
