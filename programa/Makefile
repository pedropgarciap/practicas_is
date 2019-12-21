CXX = g++
CXXFLAGS = -std=c++11

#En verdad el Directorio es completamente innecesario pero queda bien
DIRECTORIO = /home/i82gaibj/Desktop/programa

MAIN = main
SISTEMA = sistema
MENUS = menus
PACIENTES = pacientes
TRATAMIENTOS = tratamientos
CITAS = citas

#Ejecucion·························································

.PHONY: main all clean


#Reglas

main:
	$(CXX) $(MAIN).cc $(SISTEMA).cc $(MENUS).cc $(PACIENTES).cc $(TRATAMIENTOS).cc $(CITAS).cc -o $(MAIN) $(CXXFLAGS)

clean:
	rm *.o main

all: main