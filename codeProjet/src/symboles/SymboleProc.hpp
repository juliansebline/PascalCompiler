#ifndef SYMBOLEPROC_HPP
#define SYMBOLEPROC_HPP

#include "Symbole.hpp"
#include "TableSymboles.hpp"

#include <map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>

using namespace std;

class SymboleProc : public Symbole {

	private:
        TableSymboles * _table;
		int _nbArguments;
        const char * _nomProc;
		const char * _type = "Procedure";        

	public:
		SymboleProc();
		~SymboleProc();
		
		virtual const char * getNom();
		virtual const char * getType();
		virtual void setNom(const char *);
		virtual void afficher();

		void setNbArguments(int);
		int getNbArguments();
		void setTableSymboles(TableSymboles *);
		TableSymboles * getTableSymboles();

		void ajouterALaTable(unsigned int, Symbole*);
};
#endif
