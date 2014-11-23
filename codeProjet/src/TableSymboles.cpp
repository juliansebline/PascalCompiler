#include <string>

#include "TableSymboles.hpp"
#include "TableIdentificateurs.hpp"
#include "symboles/Symbole.hpp"
#include "symboles/SymboleProg.hpp"
#include "symboles/SymboleConst.hpp"

extern TableIdentificateurs *tableIdentificateurs;
extern string pascalFileName;
extern SymboleProg * symboleProg;

TableSymboles::TableSymboles()
{
}

TableSymboles::~TableSymboles()
{
}

void TableSymboles::setTableParent(TableSymboles * parent)
{
    _parent = parent;
}

void TableSymboles::setNom(const char * nom)
{
	_nom = (char *) malloc(strlen(nom) * sizeof(char));	
    strcpy(_nom, nom);
}

char * TableSymboles::getNom()
{	
    return _nom;
}

TableSymboles * TableSymboles::getTableParent()
{
    return _parent;
}

void TableSymboles::ajouter(unsigned int indice, Symbole * symbole)
{ 
    mapSymboles.insert( std::pair<unsigned int, Symbole *>( indice , symbole) );
}

void TableSymboles::get(unsigned int indice)
{
}

Symbole * TableSymboles::chercher(const char * variable)
{
        std::map<unsigned int, Symbole *>::iterator it;	

        for(it = mapSymboles.begin(); it != mapSymboles.end(); ++it)
         if(strcmp(it->second->getNom(), variable) == 0) return it->second;
	   
	   return nullptr;
}	

std::map<unsigned int, Symbole *> TableSymboles::getMap()
{
	return mapSymboles;
}

void TableSymboles::afficher()
{
	std::map<unsigned int, Symbole *>::iterator it;	
	
	ofstream tableSymbFile;
    streambuf * backup = cout.rdbuf();
	string tableSymbPath = "intermediaire/" + pascalFileName + "." + _nom  + ".ts";

	// ouverture du fichier
	tableSymbFile.open(tableSymbPath.c_str(), ios::out | ios::app | ios::binary);
		
	cout.rdbuf(tableSymbFile.rdbuf());	      
    	
	// écriture table des symboles par redirection du cout
    for(it = mapSymboles.begin(); it != mapSymboles.end(); ++it)			
	{
		std::cout << it->second->getType() << "    ";

		if(strcmp(it->second->getType(), "const") == 0){
			Symbole * symbole = it->second;
			SymboleConst * symboleConst = (SymboleConst *)symbole;
			std::cout <<  symboleConst->getTypeValeur() << "   "; 
		}
	
		std::cout << it->second->getNom();

		if(strcmp(it->second->getType(), "const") == 0)
		{
			Symbole * symbole = it->second;
			SymboleConst * symboleConst = (SymboleConst *)symbole;

			if(strcmp(symboleConst->getTypeValeur(), "integer") == 0) 
			 std::cout << "    " << symboleConst->getValeur().i  << std::endl;
			if(strcmp(symboleConst->getTypeValeur(), "string") == 0) 
			 std::cout << "    " << symboleConst->getValeur().s  << std::endl;
			if(strcmp(symboleConst->getTypeValeur(), "char") == 0) 
			 std::cout << "    " << symboleConst->getValeur().c  << std::endl;
			if(strcmp(symboleConst->getTypeValeur(), "real") == 0) 
			 std::cout << "    " << symboleConst->getValeur().f  << std::endl;
			if(strcmp(symboleConst->getTypeValeur(), "boolean") == 0) 
			 std::cout << "    " << symboleConst->getValeur().b  << std::endl;
			
		}
		else std::cout << std::endl;
	}

	// on remet le vrai cout
	cout.rdbuf(backup);  

	// on ferme les fichiers
	tableSymbFile.close();

	 for(it = mapSymboles.begin(); it != mapSymboles.end(); ++it)
       	    it->second->afficher();

}
