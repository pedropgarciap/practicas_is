#include "pacientes.h"
#include "sistema.h"
#include <iostream>
#include <string>

using namespace std;

bool Sistema::comprobarExistenciaPaciente(string dni){

    list <Paciente>::iterator i;
    
    for (i = pacientes_.begin(); i != pacientes_.end(); i++){

            if (i->getDNI() == dni){

                return true;
            }
    }
    
    return false;
}

//devuelve -1 si no se puede agregar y 1 si ha sido agregado con exito
int Sistema::addPaciente(){ 

    string dni;

    cout << "Introduzca el DNI del paciente a agregar: ";
    getline(cin, dni);
    cout << endl;

    if (!pacientes_.empty()){

        if (comprobarExistenciaPaciente(dni)){

            return -1;
        } 
    } 

    string nombre;

    cout << "Introduzca ahora el nombre del paciente: ";
    getline(cin, nombre);
    cout << endl;
    
    string apellidos;

    cout << "Continue introduciendo los apellidos del paciente: ";
    getline(cin, apellidos);
    cout << endl;

    Paciente auxiliar(dni, nombre, apellidos);

    string opcion;

    cout << "Los parametros por defecto han sido introducidos correctamente." << endl;
    cout << "Escriba S (Si) para seguir introduciendo los demas parametros, o N (No) si no desea introducir " <<
    "mas parametros del paciente:" << endl;
    getline(cin, opcion);
    cout << endl;
    
    while (opcion != "Salir"){

        if (opcion == "S"){

            string day, month, year, direccionpostal, seguro;
            int telefono;

            cout << "Introduzca el dia de nacimiento del paciente: ";
            getline(cin, day);
            cout << endl;
            cout << "Introduzca ahora el mes de nacimiento del paciente: ";
            getline(cin, month);
            cout << endl;
            cout << "Introduzca por ultimo el a"<< char(-92) << "o de nacimiento del paciente: ";
            getline(cin, year);
            cout << endl;
            auxiliar.setFechaNacimiento(day, month, year);
            
            cout << "Introduzca ahora la direccion postal del paciente: ";
            getline(cin, direccionpostal);
            cout << endl;
            auxiliar.setDireccionPostal(direccionpostal);

            cout << "Introduzca ahora el telefono del paciente: ";
            cin >> telefono;
            cout << endl;
            getchar();
            auxiliar.setTelefono(telefono);

            cout << "Por ultimo introduzca Si, si el paciente asiste por el seguro o en su defecto No, si este asiste pagando: ";
            getline(cin, seguro);
            cout << endl;
            auxiliar.setSeguroMutua(seguro);
            
            cout << "\nPARAMETROS INTRODUCIDOS CON EXITO." << endl;
            opcion = "Salir";
        }

        else if (opcion == "N"){

            cout << "\nVOLVIENDO AL MENU." << endl;
            opcion = "Salir";
        }

        else {

            cout << "La opcion elegida no es valida." << endl;
            cout << "Pruebe a escribir S si desea introducir los demas parametros, o N si en su defecto no desea introducirlos:" << endl;

            getline(cin, opcion);
            cout << endl;
        }
    }
    
    pacientes_.push_back(auxiliar);
    
    cout << "\nPACIENTE INTRODUCIDO CON EXITO." << endl;
    return 1;
}

void Sistema::mostrarPacientes(){

    list <Paciente>::iterator i;

    for (i = pacientes_.begin(); i != pacientes_.end(); i++)
    {
        cout << "\nDNI: " << i->getDNI() << endl;
        cout << "Nombre: " << i->getNombre() << endl;
        cout << "Apellidos: " << i->getApellidos() << endl;
        cout << "Fecha de Nacimiento: " << i->getFechaNacimiento() << endl;
        cout << "Direccion Postal: " << i->getDireccionPostal() << endl;
        cout << "Telefono: " << i->getTelefono() << endl;
        cout << "Seguro/Mutua: " <<  i->getSeguroMutua() << endl;
    }
    
    cout << "\nPACIENTES MOSTRADOS CON EXITO." << endl;
}

