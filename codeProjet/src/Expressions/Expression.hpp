#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <typeinfo>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctgmath>

typedef union {
		char * s;
		char c;
		int i;
		float f;
		bool b;	
} Valeur;

class Expression
{
    public:	

        virtual const char * getType() = 0;
        virtual void afficher() = 0;
	virtual bool estCalculable() = 0;
	virtual Valeur getValeur() = 0;

	
};

#endif
