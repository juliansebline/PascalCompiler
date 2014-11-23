#ifndef SYMBOLEFONC_HPP
#define SYMBOLEFONC_HPP

#include "Symbole.hpp"
#include "../TableSymboles.hpp"

#include <map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>


class SymboleFonc : public Symbole {

	private:
		TableSymboles * _table;
		const char * _nomFonc;
		int _nbArguments;
		const char * _typeRetour;
		const char * _type = "Fonction";

	public:
		SymboleFonc();
		~SymboleFonc();

		virtual const char * getNom();
		virtual const char * getType();
		virtual void setNom(const char *);
		virtual void afficher();

		void setTableSymboles(TableSymboles *);
		void setTypeRetour(const char *);
		void setNbArguments(int);

		const char * getTypeRetour();
		int getNbArguments();
		TableSymboles * getTableSymboles();

		void ajouterALaTable(unsigned int indice, Symbole* symbole);
};
#endif
