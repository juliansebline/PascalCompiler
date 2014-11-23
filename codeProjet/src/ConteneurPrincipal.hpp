#ifndef CONTENEURPRINCIPAL_H
#define CONTENEURPRINCIPAL_H

#include <map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

#include "symboles/Symbole.hpp"
#include "TableSymboles.hpp"

class ConteneurPrincipal
{
	private:
		TableSymboles _principale;
	public:
		ConteneurPrincipal();
		ConteneurPrincipal(TableSymboles *);
		~ConteneurPrincipal();
};
#endif
