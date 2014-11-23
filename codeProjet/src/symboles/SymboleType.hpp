#ifndef SYMBOLETYPE_HPP
#define SYMBOLETYPE_HPP

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <unistd.h>

#include "Symbole.hpp"

class SymboleType : public Symbole {

	private:
		const char * _nomType;
		bool _estCalculable = false;
	public:
		SymboleType();
		~SymboleType();
        const char * getNom();
        void setNom(const char * nom);
};
#endif
