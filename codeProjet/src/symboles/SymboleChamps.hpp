#ifndef SYMBOLECHAMPS_H
#define SYMBOLECHAMPS_H

#include "Symbole.hpp"

#include <map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <unistd.h>


class SymboleChamps : public Symbole {

	private:
		const char * _nomChamps;

	public:
		SymboleChamps();
		~SymboleChamps();
        const char * getNom();
        void setNom(const char * nom);
};

#endif
