#include "citas.h"
#include <ctime>

using namespace std;

//Comprueba que el dia introducido se encuentra entre los valores permitidos
bool Cita::setDay(int day){ 
            
    if ( (day > 31) || (day < 1)){

        return false;
    }

    else{
                
        day_ = day;
        return true;
    }
}

//Comprueba que el mes introducido se encuentra entre los valores permitidos
bool Cita::setMonth(int month){
            
    if ( (month > 12) || (month < 1)){

        return false;
    }

    else{
                
        month_ = month;
        return true;
    }
}

//Comprueba que el año introducido se encuentra entre los valores permitidos
bool Cita::setYear(int year){

    if (year < 0){

        return false;                
    }

    else{
                
        year_ = year;
        return true;
    }
}

//Comprueba que la hora introducida se encuentra entre los valores permitidos
bool Cita::setHora(int hora){

    if ( (hora > 24) || (hora < 0)){

        return false;                
    }

    else{
                
        hora_ = hora;
        return true;
    }
}

//Comprueba que los minutos introducidos se encuentran entre los limites permitidos
bool Cita::setMinutos(int minutos){

    if ( (minutos > 59) || (minutos < 0)){

        return false;                
    }

    else{
                
        minutos_ = minutos;
        return true;
    }
}