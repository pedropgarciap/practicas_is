#ifndef PACIENTES_H
#define PACIENTES_H

#include <string>
#include <list>

using namespace std;

class Paciente{

private:

string dni_;
string nombre_;
string apellidos_;
string fechanacimiento_;
string direccionpostal_;
int telefono_;
string seguromutua_;

public:

    Paciente(string dni, string nombre, string apellidos, string fechanacimiento = "XX/XX/XXXX", string direccionpostal = "",
    int telefono = 000000000 , string seguromutua = "");   

    //OBSERVADORES
    inline string getDNI(){return dni_;};
    inline string getNombre(){return nombre_;};
    inline string getApellidos(){return apellidos_;};
    inline string getFechaNacimiento(){return fechanacimiento_;};
    inline string getDireccionPostal(){return direccionpostal_;};
    inline int getTelefono(){return telefono_;};
    inline string getSeguroMutua(){return seguromutua_;};

    //MODIFICADORES
    inline void setDNI(string dni){dni_ = dni;}; 
    inline void setNombre(string nombre){nombre_ = nombre;};
    inline void setApellidos(string apellidos){apellidos_ = apellidos;};
    inline void setFechaNacimiento(string day, string month, string year){fechanacimiento_ = day+"/"+month+"/"+year;};
    inline void setFechaNacimiento(string fechanacimiento){fechanacimiento_ = fechanacimiento;};
    inline void setDireccionPostal(string direccionpostal){direccionpostal_ = direccionpostal;};
    inline void setTelefono(int telefono){telefono_ = telefono;};
    inline void setSeguroMutua(string seguromutua){seguromutua_ = seguromutua;};    
};

#endif