#ifndef SYMBOLEETIQ_HPP
#define SYMBOLEETIQ_HPP

#include "Symbole.hpp"

#include <map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <unistd.h>


class SymboleEtiq : public Symbole {

	private:
		const char * _nomEtiq;

	public:
		SymboleEtiq();
		~SymboleEtiq();
        const char * getNom();
        void setNom(const char * nom);
};
#endif
