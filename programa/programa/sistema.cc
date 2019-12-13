#include "pacientes.h"
#include "sistema.h"
#include "menus.h"
#include <iostream>
#include <string>
#include <locale.h>
#include <fstream>

using namespace std;

//constructor de la clase sistema que ademas ejecuta el constructor de la clase menu para poder elegir de forma mas ordenada
Sistema::Sistema(){

    cout << endl;
    cout << "********************************************************************************" << endl;
    cout << "BIENVENIDO A SU PLATAFORMA DE GESTION DE DATOS"<< endl;
    cout << "********************************************************************************" << endl;
    cout << endl;

    leeFichero();

    Menu m;
    string nombre, apellidos;

    int opcion = m.menuPrincipal();

    //int error;

    while(opcion != -1){

        switch (opcion){
            
            case 0:

                opcion = m.menuPrincipal();    

                break;

            case 1:
                
                addPaciente(); //especificar errores
                
                opcion = 0;
                break;

            case 2:

                cout << "Introduzca el nombre del paciente a buscar: ";
                getline(cin, nombre);
                cout << endl;

                cout << "Introduzca los apellidos del paciente a buscar: ";
                getline(cin, apellidos);
                cout << endl;

                if (pacientes_.empty()){

                    cout << "No hay pacientes que buscar en la base de datos." << endl;

                    opcion = 0;
                    break;
                }

                else if (!comprobarExistenciaPaciente(nombre, apellidos)){

                    cout << "No existe dicho paciente en la base de datos." << endl;

                    opcion = 0;
                    break;
                }

                buscarPaciente(nombre, apellidos);

                opcion = 0;
                break;
                
                
                /*cout << "Si desea buscar al paciente usando el DNI teclee 1, si desea buscarlo usando el nombre y " <<
                "los apellidos teclee el 2." << endl;

                if (opcion == 1 || opcion == 2){

                    if (opcion == 1){

                        buscarPacienteDNI();
                    
                    }
                }*/

            case 3:

                modificarPaciente();

                opcion = 0;
                break;

            case 4:

                if (pacientes_.empty()){

                    cout << "No hay pacientes que mostrar en la base de datos." << endl;

                    opcion = 0;
                    break;
                }

                mostrarPacientes();
                
                opcion = 0;
                break;

            case 5:

                if (pacientes_.empty()){

                    cout << "No hay pacientes que borrar en la base de datos." << endl;

                    opcion = 0;
                    break;
                }

                borrarPaciente();               

                opcion = 0;
                break;

            default:

                cout << "La opcion elegida no es valida, prueba a elegir una opcion del menu." << endl;
                
                opcion = 0;
                break;
        }
    }    
}

Sistema::~Sistema(){

    cout << endl;
    cout << "********************************************************************************" << endl;
    cout << "PROGRAMA CERRADO" << endl;
    cout << "********************************************************************************" << endl;
    cout << endl;
}

//comprueba gracias al dni si ese paciente ya existe en la lista de pacientes
bool Sistema::comprobarExistenciaPaciente(string dni){

    list <Paciente>::iterator i;
    
    for (i = pacientes_.begin(); i != pacientes_.end(); i++){

            if (i->getDNI() == dni){

                return true;
            }
    }
    
    return false;
}

//comprueba gracias al nombre y a los apellidos si ese paciente ya existe en la lista de pacientes
bool Sistema::comprobarExistenciaPaciente(string nombre, string apellidos){

    list <Paciente>::iterator i;
    
    for (i = pacientes_.begin(); i != pacientes_.end(); i++){

            if ((i->getNombre() == nombre) && (i->getApellidos() == apellidos)){

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

            cout << "Ese DNI ya existe en la base de datos." << endl;
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
            cout << "Introduzca por ultimo el año de nacimiento del paciente: ";
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
            while (opcion != "Salir"){

                if ((seguro == "Si") || (seguro == "No")){

                    opcion = "Salir";
                }

                else{

                    cout << "Parametro incorrecto. Pruebe a introducir Si, si el paciente asiste por el seguro o en su defecto No, si este asiste pagando: ";
                    getline(cin, seguro);
                    cout << endl;
                }
            }

            auxiliar.setSeguroMutua(seguro);

            cout << "\nPARAMETROS INTRODUCIDOS CON EXITO." << endl;
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
    escribeFichero();

    cout << "\nPACIENTE INTRODUCIDO CON EXITO." << endl;
    return 1;
}

//tras comprobar que el paciente existe en la lista itera la lista hasta encontrarlo y lo devuelve
void Sistema::buscarPaciente(string nombre, string apellidos){

    list <Paciente>::iterator i;

    for (i = pacientes_.begin(); i != pacientes_.end(); i++)
    {

        if ( (i->getNombre() == nombre) && (i->getApellidos() == apellidos) ){

            cout << "\nDNI: " << i->getDNI() << endl;
            cout << "Nombre: " << i->getNombre() << endl;
            cout << "Apellidos: " << i->getApellidos() << endl;
            cout << "Fecha de Nacimiento: " << i->getFechaNacimiento() << endl;
            cout << "Direccion Postal: " << i->getDireccionPostal() << endl;
            cout << "Telefono: " << i->getTelefono() << endl;
            cout << "Seguro/Mutua: " <<  i->getSeguroMutua() << endl;
        }
    }
}

Paciente * Sistema::buscaPaciente(string dni){

    list <Paciente>::iterator i;
    
    for (i = pacientes_.begin(); i != pacientes_.end(); i++){

        if (i->getDNI() == dni){

            return &(*i);
        }
    }
}


void Sistema::modificarPaciente(){

    if (pacientes_.empty()){

        cout << "No hay pacientes que modificar." << endl;
    }

    else{

        string dni;

        cout << "\nIntroduce el dni del paciente a modificar: ";
        getline(cin, dni);
        cout << endl;

        if (!comprobarExistenciaPaciente(dni)){

            cout << "No existe dicho paciente." << endl;
        }

        else{

            Menu m;

            Paciente * aux((buscaPaciente(dni)));
            
            string nombre, apellidos, day, month, year, direccionpostal, seguromutua;
            int telefono;

            int opcion = m.submenuModificar();
            string selector;

            while (opcion != -1){

                switch(opcion){

                    case 0:

                        opcion = m.submenuModificar();

                        break;

                    case 1:
                        
                        cout << "Introduzca el nombre para modificarlo: ";
                        getline(cin, nombre);
                        cout << endl;

                        aux->setNombre(nombre);

                        opcion = 0;
                        break;

                    case 2:

                        cout << "Introduzca el apellidos para modificarlo: ";
                        getline(cin, apellidos);
                        cout << endl;

                        aux->setApellidos(apellidos);

                        opcion = 0;
                        break;

                    case 3:
                        
                        cout << "Introduzca el dia para modificarlo: ";
                        getline(cin, day);
                        cout << endl;

                        cout << "Introduzca el dia para modificarlo: ";
                        getline(cin, month);
                        cout << endl;

                        cout << "Introduzca el año para modificarlo: ";
                        getline(cin, year);
                        cout << endl;

                        aux->setFechaNacimiento(day, month, year);

                        opcion = 0;
                        break;

                    case 4:

                        cout << "Introduzca la direccion postal para modificarla: ";
                        getline(cin, direccionpostal);
                        cout << endl;

                        aux->setDireccionPostal(direccionpostal);

                        opcion = 0;
                        break;

                    case 5:

                        cout << "Introduzca el numero de telefono para modificarlo: ";
                        cin >> telefono;
                        cout << endl;
                        
                        //getchar();

                        aux->setTelefono(telefono);

                        opcion = 0;
                        break;

                    case 6:

                        cout << "Introduzca Si, si el paciente asiste por el seguro o en su defecto No, si este asiste pagando: ";
                        getline(cin, seguromutua);
                        cout << endl;


                        while (selector != "Salir"){

                            if ((seguromutua == "Si") || (seguromutua == "No")){

                                selector = "Salir";
                            }

                            else{

                                cout << "Parametro incorrecto. Pruebe a introducir Si, si el paciente asiste por el seguro o en su defecto No, si este asiste pagando: ";
                                getline(cin, seguromutua);
                                cout << endl;
                            }
                        }

                        aux->setSeguroMutua(seguromutua);

                        cout << "\nPARAMETROS INTRODUCIDOS CON EXITO." << endl;

                        opcion = 0;
                        break;

                    default:

                        cout << "Opción no válida. Pruebe a introducir una de las mostradas en el siguiente menu: " << endl;
                        
                        opcion = 0;

                        break;
                }
            }
        }
    }

    escribeFichero();
    cout << "\nVolviendo al menu principal." << endl;
}

void Sistema::escribeFichero(){

    ofstream salida;
    salida.open("pacientes.txt");

    list <Paciente>::iterator i;

    for (i = pacientes_.begin(); i != pacientes_.end(); i++){

        salida << i->getDNI() << "," << i->getNombre() << "," << i->getApellidos() <<
        "," << i->getFechaNacimiento() << "," << i->getDireccionPostal() << "," << i->getTelefono() << "," 
        << i->getSeguroMutua() << "\n";
    }

    salida.close();

}

void Sistema::borrarPaciente(){

    string dni;

    cout << "\nIntroduce el dni del paciente a borrar: ";
    getline(cin, dni);
    cout << endl;

    if (!comprobarExistenciaPaciente(dni)){

        cout << "No existe dicho paciente." << endl;
    }

    else{
        
        list <Paciente>::iterator i;
        string aux;     

        for (i = pacientes_.begin(); i != pacientes_.end(); i++){

            if (i->getDNI() == dni){

                cout << "LOS DATOS DEL PACIENTE ELEGIDO PARA BORRAR SON: " << endl;

                cout << "\nDNI: " << i->getDNI() << endl;
                cout << "Nombre: " << i->getNombre() << endl;
                cout << "Apellidos: " << i->getApellidos() << endl;
                cout << "Fecha de Nacimiento: " << i->getFechaNacimiento() << endl;
                cout << "Direccion Postal: " << i->getDireccionPostal() << endl;
                cout << "Telefono: " << i->getTelefono() << endl;
                cout << "Seguro/Mutua: " <<  i->getSeguroMutua() << endl;    

                cout << "Para confirmar que desea eliminar el paciente con DNI: " << dni << " introduzca su nombre aqui: ";
                getline(cin, aux);

                if (aux == i->getNombre()){

                    i = pacientes_.erase(i);

                    cout << "Paciente borrado con éxito, volviendo al menú." << endl;
                }
                
                else{

                    cout << "Confirmación erronea, volviendo al menú." << endl;
                }
            }
        }

        escribeFichero();
        leeFichero();
    }
}

void Sistema::leeFichero(){

    if (!pacientes_.empty()){

        pacientes_.clear();
    }

    ifstream entrada;
    entrada.open("pacientes.txt");

    char DNI [50];
    char nombre [50];
    char apellidos [50];
    char fechanacimiento [50];
    char direccionpostal [50];
    char telefono [50];
    char seguromutua [50];

    while (entrada.getline(DNI, 256, ',')){

        entrada.getline(nombre, 256, ',');
        entrada.getline(apellidos, 256, ',');
        entrada.getline(fechanacimiento, 256, ',');
        entrada.getline(direccionpostal, 256, ',');
        entrada.getline(telefono, 256, ',');
        entrada.getline(seguromutua, 256, '\n');

        Paciente auxiliar(DNI, nombre, apellidos);
    
        auxiliar.setFechaNacimiento(fechanacimiento);
        auxiliar.setDireccionPostal(direccionpostal);
        auxiliar.setTelefono(atoi(telefono));
        auxiliar.setSeguroMutua(seguromutua);

        pacientes_.push_back(auxiliar);
    } 

    entrada.close();
}


//muestra los datos de todos los pacientes que haya en ese momento en la lista
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

