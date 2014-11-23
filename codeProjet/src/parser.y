%{
	#include <cstddef>
	#include <cstdio>
	#include <string>

    #include <vector>
    #include <typeinfo>

    #include "TableSymboles.hpp"

	#include "symboles/Symbole.hpp"
    #include "symboles/SymboleProg.hpp"
	#include "symboles/SymboleVar.hpp"
	#include "symboles/SymboleProc.hpp"
	#include "symboles/SymboleFonc.hpp"
	#include "symboles/SymboleArg.hpp"
	#include "symboles/SymboleConst.hpp"

    #include "AtomExpression/AtomExpressionInteger.hpp"
    #include "AtomExpression/AtomExpressionBoolean.hpp"
    #include "AtomExpression/AtomExpressionString.hpp"
    #include "AtomExpression/AtomExpressionReal.hpp"
    #include "AtomExpression/AtomExpressionChar.hpp"
    
    #include "MathExpression/MathExpressionPlus.hpp"
    #include "MathExpression/MathExpressionMoins.hpp"
    #include "MathExpression/MathExpressionMult.hpp"
    #include "MathExpression/MathExpressionDiv.hpp"
    #include "MathExpression/MathExpressionMod.hpp"    
    #include "MathExpression/MathExpressionSlash.hpp"
    #include "MathExpression/MathExpressionExp.hpp"

    #include "CompExpression/CompExpressionEqual.hpp"
	#include "CompExpression/CompExpressionNonEqual.hpp"
	#include "CompExpression/CompExpressionPlusGrand.hpp"	
	#include "CompExpression/CompExpressionPlusGrandEqual.hpp"	
	#include "CompExpression/CompExpressionPlusPetit.hpp"
    #include "CompExpression/CompExpressionPlusPetitEqual.hpp"

    #include "BoolExpression/BoolExpressionAND.hpp"
    #include "BoolExpression/BoolExpressionNOT.hpp"
    #include "BoolExpression/BoolExpressionOR.hpp"
    #include "BoolExpression/BoolExpressionXOR.hpp"

	#include "TableIdentificateurs.hpp"
	

    extern TableIdentificateurs * tableIdentificateurs;
    extern TableSymboles * tableSymbolesCourante;

    extern SymboleProg * symboleProg;

	extern int yyerror ( char* );
	extern "C" int yylex ();
    
    void yyerror (char const *s) {
    }

    extern FILE* yyin;
    extern int yyleng;
    extern char* yytext;
    extern int yyparse ();

%}

%code requires {
	#include "myVector.hpp"
	#include "symboles/SymboleFonc.hpp"
    #include "AtomExpression/AtomExpression.hpp"
    #include "AtomExpression/AtomExpressionInteger.hpp"
    #include "AtomExpression/AtomExpressionBoolean.hpp"
    #include "AtomExpression/AtomExpressionString.hpp"
    #include "AtomExpression/AtomExpressionReal.hpp"
    #include "AtomExpression/AtomExpressionChar.hpp"
    #include "Expressions/Expression.hpp"
}

%union {	
 const char * _tok;
AtomExpression  * _tokAtom;
AtomExpressionInteger * _tokAtomInteger;
AtomExpressionBoolean  * _tokAtomBoolean;
AtomExpressionString * _tokAtomString;
AtomExpressionReal  * _tokAtomReal;
AtomExpressionChar * _tokAtomChar;
Expression * _tokExpression;
vectorList * _vector;
SymboleFonc * _fonction;
}

%token KW_PROGRAM
%token KW_CONST
%token KW_TYPE
%token KW_VAR
%token KW_ARRAY
%token KW_OF
%token KW_RECORD
%token KW_BEGIN
%token KW_END
%token KW_DIV
%token KW_MOD
%token KW_AND
%token KW_OR
%token KW_XOR
%token KW_NOT
%token KW_IF
%token KW_THEN
%token KW_ELSE
%token KW_WHILE
%token KW_DO
%token KW_REPEAT
%token KW_UNTIL
%token KW_FOR
%token KW_TO
%token KW_DOWNTO
%token KW_PROC
%token KW_FUNC
%token KW_INTEGER
%token KW_REAL
%token KW_BOOLEAN
%token KW_CHAR
%token KW_STRING

%token KW_WRITE
%token KW_WRITELN
%token KW_READ

%token SEP_SCOL
%token SEP_DOT
%token SEP_DOTS
%token SEP_DOTDOT
%token SEP_COMMA
%token SEP_CO
%token SEP_CF
%token SEP_PO
%token SEP_PF

%token OP_EQ
%token OP_NEQ
%token OP_LT
%token OP_LTE
%token OP_GT
%token OP_GTE
%token OP_ADD
%token OP_SUB
%token OP_MUL
%token OP_SLASH
%token OP_EXP
%token OP_AFFECT

// on spécifie que TOK_IDENT va etre typé avec _tok
%token<_tok> TOK_IDENT

%token<_tokAtomInteger> TOK_INTEGER
%token<_tokAtomReal>  TOK_REAL
%token<_tokAtomBoolean>  TOK_BOOLEAN
%token<_tokAtomChar>  TOK_CHAR
%token<_tokAtomString>  TOK_STRING


%start Program

%nonassoc OP_EQ OP_NEQ OP_GT OP_LT OP_GTE OP_LTE
%left OP_ADD OP_SUB KW_OR KW_XOR
%left OP_MUL OP_SLASH KW_AND KW_DIV KW_MOD
%right KW_NOT OP_NEG OP_POS
%left OP_EXP
%nonassoc OP_PTR
%nonassoc OP_DOT
%left SEP_CO
%nonassoc KW_IFX
%nonassoc KW_ELSE

// on spécifie que SimpleType va etre typé avec _tok
%type<_tok> SimpleType BaseType FuncResult KW_INTEGER KW_REAL KW_BOOLEAN KW_CHAR KW_STRING
%type<_vector> ListIdent
%type<_fonction> FuncIdent
%type<_tokAtom> AtomExpr
%type<_tokExpression> Expression MathExpr CompExpr VarExpr BoolExpr

%%
	
Program				:	ProgramHeader SEP_SCOL Block SEP_DOT
                        {
                          symboleProg->afficher();							
                        }
					;

ProgramHeader		:	KW_PROGRAM TOK_IDENT
                        {
                          // La table des symboles courantes = principale
                         tableSymbolesCourante = symboleProg->getTableSymboles();                         
                        }
					;

Block				:	BlockDeclConst BlockDeclType BlockDeclVar BlockDeclFunc BlockCode
					;

BlockSimple			:	BlockDeclConst BlockDeclType BlockDeclVar BlockCode
					;

BlockDeclConst		:	KW_CONST ListDeclConst
			 		|
			 		;

ListDeclConst		:	ListDeclConst DeclConst
			 		|	DeclConst
			 		;

DeclConst			:	TOK_IDENT OP_EQ Expression SEP_SCOL
						 { 
							if($3->estCalculable()) // Si c'est une constante
                            {
                                SymboleConst * s = new SymboleConst(tableIdentificateurs->getNom(tableIdentificateurs->getNumero($1)),
                                                                    $3->getValeur(),
                                                                    $3->getType()); 
                                tableSymbolesCourante->ajouter(tableIdentificateurs->getNumero($1), s);
                                tableSymbolesCourante->setTableParent(symboleProg->getTableSymboles());
                                
                            }
							else std::cerr << "Impossible d'affecter une expression non constante à une constante" << std::flush;
						}
					|	TOK_IDENT SEP_DOTS BaseType OP_EQ Expression SEP_SCOL
					    {
                            if($5->estCalculable()) // Si c'est une constante
                            {
                                SymboleConst * s = new SymboleConst(tableIdentificateurs->getNom(tableIdentificateurs->getNumero($1)),
                                                                    $5->getValeur(),
                                                                    $3);                          
                                tableSymbolesCourante->ajouter(tableIdentificateurs->getNumero($1), s);
                                tableSymbolesCourante->setTableParent(symboleProg->getTableSymboles());
                            }
                            else std::cerr << "Impossible d'affecter une expression non constante à une constante" << std::flush;
                        }
			 		;

BlockDeclType		:	KW_TYPE ListDeclType
			 		|
			 		;

ListDeclType		:	ListDeclType DeclType
			 		|	DeclType
			 		;

DeclType			:	TOK_IDENT OP_EQ Type SEP_SCOL
			 		;

Type				:	UserType
			 		|	SimpleType
			 		;

UserType			:	EnumType
			 		|	InterType
			 		|	ArrayType
			 		|	RecordType
			 		;

SimpleType			:	BaseType
                    |	TOK_IDENT
					;

BaseType			:	KW_INTEGER { $$ = "integer";}
					|	KW_REAL {$$ = "real";}
					|	KW_BOOLEAN { $$ = "boolean";}
					|	KW_CHAR {$$ = "char";}
					|	KW_STRING { $$ = "string";}
					;

EnumType			:	SEP_PO ListEnumValue SEP_PF
			 		;

ListEnumValue		:	ListEnumValue SEP_COMMA TOK_IDENT
			 		|	TOK_IDENT
			 		;

InterType			:	InterBase SEP_DOTDOT InterBase
			 		;

InterBase			:	TOK_IDENT
			 		|	TOK_INTEGER
			 		|	TOK_CHAR
			 		;

ArrayType			:	KW_ARRAY SEP_CO ArrayIndex SEP_CF KW_OF SimpleType
			 		;

ArrayIndex			:	TOK_IDENT
			 		|	InterType
			 		;

RecordType			:	KW_RECORD RecordFields KW_END
			 		;

RecordFields		:	RecordFields SEP_SCOL RecordField
			 		|	RecordField
			 		;

RecordField			:	ListIdent SEP_DOTS SimpleType
			 		;

BlockDeclVar		:	KW_VAR ListDeclVar
			 		|
			 		;

ListDeclVar			:	ListDeclVar DeclVar
			 		|	DeclVar 
			 		;

DeclVar 			: 	ListIdent SEP_DOTS SimpleType SEP_SCOL 
					{
                        for(std::vector<int>::iterator it = $1->_vector->begin() ; it != $1->_vector->end() ; ++it)
                        {
                            SymboleVar * s = new SymboleVar();
                            s->setType($3);
                            s->setNom(tableIdentificateurs->getNom(*it));
                            
                            tableSymbolesCourante->ajouter(*it, s);
                        }


                   		// Libération mémoire du vecteur maintenant inutile
                        delete $1->_vector;
                        delete $1;
					}
			 		;

	ListIdent		:	ListIdent SEP_COMMA TOK_IDENT
                        {
                            $1->_vector->push_back(tableIdentificateurs->getNumero($3));
                            $$ = $1;
						}
			 		|	TOK_IDENT
						{
                            vectorList* vector = (vectorList*) malloc(sizeof(vectorList));
                            vector->_vector = new std::vector<int>;
                            vector->_vector->push_back(tableIdentificateurs->getNumero($1));
                            $$ = vector;
						}
					;

BlockDeclFunc		:	ListDeclFunc SEP_SCOL
			 		|
			 		;

ListDeclFunc		:	ListDeclFunc SEP_SCOL DeclFunc
                    |	DeclFunc
			 		;

DeclFunc			:	ProcDecl

                    |	FuncDecl
			 		;

ProcDecl			:	ProcHeader SEP_SCOL BlockSimple
			 		;

ProcHeader			:	ProcIdent
			 		|	ProcIdent FormalArgs 
			 		;

ProcIdent			:	KW_PROC TOK_IDENT
                        {
                            SymboleProc * symboleProcedure = new SymboleProc();
                            symboleProcedure->setNom($2);

                            symboleProcedure->getTableSymboles()->setTableParent(symboleProg->getTableSymboles());
                            symboleProg->ajouterALaTable(tableIdentificateurs->getNumero($2), symboleProcedure);
                            tableSymbolesCourante = symboleProcedure->getTableSymboles();
                            tableSymbolesCourante->setTableParent(symboleProg->getTableSymboles());
                        }
			 		;

FormalArgs			:	SEP_PO ListFormalArgs SEP_PF
			 		;

ListFormalArgs		:	ListFormalArgs SEP_SCOL FormalArg
                    |	FormalArg
			 		;

FormalArg			:	ValFormalArg
                    |	VarFormalArg
			 		;

// pgdc ( a : integer ; b : integer )
//        ^^^^^^^^^^^   ^^^^^^^^^^^			 		
ValFormalArg		:	ListIdent SEP_DOTS SimpleType
                        {
                            for(std::vector<int>::iterator it = $1->_vector->begin() ; it != $1->_vector->end() ; ++it)
                            {
                              SymboleArg * s = new SymboleArg();
                              s->setTypeArgument($3);
                              s->setNom(tableIdentificateurs->getNom(*it));
                              tableSymbolesCourante->ajouter(*it, s);
                            }

                           // Libération mémoire du vecteur maintenant inutile
                           delete $1->_vector;
                           delete $1;
                        }
				 	;

VarFormalArg		:	KW_VAR ListIdent SEP_DOTS SimpleType
                        {
                              for(std::vector<int>::iterator it = $2->_vector->begin() ; it != $2->_vector->end() ; ++it)
                                {
                                  SymboleArg * s = new SymboleArg();
                                  s->setTypeArgument($4);
                                  s->setNom(tableIdentificateurs->getNom(*it));
                                  tableSymbolesCourante->ajouter(*it, s);
                                }

                            // Libération mémoire du vecteur maintenant inutile
                           delete $2->_vector;
                           delete $2;
                        }
				 	;

FuncDecl			:	FuncHeader SEP_SCOL BlockSimple 
			 		;

FuncHeader			:	FuncIdent FuncResult
                        {
							$1->setTypeRetour($2);
                        }
                    |	FuncIdent FormalArgs FuncResult
                        {
							$1->setTypeRetour($3);
                        }
			 		;

FuncIdent			:	KW_FUNC TOK_IDENT
                        {							
                            SymboleFonc * symboleFonction = new SymboleFonc();
                            symboleFonction->setNom($2);
                            symboleFonction->getTableSymboles()->setTableParent(symboleProg->getTableSymboles());
                            tableSymbolesCourante = symboleFonction->getTableSymboles();
                            tableSymbolesCourante->setTableParent(symboleProg->getTableSymboles());
                            symboleProg->ajouterALaTable(tableIdentificateurs->getNumero($2), symboleFonction);
							$$ = symboleFonction;
                        }
			 		;

FuncResult			:	SEP_DOTS SimpleType 
					{ 
						$$ = $2; 
					}
			 		;

BlockCode			:	KW_BEGIN ListInstr KW_END
					|	KW_BEGIN ListInstr SEP_SCOL KW_END
					|	KW_BEGIN KW_END
			 		;

ListInstr			:	ListInstr SEP_SCOL Instr
                    |	Instr
			 		;

Instr				:	KW_WHILE Expression KW_DO Instr
			 		|	KW_REPEAT ListInstr KW_UNTIL Expression
			 		|	KW_FOR TOK_IDENT OP_AFFECT Expression ForDirection Expression KW_DO Instr
			 		|	KW_IF Expression KW_THEN Instr %prec KW_IFX
			 		|	KW_IF Expression KW_THEN Instr KW_ELSE Instr
                    |	VarExpr OP_AFFECT Expression
                        {
                        }
			 		|	TOK_IDENT SEP_PO ListeExpr SEP_PF
			 		|	TOK_IDENT
			 		|	KW_WRITE SEP_PO ListeExpr SEP_PF
			 		|	KW_WRITELN SEP_PO ListeExpr SEP_PF
			 		|	KW_READ SEP_PO VarExpr SEP_PF
			 		|	KW_WRITELN
			 		|	BlockCode
			 		;

ForDirection		:	KW_TO
			 		|	KW_DOWNTO
			 		;

Expression			:	MathExpr { $$ = $1; std::cout << "MATH" << std::endl;}
                    |	CompExpr { $$ = $1; std::cout << "COMP" << std::endl;}
                    |	BoolExpr { $$ = $1; }
                    |	AtomExpr { $$ = $1; std::cout << "ATOM" << std::endl;}
                    |	VarExpr { $$ = $1; std::cout << "VAR" << std::endl;}
					|	TOK_IDENT SEP_PO ListeExpr SEP_PF
			 		;

MathExpr			:	Expression OP_ADD Expression { $$ = new MathExpressionPlus($1, $3); }
                    |	Expression OP_SUB Expression { $$ = new MathExpressionMoins($1, $3); }
                    |	Expression OP_MUL Expression  { $$ = new MathExpressionMult($1, $3); }
                    |	Expression OP_SLASH Expression {$$ = new MathExpressionSlash($1, $3);}
                    |	Expression KW_DIV Expression { $$ = new MathExpressionDiv($1, $3);}
                    |	Expression KW_MOD Expression { $$ = new MathExpressionMod($1, $3); }
                    |	Expression OP_EXP Expression { $$ = new MathExpressionExp($1, $3); }
			 		|	OP_SUB Expression %prec OP_NEG
			 		|	OP_ADD Expression %prec OP_POS
			 		;

CompExpr			:	Expression OP_EQ Expression { $$ = new CompExpressionEqual($1, $3); }
                    |	Expression OP_NEQ Expression { $$ = new CompExpressionNonEqual($1, $3); }
                    |	Expression OP_LT Expression { $$ = new CompExpressionPlusPetit($1, $3); }
                    |	Expression OP_LTE Expression { $$ = new CompExpressionPlusPetitEqual($1, $3); }
                    |	Expression OP_GT Expression { $$ = new CompExpressionPlusGrand($1, $3); }
                    |	Expression OP_GTE Expression { $$ = new CompExpressionPlusGrandEqual($1, $3); }
			 		;

BoolExpr			:	Expression KW_AND Expression { $$ = new BoolExpressionAND($1, $3);}
                    |	Expression KW_OR Expression  { $$ = new BoolExpressionOR($1, $3);}
                    |	Expression KW_XOR Expression  { $$ = new BoolExpressionXOR($1, $3);}
                    |	KW_NOT Expression  { $$ = new BoolExpressionNOT($2); }
                    ;

AtomExpr			:	SEP_PO Expression SEP_PF //{ $$ = $2; }
                    |	TOK_INTEGER { $$ = $1; }
                    |	TOK_REAL  { $$ = $1; }
                    |	TOK_BOOLEAN { $$ = $1; }
                    |	TOK_CHAR  { $$ = $1; }
                    |	TOK_STRING { $$ = $1; }
			 		;

VarExpr				:	TOK_IDENT
                        {
                        
                            Symbole * symbole = tableSymbolesCourante->chercher($1);
                            if(symbole == nullptr) symbole = tableSymbolesCourante->getTableParent()->chercher($1);

                           if(symbole != nullptr)
                           {
                                std::cout << "Variable " << $1 << " trouvée dans la table courante!\n" << std::endl;
                                SymboleConst * SymbConst = dynamic_cast<SymboleConst *>(symbole);
                                if( SymbConst == 0 ) { std::cerr << "Pas calculable à la compilation" << std::endl; exit(1);}
                           
                               if(strcmp(SymbConst->getTypeValeur(), "integer") == 0) $$ = new AtomExpressionInteger(((SymboleConst *)symbole)->getValeur().i);
                               else if(strcmp(SymbConst->getTypeValeur(), "real") == 0) $$ = new AtomExpressionReal(((SymboleConst *)symbole)->getValeur().f);
                               else if(strcmp(SymbConst->getTypeValeur(), "char") == 0) $$ = new AtomExpressionChar(((SymboleConst *)symbole)->getValeur().c);
                               else if(strcmp(SymbConst->getTypeValeur(), "string") == 0) $$ = new AtomExpressionString(((SymboleConst *)symbole)->getValeur().s);
                               else $$ = new AtomExpressionBoolean(SymbConst->getValeur().b);
                               
                               //delete SymbConst;
                           }
                           else
                           { 
                                std::cerr << "Variable " << $1 << " non déclarée!\n" << std::endl; 
                                exit(1); 
                           }
                           
                           
                        }
                    |	VarExpr SEP_CO Expression SEP_CF// { std::cout << "VAR 1" << std::endl; }
                    |	VarExpr SEP_DOT TOK_IDENT %prec OP_DOT// { std::cout << "VAR 2" << std::endl; }
					;

ListeExpr			:	ListeExpr SEP_COMMA Expression
					|	Expression
					;

%%
