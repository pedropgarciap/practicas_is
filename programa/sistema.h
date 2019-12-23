#ifndef SISTEMA_H
#define SISTEMA_H

#include "pacientes.h"
#include "citas.h"
#include "historial.h"
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

        bool comprobarExistenciaPaciente(string dni); //Subfuncion
        int addPaciente(); //Funcion del menu

        void buscarPaciente(string dni); //Funcion del menu

        Paciente * buscaPaciente(string dni); //Subfuncion
        void modificarPaciente(); //Funcion del menu

        void borrarPaciente(); //Funcion del menu

        void leeFichero(); //Subfuncion
        void leeTratamientos(); //Subfuncion
        void leeCitas(); //Subfuncion
        void leeHistorial(); //Subfuncion
        void escribeFichero(); //Subfuncion
        void escribeTratamientos(); //Subfuncion
        void escribeCitas(); //Subfuncion
        void escribeHistorial(); //Subfuncion

        void mostrarPacientes(); //Funcion del menu

        void addTratamiento(Paciente & paciente); //Funcion del menu
        void modificarTratamiento(Paciente & paciente); //Funcion del menu
        void mostrarTratamiento(Paciente & paciente); //Funcion del menu

        bool comprobarCita(int day, int month, int year, int hora, int minutos); //Subfuncion
        void verCitas(Paciente & paciente); //Funcion del menu
        void addCita(Paciente & paciente); //Funcion del menu
        bool buscaCita(Paciente paciente, int day, int month, int year, int hora, int minutos); //Funcion del menu
        void modificarCita(Paciente & paciente); //Funcion del menu
        void borrarCita(Paciente & paciente); //Funcion del menu
        void verCitasHoy(); //Funcion del menu

        void addHistorial(Paciente & paciente); //Funcion del menu
        void verHistorial(Paciente & paciente); //Funcion del menu
};


#endif