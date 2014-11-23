#ifndef SYMBOLEVAR_HPP
#define SYMBOLEVAR_HPP

#include "Symbole.hpp"

#include <map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <unistd.h>


class SymboleVal : public Symbole {

	private:
		const char * _nomVal;

	public:
		SymboleVal();
		~SymboleVal();
        const char * getNom();
        void setNom(const char * nom);
};
#endif
