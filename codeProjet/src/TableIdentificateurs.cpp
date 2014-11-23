#include "TableIdentificateurs.hpp"
using namespace std;

TableIdentificateurs::TableIdentificateurs() : map()
{
}

TableIdentificateurs::~TableIdentificateurs()
{
}

/*
 * ajoute un identificateur a la table
 * renvoie le numero unique associe
 * si il est deja present , ne fait que renvoyer son numero
 */
unsigned int TableIdentificateurs::ajoutIdentificateur( const char * identificateur )
{
	std::map<unsigned int, const char*>::iterator it;

	for (it = map.begin(); it != map.end(); it++)
	{
		if(strcmp(it->second, identificateur) == 0)
		{
			return it->first;
		}
	}

	map.insert( std::pair<unsigned int, const char*>( map.size() + 1, identificateur) );
	return (unsigned int) map.size();
}

/*
 * recupere le nom associe a un numero unique
 */
const char * TableIdentificateurs::getNom ( const unsigned int indice)
{
	if(indice > 0 || indice < map.size())
		return map.find(indice)->second;
	else return NULL;
}

const unsigned int TableIdentificateurs::getNumero ( const char * nom)
{
	if(nom == NULL)
	{
		cout << "NULL\n" ;
		return 0;
	}

	std::map<unsigned int, const char*>::iterator it;

	for (it = map.begin(); it != map.end(); it++)
	{
		if(strcmp(it->second, nom) == 0)
		{
			return it->first;
		}
	}

	return 0;
}

/*
 *affiche la table sur la sortie standard
 */
void TableIdentificateurs::afficherTableIdent ()
{
	std::map<unsigned int, const char*>::iterator it;

	cout << "** Table Identificateur\n";

	for(it = map.begin(); it != map.end(); it++)
	{
		cout <<  it->first << "\t" << it->second << '\n';
	}
}

/*
sauvegarde la table dans un fichier
le nom du fichier est passe en argument
*/
void TableIdentificateurs::sauvegarderTableIdent ( const char * nomFichier )
{
	FILE* fichier = fopen(nomFichier, "w");
	std::map<unsigned int, const char*>::iterator it;

	for(it = map.begin(); it != map.end(); it++)
		fprintf(fichier, "%u%c%s\n", it->first, ',' , it->second);

	fclose(fichier);
}
