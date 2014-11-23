#ifndef SYMBOLETEMP_HPP
#define SYMBOLETEMP_HPP

#include "Symbole.hpp"

#include <map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <unistd.h>


class SymboleTemp : public Symbole {

	private:
		const char * _nomTemp;

	public:
		SymboleTemp();
		~SymboleTemp();
        const char * getNom();
        void setNom(const char * nom);
};
#endif
