#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

#include "TableIdentificateurs.hpp"
#include "TableSymboles.hpp"
#include "symboles/SymboleProg.hpp"
#include "symboles/Symbole.hpp"
#include "type/TypeInteger.hpp"

void showUsage(char ** argv);

extern int yyparse ();
extern FILE* yyin;

TableIdentificateurs * tableIdentificateurs = new TableIdentificateurs();
TableSymboles * tableSymbolesCourante = new TableSymboles();
SymboleProg * symboleProg = new SymboleProg();



string pascalFileName;

using namespace std;

int main ( int argc, char** argv )
{
	int i, indexOfPascalFileToCompile;
	bool optimisation = false;
	bool assembly = false;

	/* Gestion de la ligne de commande */
	/* iteration sur les arguments du cli*/
	for (i = 1; i < argc; i++)
	{

		if (strncmp(argv[i], "-c", 2) == 0)
		{
			// on a trouvé un "-c"

			if (i+1 < argc)
			{
				// s'il y a un parametre pour l'option 'c'
				// dans argv[i+1] il a le nom du fichier pascal à traiter
				// TODO
				// fonctionnement normal de l'appli
				indexOfPascalFileToCompile = i+1;
			} else
			{
				// s'il n'y a pas de parametre pour l'option 'c'
				fprintf(stderr, "%s: option requires an argument -- '%s'\n", argv[0], argv[i]);
				fprintf(stderr, "Try '%s --help' for more information.\n", argv[0]);
				return 1;
			}
		}

		if (strncmp(argv[i], "-O", 2) == 0)
		{
			// si on a -O
			// activer les optimisations

			assembly = true;
			fprintf(stderr, "%s: option is not yet available -- '%s'\n", argv[0], argv[i]);
			fprintf(stderr, "Try '%s --help' for more information.\n", argv[0]);
			return 1;
		}

		if (strncmp(argv[i], "-a", 2) == 0)
		{
			// si on a -a
			// activer la génération du code assembleur

			assembly = true;
			fprintf(stderr, "%s: option is not yet available -- '%s'\n", argv[0], argv[i]);
			fprintf(stderr, "Try '%s --help' for more information.\n", argv[0]);
			return 1;
		}


		if ((strncmp(argv[i], "--help", 6) == 0) || 
			(strncmp(argv[i], "-h", 2) == 0))
		{
			// si on a --help ou -c 
			showUsage(argv);
			return 0;
		}
	}

	if (argc == 1) {
		showUsage(argv);
		return 1;
	}
	
	if (! (assembly) && !(optimisation) )
	{
		// traitement normal
		// argv[indexOfPascalFileToCompile] contient le fichier pascal

		// on copie le descripteur du stdin
		dup(0);

		// on ferme le descripteur du stdin
		close(0);
		
		FILE * pascalSrc;
		pascalSrc = fopen(argv[indexOfPascalFileToCompile], "r");
		
		// récupération du nom du fichier pascal
        std::string s(argv[indexOfPascalFileToCompile]);
        std::string delimiter = ".";
		
		// on enleve ce qu'il y a après le . et le .
		pascalFileName = s.substr(0, s.find(delimiter));

		// on enlève ce qui précède un /
		std::size_t found = pascalFileName.find_last_of("/");
		pascalFileName.erase (0, found+1); 
        // pascalFilename contient juste le nom du fichier
	
         symboleProg->setNom(pascalFileName.c_str());
         
		/* Initialisation des données du compilateur */
		/* phases d'analyse */
		yyparse ();

		/* traitements post analyse */
		/* sauvegarde des resultats */
		

		
		// écriture table ID 
        fclose(pascalSrc);
        
		return 0;
	} else
	{
		return 1;
	}

}

void showUsage(char ** argv) {
	cout << "Usage:" << argv[0] << " [OPTION]... -c [FILE]...\n\n";
	cout << "-c     		filename of the pascal source file to compile\n";
	cout << "-O     		enable optimisations (not yet available)\n";
	cout << "-a     		enable assembly code generation (not yet available)\n";
	cout << "-h, --help 	show this help message\n";
}
