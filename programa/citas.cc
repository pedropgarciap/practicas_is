#include "citas.h"
#include <ctime>

using namespace std;

bool Cita::setDay(int day){
            
    if ( (day > 31) || (day < 1)){

        return false;
    }

    else{
                
        day_ = day;
        return true;
    }
}

bool Cita::setMonth(int month){
            
    if ( (month > 12) || (month < 1)){

        return false;
    }

    else{
                
        month_ = month;
        return true;
    }
}

bool Cita::setYear(int year){

    if (year < 0){

        return false;                
    }

    else{
                
        year_ = year;
        return true;
    }
}

bool Cita::setHora(int hora){

    if ( (hora > 24) || (hora < 0)){

        return false;                
    }

    else{
                
        hora_ = hora;
        return true;
    }
}

bool Cita::setMinutos(int minutos){

    if ( (minutos > 59) || (minutos < 0)){

        return false;                
    }

    else{
                
        minutos_ = minutos;
        return true;
    }
}