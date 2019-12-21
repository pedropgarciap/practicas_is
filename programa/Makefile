CXX = g++
CXXFLAGS = -std=c++11

DIRECTORIO = /home/i82gaibj/Desktop/programa

MAIN = main
SISTEMA = sistema
MENUS = menus
PACIENTES = pacientes
TRATAMIENTOS = tratamientos

#Ejecucion·························································

.PHONY: main all clean


#Reglas

main:
	$(CXX) $(SISTEMA).cc $(MENUS).cc $(PACIENTES).cc $(TRATAMIENTOS).cc $(MAIN).cc -o $(MAIN) $(CXXFLAGS)

clean:
	rm *.o main

all: main clean