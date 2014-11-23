#ifndef ATOMEXPRESSION_BOOLEAN_HPP
#define ATOMEXPRESSION_BOOLEAN_HPP

#include "AtomExpression.hpp"

class AtomExpressionBoolean : public AtomExpression
{
	private: 		
		const char* _type = "boolean";	
		
	public:	
		AtomExpressionBoolean();
		AtomExpressionBoolean(bool);
		virtual ~AtomExpressionBoolean();
		
		virtual void afficher();
		virtual const char * getType();
		virtual bool estCalculable();
		virtual Valeur getValeur();

		bool _estCalculable = true;

		Valeur _valeur;		
};
#endif
