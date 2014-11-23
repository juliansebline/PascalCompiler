#ifndef SYMBOLECONST_H
#define SYMBOLECONST_H

#include "../type/Type.hpp"
#include "Symbole.hpp"

#include "../type/TypeInteger.hpp"
#include "../type/TypeBoolean.hpp"
#include "../type/TypeString.hpp"
#include "../type/TypeChar.hpp"
#include "../type/TypeReal.hpp"

#include "../Expressions/Expression.hpp"

/*#include <map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <unistd.h>*/

class SymboleConst : public Symbole {

	private:
		const char * _nomConst;
		const char * _type = "const";
		const char * _typeValeur;
		Type * _objetTypeValeur;
		Valeur _valeur; 

	public:
		SymboleConst();
		SymboleConst(const char *, Valeur, const char *);
		virtual ~SymboleConst();
		virtual const char * getNom();
		virtual const char * getType();
		virtual void setNom(const char *);
		virtual void afficher();
		
		void setTypeValeur(const char *);
		void setValeur(Valeur);
		const char * getTypeValeur();
		Valeur getValeur();
};

#endif
