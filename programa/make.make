indice: main.exe clean

main.exe: main.o sistema.o menus.o pacientes.o tratamientos.o
	g++ -o main.exe main.o sistema.o paciente.o tratamientos.o -std=gnu++11

main.o: main.cc
	g++ -c main.cc

sistema.o: sistema.cc
	g++ -c sistema.cc

menus.o: menus.cc
	g++ -c menus.cc
	
paciente.o: pacientes.cc
	g++ -c paciente.cc

tratamiento.o: tratamientos.cc
	g++ -c tratamiento.cc
	
.PHONY: clean

clean:
	del /Q /S *.o *.txt