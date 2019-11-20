#ifndef SISTEMA_H
#define SISTEMA_H

#include "pacientes.h"
#include <list>
#include <iostream>

using namespace std;

class Sistema
{
    private:
        
        list <Paciente> pacientes_;

    public:
        
        inline Sistema(){cout << "SISTEMA CREADO" << endl;};

        inline list <Paciente> getPacientes(){return pacientes_;};

        bool comprobarExistenciaPaciente(string dni);
        int addPaciente();

        void mostrarPacientes();

};


#endif