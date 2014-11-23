#ifndef ATOMEXPRESSION_CHAR_HPP
#define ATOMEXPRESSION_CHAR_HPP

#include "AtomExpression.hpp"

class AtomExpressionChar : public AtomExpression
{
	private:
		const char * _type = "char";
		
	public:
		AtomExpressionChar();
		AtomExpressionChar(char);
		virtual ~AtomExpressionChar();
		
		virtual void afficher();
		virtual const char * getType();
		virtual bool estCalculable();
		virtual Valeur getValeur();
		  
		bool _estCalculable = true;
		Valeur _valeur;
};
#endif
