#ifndef SYMBOLE_H
#define SYMBOLE_H
/**
 * Classe abstraite représentant la signification d'un
 *  d'un identificateur 
 * Il y aura les classes filles suivantes : 
 *  programme, fonction, procedure, type, constante, 
 *  variable, argument, champs, valenum, temporaire, etiquette, chaine.
 */
#include <string>

class Symbole {

	public:
		Symbole();
		virtual ~Symbole();
		virtual const char * getNom() = 0;
		virtual void setNom(const char *) = 0;
		virtual void afficher() = 0;
		virtual const char * getType() = 0;
};
#endif
