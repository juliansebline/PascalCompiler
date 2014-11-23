#ifndef SYMBOLEVAR_HPP
#define SYMBOLEVAR_HPP

#include "Symbole.hpp"

#include <map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>


class SymboleVar : public Symbole {

	private:
        const char * _nomVar;
        const char * _typeVar;

	public:
		SymboleVar();
		virtual ~SymboleVar();
        virtual const char *getNom();
        virtual void setNom(const char *);
        virtual void afficher();
	    virtual const char * getType();

        void setType(const char *);

};
#endif
