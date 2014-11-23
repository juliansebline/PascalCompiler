#ifndef ATOMEXPRESSION_REAL_HPP
#define ATOMEXPRESSION_REAL_HPP

#include "AtomExpression.hpp"

class AtomExpressionReal : public AtomExpression
{
	private:		
		const char * _type = "real";
	public:
		AtomExpressionReal();
		AtomExpressionReal(float);
		virtual ~AtomExpressionReal();

		virtual void afficher();
		virtual const char * getType(); 
		virtual bool estCalculable();
		virtual Valeur getValeur();
		
		bool _estCalculable = true;
		Valeur _valeur;		
};
#endif
