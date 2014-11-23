#ifndef SYMBOLEARG_H
#define SYMBOLEARG_H

#include <map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>

#include "Symbole.hpp"

class SymboleArg : public Symbole{

	private:
		   const char * _typeArgument;
		   const char * _modePassage;
		   const char * _nomArgument;
			const char * _type = "Argument";

    public:
		SymboleArg();
		~SymboleArg();
        virtual const char * getNom();
		virtual const char * getType();
        virtual void setNom(const char *);
        virtual void afficher();

        void setTypeArgument(const char * );
        const char * getTypeArgument();

};
#endif
