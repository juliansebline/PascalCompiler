SRCD = src
INCD = include
OBJD = obj
BIND = bin

#CXX = clang++
CXX = g++

EXEC = ppc
SYMBD = symboles
ATOMD = AtomExpression
TYPED = type
INTERMD = intermediaire
MATHD = MathExpression
EXPRESSIOND = Expressions
COMPEXPRESSIOND = CompExpression
BOOLEXPRESSIOND = BoolExpression

OBJFILES = parser.o main.o lexer.o  myVector.o TableIdentificateurs.o TableSymboles.o Expression.o Type.o TypeInteger.o TypeString.o TypeBoolean.o TypeChar.o TypeReal.o TypeInteger.o Symbole.o SymboleConst.o SymboleProg.o  SymboleVar.o SymboleProc.o SymboleFonc.o SymboleVar.o SymboleVal.o SymboleArg.o AtomExpression.o AtomExpressionInteger.o AtomExpressionChar.o AtomExpressionBoolean.o AtomExpressionString.o AtomExpressionReal.o CompExpression.o CompExpressionEqual.o CompExpressionNonEqual.o CompExpressionPlusGrand.o CompExpressionPlusGrandEqual.o CompExpressionPlusPetit.o CompExpressionPlusPetitEqual.o MathExpression.o MathExpressionPlus.o MathExpressionDiv.o MathExpressionExp.o MathExpressionMod.o MathExpressionMoins.o MathExpressionMult.o MathExpressionSlash.o BoolExpression.o BoolExpressionXOR.o BoolExpressionAND.o BoolExpressionNOT.o BoolExpressionOR.o
OBJS = $(OBJFILES:%.o=$(OBJD)/%.o) 

#CXXFLAGS = -Wall -Weffc++ -pedantic -std=c++11
CXXFLAGS = -Wall -pedantic -g -std=c++11
#CXXFLAGS = -Wall -std=c++11

default: $(BIND)/$(EXEC)

$(BIND)/$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ -L/usr/lib -lfl
	#$(CXX) $(CXXFLAGS) -o $@ $^ -L/home/pers/erwan.guillou/Public/lib -lfl

$(OBJD)/%.o: $(SRCD)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< -I$(INCD) -I$(SRCD)

$(OBJD)/%.o: $(SRCD)/$(SYMBD)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< -I$(INCD) -I$(SRCD)

$(OBJD)/%.o: $(SRCD)/$(ATOMD)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< -I$(INCD) -I$(SRCD)

$(OBJD)/%.o: $(SRCD)/$(TYPED)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< -I$(INCD) -I$(SRCD)
	
$(OBJD)/%.o: $(SRCD)/$(MATHD)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< -I$(INCD) -I$(SRCD)
	
$(OBJD)/%.o: $(SRCD)/$(EXPRESSIOND)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< -I$(INCD) -I$(SRCD)

$(OBJD)/%.o: $(SRCD)/$(COMPEXPRESSIOND)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< -I$(INCD) -I$(SRCD)

$(OBJD)/%.o: $(SRCD)/$(BOOLEXPRESSIOND)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< -I$(INCD) -I$(SRCD)

$(SRCD)/parser.cpp: $(SRCD)/parser.y
	bison --verbose -d -o $@ $<

$(SRCD)/lexer.cpp: $(SRCD)/lexer.l
	flex -o $@ $<

clean:
	@rm -f $(OBJD)/*.o
	@rm -f $(SRCD)/parser.[hc]pp
	@rm -f $(SRCD)/lexer.[hc]pp
	@rm -f $(SRCD)/$(SYMBD)/*~
	@rm -f $(SRCD)/$(ATOMD)/*~
	@rm -f $(SRCD)/$(TYPED)/*~
	@rm -f $(SRCD)/$(MATHD)/*~
	@rm -f $(SRCD)/$(EXPRESSIOND)/*~
	@rm -f $(SRCD)/$(COMPEXPRESSIOND)/*~
	@rm -f $(SRCD)/$(BOOLEXPRESSIOND)/*~

mrproper: clean
	@rm -f $(BIND)/$(EXEC)
