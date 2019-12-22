#ifndef CITAS_H
#define CITAS_H

#include <ctime>
#include <vector>
#include <iostream>
#include <locale.h>
#include <string>

/*
Recoge la clase citas con todas sus funciones propias como el 
constructor y las comunmente llamadas funciones get y set.
*/

using namespace std;

class Cita{

    private:

        int day_;
        int month_;
        int year_;

        int hora_;
        int minutos_;

        string dnipaciente_;        

    public:

        inline Cita(){


        }

        //~Cita(); No es necesario

        inline int getDay(){return day_;}
        inline int getMonth(){return month_;}
        inline int getYear(){return year_;}
        inline int getHora(){return hora_;}
        inline int getMinutos(){return minutos_;}
        inline string getDniPaciente(){return dnipaciente_;}

        bool setDay(int day);
        bool setMonth(int month);
        bool setYear(int year);
        bool setHora(int hora);
        bool setMinutos(int minutos);
        inline void setDniPaciente(string dnipaciente){dnipaciente_ = dnipaciente;};

};


#endif