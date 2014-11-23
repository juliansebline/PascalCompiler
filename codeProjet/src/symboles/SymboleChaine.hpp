#ifndef SYMBOLECHAINE_HPP
#define SYMBOLECHAINE_HPP

#include "Symbole.hpp"

#include <map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <unistd.h>


class SymboleChaine : public Symbole {

	private:
		const char * _nomChaine;


	public:
		SymboleChaine();
		~SymboleChaine();
		const char * getNom();
		void setNom(const char * nom);
};
#endif
