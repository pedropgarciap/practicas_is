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
        int addPaciente();

        void buscarPaciente(string dni);

        Paciente * buscaPaciente(string dni);
        void modificarPaciente();

        void borrarPaciente();

        void leeFichero();
        void leeTratamientos();
        void escribeFichero();
        void escribeTratamientos();

        void mostrarPacientes();

        void addTratamiento(Paciente & paciente);
        void modificarTratamiento(Paciente & paciente);
        void mostrarTratamiento(Paciente & paciente);

};


#endif