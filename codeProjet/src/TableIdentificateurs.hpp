#ifndef TABLEIDENT_HPP
#define TABLEIDENT_HPP

#include <map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>

using namespace std;

class TableIdentificateurs
{

private :
    std::map<unsigned int, const char *> map;

public :

	TableIdentificateurs();
	~TableIdentificateurs();
	
	unsigned int ajoutIdentificateur ( const char * ) ;	
	const char * getNom ( const unsigned int ) ;
	void afficherTableIdent () ;
	void sauvegarderTableIdent ( const char * ) ; 
	std::map<unsigned int, char *> getMap() ;
	const unsigned int getNumero ( const char * );
};
#endif
