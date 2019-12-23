#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <iostream>

/*
Recoge la clase historial con todas sus funciones propias como el 
constructor y las bulgarmente llamadas funciones get y set.
*/

using namespace std;

class Historial{

    private:
        
        int year_;
        int month_;
        int day_;
        int hora_;
        int minutos_;

        string dnipaciente_;
        string motivovisita_;

    public:
        
        inline Historial(){};

        inline int getDay(){return day_;}
        inline int getMonth(){return month_;}
        inline int getYear(){return year_;}
        inline int getHora(){return hora_;}
        inline int getMinutos(){return minutos_;}
        inline string getDniPaciente(){return dnipaciente_;}
        inline string getMotivo(){return motivovisita_;}

        inline void setDay(int day){day_ = day;};
        inline void setMonth(int month){month_ = month;};
        inline void setYear(int year){year_ = year;};
        inline void setHora(int hora){hora_ = hora;};
        inline void setMinutos(int minutos){minutos_ = minutos;};
        inline void setDniPaciente(string dnipaciente){dnipaciente_ = dnipaciente;};
        inline void setMotivo(string motivovisita){motivovisita_ = motivovisita;};

};

#endif