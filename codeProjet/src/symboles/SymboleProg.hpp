#ifndef SYMBOLEPROG_HPP
#define SYMBOLEPROG_HPP

#include <map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

#include "Symbole.hpp"
#include "../TableSymboles.hpp"

class SymboleProg : public Symbole {
	private:
        TableSymboles * _principale;
        const char * _nom;
	const char * _type = "Programme";

    public:
        SymboleProg();
        SymboleProg(TableSymboles *);
        ~SymboleProg();
        virtual const char * getNom();
        virtual void setNom(const char *);
        virtual void afficher();
	virtual const char * getType();

        TableSymboles * getTableSymboles();

        void ajouterALaTable(unsigned int, Symbole*);
};
#endif
