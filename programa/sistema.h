#ifndef SISTEMA_H
#define SISTEMA_H

#include "pacientes.h"
#include "citas.h"
#include <list>

/*
Recoge la clase sistema con todas sus funciones, en este caso la clase sistema se 
podria conocer como la clase mas externa, ya que es la que acude a todas las demas.

En esta clase se recojen las funciones clave o externas "Las que se muestran al usuario" y algunas subfunciones.
*/

class Sistema
{
    private:

        time_t now;
        tm * tiempo;
        
        list <Paciente> pacientes_;
        list <Cita> citas_;

    public:
        
        Sistema();
        ~Sistema();

        inline list <Paciente> getPacientes(){return pacientes_;};
        inline list <Cita> getCitas(){return citas_;}

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

        bool comprobarCita(int day, int month, int year, int hora, int minutos);
        void verCitas(Paciente & paciente);
        void addCita(Paciente & paciente);
        void verCitasHoy();
};


#endif