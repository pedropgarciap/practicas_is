#ifndef SISTEMA_H
#define SISTEMA_H

#include "pacientes.h"
#include <list>

class Sistema
{
    private:
        
        list <Paciente> pacientes_;

    public:
        
        Sistema();
        ~Sistema();

        inline list <Paciente> getPacientes(){return pacientes_;};

        bool comprobarExistenciaPaciente(string dni);
        bool comprobarExistenciaPaciente(string nombre, string apellidos);
        int addPaciente();

        void buscarPaciente(string nombre, string apellidos);

        Paciente * buscaPaciente(string dni);
        void modificarPaciente();

        void borrarPaciente();

        void leeFichero();
        void escribeFichero();

        void mostrarPacientes();

};


#endif