#ifndef TABLESYMBOLES_H
#define TABLESYMBOLES_H

#include <map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <iostream>
#include <fstream>

#include "symboles/Symbole.hpp"

using namespace std;

class TableSymboles {

	private:		
        TableSymboles * _parent = NULL;
        char * _nom;
	
	public:
		TableSymboles();
		~TableSymboles();
		
		std::map<unsigned int, Symbole *> mapSymboles;
		void ajouter(unsigned int, Symbole *);		
		
		void afficher();
		void setTableParent(TableSymboles *);
		void setNom(const char *);
		Symbole * chercher(const char *);	
		
		void get(unsigned int);
		std::map<unsigned int, Symbole *> getMap();
		TableSymboles * getTableParent();
		char * getNom();	
};
#endif
