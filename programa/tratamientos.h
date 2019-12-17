#ifndef TRATAMIENTOS_H
#define TRATAMIENTOS_H

#include <string> 
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class Tratamiento
{
    private:

        string duracion_;
        string medicamento_;
        string dosis_;
        string regularidad_;   
        bool estado_;     

    public:

        inline Tratamiento(string duracion = "", string medicamento = "", string dosis = "", string regularidad = ""){

            duracion_ = duracion;
            medicamento_ = medicamento;
            dosis_ = dosis;
            regularidad_ = regularidad;
        };

        inline string getDuracion(){return duracion_;};
        inline string getMedicacion(){return medicamento_;};
        inline string getDosis(){return dosis_;};
        inline string getRegularidad(){return regularidad_;};
        inline bool getEstado(){return estado_;};

        inline void setDuracion(string duracion){duracion_ = duracion;};
        inline void setMedicacion(string medicamento){medicamento_ = medicamento;};
        inline void setDosis(string dosis){dosis_ = dosis;};
        inline void setRegularidad(string regularidad){regularidad_ = regularidad;};
        inline void setEstado(bool estado){estado_ = estado;}

        
};  

#endif