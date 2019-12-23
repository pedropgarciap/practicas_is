#include "pacientes.h"
#include "sistema.h"
#include "menus.h"
#include "tratamientos.h"
#include "citas.h"
#include <iostream>
#include <string>
#include <locale.h>
#include <fstream>

using namespace std;

//constructor de la clase sistema que ademas ejecuta el constructor de la clase menu para poder elegir de forma mas ordenada
Sistema::Sistema(){

    cout << endl;
    cout << "********************************************************************************" << endl;
    cout << "BIENVENIDO A PROGECIT, SU PROGRAMA DE GESTION DE CITAS Y PACIENTES"<< endl;
    cout << "********************************************************************************" << endl;
    cout << endl;

    now = time(0);
    tiempo = localtime(&now);

    leeFichero();
    leeTratamientos();
    leeCitas();
    leeHistorial();

    Menu m;
    string nombre, apellidos;
    string dni;

    int opcion = m.menuPrincipal();

    //int error;

    while(opcion != -1){

        switch (opcion){
            
            case 0:

                opcion = m.menuPrincipal();    

                break;

            case 1: //Opcion añadir paciente
                
                addPaciente(); //especificar errores
                
                opcion = 0;
                break;

            case 2: //Opcion buscar paciente

                cout << "Introduzca el DNI del paciente a buscar: ";
                getline(cin, dni);
                cout << endl;

                if (pacientes_.empty()){

                    cout << "No hay pacientes que buscar en la base de datos." << endl;

                    opcion = 0;
                    break;
                }

                else if (!comprobarExistenciaPaciente(dni)){

                    cout << "No existe dicho paciente en la base de datos." << endl;

                    opcion = 0;
                    break;
                }

                buscarPaciente(dni);

                opcion = 0;
                break;       

            case 3: //Opcion modificar paciente

                modificarPaciente();

                opcion = 0;
                break;

            case 4: //Opcion mostrar todos los pacientes

                if (pacientes_.empty()){

                    cout << "Actualmente no hay pacientes en la base de datos." << endl;

                    opcion = 0;
                    break;
                }

                mostrarPacientes();
                
                opcion = 0;
                break;

            case 5: //Opcion eliminar paciente

                if (pacientes_.empty()){

                    cout << "No hay pacientes que borrar en la base de datos." << endl;

                    opcion = 0;
                    break;
                }

                borrarPaciente();               

                opcion = 0;
                break;

            case 6:

                verCitasHoy();

                opcion = 0;
                break;

            default: //Si no introduce un numero de los posibles salta este mensaje y vuelve al menu.

                cout << "Opcion no valida, prueba a elegir una opcion del menu." << endl;
                
                opcion = 0;
                break;
        }
    }    
}

Sistema::~Sistema(){

    cout << endl;
    cout << "********************************************************************************" << endl;
    cout << "CERRANDO PROGRAMA. HASTA PRONTO" << endl;
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
/*bool Sistema::comprobarExistenciaPaciente(string nombre, string apellidos){

    list <Paciente>::iterator i;
    
    for (i = pacientes_.begin(); i != pacientes_.end(); i++){

            if ((i->getNombre() == nombre) && (i->getApellidos() == apellidos)){

                return true;
            }
    }
    
    return false;
}*/

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

    cout << "Nombre del paciente: ";
    getline(cin, nombre);
    cout << endl;
    
    string apellidos;

    cout << "Apellidos del paciente: ";
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
            unsigned long int telefono;

            cout << "Dia de nacimiento del paciente: ";
            getline(cin, day);
            cout << endl;
            cout << "Mes de nacimiento del paciente: ";
            getline(cin, month);
            cout << endl;
            cout << "Año de nacimiento del paciente: ";
            getline(cin, year);
            cout << endl;
            auxiliar.setFechaNacimiento(day, month, year);
            
            cout << "Direccion postal del paciente (NO introduzca comas): ";
            getline(cin, direccionpostal);
            cout << endl;
            auxiliar.setDireccionPostal(direccionpostal);

            cout << "Telefono del paciente: ";
            cin >> telefono;
            cout << endl;
            getchar();
            auxiliar.setTelefono(telefono);

            cout << "Por ultimo introduzca Si, si el paciente asiste por el seguro, o No, si este asiste pagando: ";
            getline(cin, seguro);
            cout << endl;
            while (opcion != "Salir"){

                if ((seguro == "Si") || (seguro == "No")){

                    opcion = "Salir";
                }

                else{

                    cout << "Parametro incorrecto. Pruebe a introducir Si, si el paciente asiste por el seguro, o No, si este asiste pagando: ";
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
            cout << "Pruebe a escribir S si desea introducir los demas parametros, o N si no desea introducirlos:" << endl;

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
void Sistema::buscarPaciente(string dni){

    list <Paciente>::iterator i;

    for (i = pacientes_.begin(); i != pacientes_.end(); i++)
    {

        if ( (i->getDNI() == dni)){

            Menu m;

            cout << "\nDNI: " << i->getDNI() << endl;
            cout << "Nombre: " << i->getNombre() << endl;
            cout << "Apellidos: " << i->getApellidos() << endl;
            cout << "Fecha de Nacimiento: " << i->getFechaNacimiento() << endl;
            cout << "Direccion Postal: " << i->getDireccionPostal() << endl;
            cout << "Telefono: " << i->getTelefono() << endl;
            cout << "Seguro/Mutua: " <<  i->getSeguroMutua() << endl;

            int opcion = m.submenuPaciente();

            while(opcion != -1){

                switch (opcion){

                    case 0:

                        opcion = m.submenuPaciente(); 

                        break;

                    case 1:

                        opcion = m.submenuTratamientos();

                        while(opcion != -1){

                            switch (opcion){

                                case 0:

                                    opcion = m.submenuTratamientos(); 
                                    break;

                                case 1:

                                    addTratamiento(*i);
                                                                     
                                    opcion = 0;    
                                    break;

                                case 2:

                                    modificarTratamiento(*i);

                                    opcion = 0;
                                    break;

                                case 3:

                                    mostrarTratamiento(*i);

                                    opcion = 0;
                                    break;

                                default:

                                    cout << "La opcion elegida no es valida, prueba a elegir una opcion del menu." << endl;
                            
                                    opcion = 0;
                                    break;
                            }
                        }             

                        opcion = 0;    
                        break;

                    case 2:

                        opcion = m.submenuHistorial();

                        while(opcion != -1){

                            switch (opcion){

                                case 0:

                                    opcion = m.submenuHistorial(); 
                                    break;

                                case 1:

                                    addHistorial(*i);
                                                                     
                                    opcion = 0;    
                                    break;

                                case 2:

                                    verHistorial(*i);

                                    opcion = 0;
                                    break;

                                default:

                                    cout << "La opcion elegida no es valida, prueba a elegir una opcion del menu." << endl;
                            
                                    opcion = 0;
                                    break;
                            }
                        }    

                        opcion = 0;
                        break;

                    case 3:

                        opcion = m.submenuCitas();

                        while(opcion != -1){

                            switch (opcion){

                                case 0:

                                    opcion = m.submenuCitas(); 
                                    break;

                                case 1:

                                    addCita(*i);
                                                                     
                                    opcion = 0;    
                                    break;

                                case 2:

                                    modificarCita(*i);

                                    opcion = 0;
                                    break;

                                case 3:

                                    borrarCita(*i);

                                    opcion = 0;
                                    break;

                                case 4:

                                    verCitas(*i);

                                    opcion = 0;
                                    break;

                                default:

                                    cout << "La opcion elegida no es valida, prueba a elegir una opcion del menu." << endl;
                            
                                    opcion = 0;
                                    break;
                            }
                        }             

                        opcion = 0;    
                        break;
                        
                    default:

                        cout << "La opcion elegida no es valida, prueba a elegir una opcion del menu." << endl;
                
                        opcion = 0;
                        break;
                }
            }
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

//Modifica uno de los parametros del paciente
void Sistema::modificarPaciente(){

    if (pacientes_.empty()){ //Comprueba que la lista este vacia

        cout << "No hay pacientes que modificar." << endl;
    }

    else{

        string dni;

        cout << "\nIntroduce el DNI del paciente a modificar: ";
        getline(cin, dni);
        cout << endl;

        if (!comprobarExistenciaPaciente(dni)){ //Busca un paciente con ese DNI

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

                switch(opcion){ // Switch con las diferentes opciones del submenu modificar paciente.

                    case 0:

                        opcion = m.submenuModificar();

                        break;

                    case 1:
                        
                        cout << "Introduzca el nuevo nombre: ";
                        getline(cin, nombre);
                        cout << endl;

                        aux->setNombre(nombre);

                        opcion = 0;
                        break;

                    case 2:

                        cout << "Introduzca los nuevos apellidos: ";
                        getline(cin, apellidos);
                        cout << endl;

                        aux->setApellidos(apellidos);

                        opcion = 0;
                        break;

                    case 3:
                        
                        cout << "Introduzca el nuevo dia: ";
                        getline(cin, day);
                        cout << endl;

                        cout << "Introduzca el nuevo mes: ";
                        getline(cin, month);
                        cout << endl;

                        cout << "Introduzca el nuevo año: ";
                        getline(cin, year);
                        cout << endl;

                        aux->setFechaNacimiento(day, month, year);

                        opcion = 0;
                        break;

                    case 4:

                        cout << "Introduzca la nueva direccion postal: ";
                        getline(cin, direccionpostal);
                        cout << endl;

                        aux->setDireccionPostal(direccionpostal);

                        opcion = 0;
                        break;

                    case 5:

                        cout << "Introduzca el nuevo numero de telefono: ";
                        cin >> telefono;
                        cout << endl;
                        
                        //getchar();

                        aux->setTelefono(telefono);

                        opcion = 0;
                        break;

                    case 6:

                        cout << "Introduzca Si, si el paciente asiste por el seguro, o No, si este asiste pagando: ";
                        getline(cin, seguromutua);
                        cout << endl;


                        while (selector != "Salir"){

                            if ((seguromutua == "Si") || (seguromutua == "No")){

                                selector = "Salir";
                            }

                            else{

                                cout << "Parametro incorrecto. Pruebe a introducir Si, si el paciente asiste por el seguro o No, si este asiste pagando: ";
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

//Vuelca al fichero pacientes.txt el nuevo paciente
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

//Vuelca al fichero pacientes.txt el nuevo tratamiento
void Sistema::escribeTratamientos(){

    list <Paciente>::iterator i;

    for (i = pacientes_.begin(); i != pacientes_.end(); i++){

        ofstream salida2;
        salida2.open(i->getDNI()+ "_tratamientos.txt");

        list <Tratamiento> aux = i->getTratamientos();
        list <Tratamiento>::iterator j;

        for (j = aux.begin(); j != aux.end(); j++){
        
            salida2 << j->getDosis() << "," << j->getDuracion() << "," << j->getMedicacion() << ","
            << j->getRegularidad() << "," << j->getEstado() << "\n";
        }
    
        salida2.close();
    }        
}

void Sistema::escribeCitas(){

    ofstream salida;

    salida.open("citas.txt");

    list <Cita> aux = citas_;
    list <Cita>::iterator j;

    for (j = aux.begin(); j != aux.end(); j++){
    
        salida << j->getYear() << "," << j->getMonth() << "," << j->getDay() << ","
        << j->getHora() << "," << j->getMinutos() << "," << j->getDniPaciente() << "\n";
    }

    salida.close();


    list <Paciente>::iterator i;

    for (i = pacientes_.begin(); i != pacientes_.end(); i++){

        ofstream salida2;
        salida2.open(i->getDNI()+ "_citas.txt");

        list <Cita> aux2 = i->getCitas();
        list <Cita>::iterator j;

        for (j = aux2.begin(); j != aux2.end(); j++){
        
            salida2 << j->getYear() << "," << j->getMonth() << "," << j->getDay() << ","
            << j->getHora() << "," << j->getMinutos() << "\n";
        }
    
        salida2.close();
    }
}

void Sistema::escribeHistorial(){
    
    list <Paciente>::iterator i;

    for (i = pacientes_.begin(); i != pacientes_.end(); i++){

        ofstream salida;
        salida.open(i->getDNI()+ "_historial.txt");

        list <Historial> aux = i->getHistorial();
        list <Historial>::iterator j;

        for (j = aux.begin(); j != aux.end(); j++){
        
            salida << j->getYear() << "," << j->getMonth() << "," << j->getDay() << ","
            << j->getHora() << "," << j->getMinutos() << "," << j->getMotivo() << "\n";
        }
    
        salida.close();
    }
}

//Elimina un paciente de la base de datos.
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

                    string nombrefichero;
                    nombrefichero = (dni + "_citas.txt");
                    remove(nombrefichero.c_str());

                    nombrefichero = (dni + "_tratamientos.txt");
                    remove(nombrefichero.c_str());

                    nombrefichero = (dni + "_historial.txt");
                    remove(nombrefichero.c_str());

                    list <Cita>::iterator z;

                    for (z = citas_.begin(); z != citas_.end(); z++)
                    {
                        if (z->getDniPaciente() == dni){

                            z = citas_.erase(z);

                            escribeCitas();
                        }
                    }
                }
                
                else{

                    cout << "Confirmación erronea, volviendo al menú." << endl;
                }
            }
        }

        escribeFichero();
    }
}

//Lee el fichero pacientes y lo carga en la lista
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
        auxiliar.setTelefono(atol(telefono));
        auxiliar.setSeguroMutua(seguromutua);

        pacientes_.push_back(auxiliar);
    } 

    entrada.close();
}

//Lee el fichero tratamientos y lo carga en la lista
void Sistema::leeTratamientos(){

    list <Paciente>::iterator i;

    for (i = pacientes_.begin(); i != pacientes_.end(); i++){

        ifstream entrada;

        entrada.open(i->getDNI() + "_tratamientos.txt");

        char dosis [50];
        char duracion [50];
        char medicacion [50];
        char regularidad [50];
        char estado [50];

        while (entrada.getline(dosis, 256, ',')){

            entrada.getline(duracion, 256, ',');
            entrada.getline(medicacion, 256, ',');
            entrada.getline(regularidad, 256, ',');
            entrada.getline(estado, 256, '\n');

            Tratamiento auxiliar(dosis, duracion, medicacion, regularidad);
            auxiliar.setEstado(stoi(estado));

            i->setTratamientosAtras(auxiliar);
        }
        
        entrada.close(); 
    }
}

void Sistema::leeCitas(){

    ifstream entrada;

    entrada.open("citas.txt");

    char year [50];
    char month [50];
    char day [50];
    char hora [50];
    char minutos [50];
    char dni [50];

    while (entrada.getline(year, 256, ',')){

        entrada.getline(month, 256, ',');
        entrada.getline(day, 256, ',');
        entrada.getline(hora, 256, ',');
        entrada.getline(minutos, 256, ',');
        entrada.getline(dni, 256, '\n');

        Cita auxiliar;

        auxiliar.setYear(atoi(year));
        auxiliar.setMonth(atoi(month));
        auxiliar.setDay(atoi(day));
        auxiliar.setHora(atoi(hora));
        auxiliar.setMinutos(atoi(minutos));
        auxiliar.setDniPaciente(dni);

        citas_.push_back(auxiliar);
    }
    
    entrada.close(); 

    list <Paciente>::iterator i;

    for (i = pacientes_.begin(); i != pacientes_.end(); i++){

        ifstream entrada2;

        entrada2.open(i->getDNI() + "_citas.txt");

        char year2 [50];
        char month2 [50];
        char day2 [50];
        char hora2 [50];
        char minutos2 [50];

        while (entrada2.getline(year2, 256, ',')){

            entrada2.getline(month2, 256, ',');
            entrada2.getline(day2, 256, ',');
            entrada2.getline(hora2, 256, ',');
            entrada2.getline(minutos2, 256, '\n');

            Cita auxiliar2;

            auxiliar2.setYear(atoi(year2));
            auxiliar2.setMonth(atoi(month2));
            auxiliar2.setDay(atoi(day2));
            auxiliar2.setHora(atoi(hora2));
            auxiliar2.setMinutos(atoi(minutos2));
            auxiliar2.setDniPaciente(i->getDNI());

            i->setCitas(auxiliar2);
        }
        
        entrada2.close(); 
    }
}

void Sistema::leeHistorial(){

    list <Paciente>::iterator i;

    for (i = pacientes_.begin(); i != pacientes_.end(); i++){

        ifstream entrada;

        entrada.open(i->getDNI() + "_historial.txt");

        char year [50];
        char month [50];
        char day [50];
        char hora [50];
        char minutos [50];
        char motivo [256];

        while (entrada.getline(year, 256, ',')){

            entrada.getline(month, 256, ',');
            entrada.getline(day, 256, ',');
            entrada.getline(hora, 256, ',');
            entrada.getline(minutos, 256, ',');
            entrada.getline(motivo, 256, '\n');
    

            Historial auxiliar;

            auxiliar.setYear(atoi(year));
            auxiliar.setMonth(atoi(month));
            auxiliar.setDay(atoi(day));
            auxiliar.setHora(atoi(hora));
            auxiliar.setMinutos(atoi(minutos));
            auxiliar.setMotivo(motivo);
            auxiliar.setDniPaciente(i->getDNI());

            i->setHistorial(auxiliar);
        }
        
        entrada.close(); 
    }
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

//Añade un nuevo tratamiento y el anterior pasa a estado obsoleto
void Sistema::addTratamiento(Paciente & paciente){

    string duracion, medicacion, dosis, regularidad;
    

    cout << "Duracion del tratamiento: ";
    getline(cin, duracion);
    cout << endl;

    cout << "Medicación del tratamiento: ";
    getline(cin, medicacion);
    cout << endl;

    cout << "Dosis del tratamiento: ";
    getline(cin, dosis);
    cout << endl;

    cout << "Regularidad del tratamiento: ";
    getline(cin, regularidad);
    cout << endl;

    Tratamiento aux(duracion, medicacion, dosis, regularidad);
    aux.setEstado(true);

    list <Tratamiento>::iterator i;
    list <Tratamiento> & auxiliar = paciente.getTratamientos();

    for (i = auxiliar.begin(); i != auxiliar.end(); i++)
    {
        i->setEstado(false);
    }

    paciente.setTratamientos(aux);

    escribeTratamientos();
}

//Cambia alguno de los parametros del tratamiento y lo escribe como uno nuevo
void Sistema::modificarTratamiento(Paciente &paciente){

    if ((paciente.getTratamientos()).empty()){

        cout << "Este paciente no tiene tratamientos que modificar." << endl;
    }

    else{
        
        Menu m;

        string duracion, medicacion, dosis, regularidad;

        list <Tratamiento>::iterator i;
        list <Tratamiento> auxiliar = paciente.getTratamientos();

        i = auxiliar.begin();

        dosis = i->getDosis();
        duracion = i->getDuracion();
        medicacion = i->getMedicacion();
        regularidad = i->getRegularidad();

        int opcion = m.submenuModificarTratamientos();

        while(opcion != -1){

            switch (opcion){
                
                case 0:

                    opcion = m.submenuModificarTratamientos();
                    
                    break;

                case 1:

                    cout << "Introduzca la nueva duración: ";
                    getline(cin, duracion);
                    cout << endl;

                    opcion = 0;
                    break;
                    
                case 2:

                    cout << "Introduzca la nueva medicación: ";
                    getline(cin, medicacion);
                    cout << endl;

                    opcion = 0;
                    break;
                            
                case 3:

                    cout << "Introduzca la nueva dosis: ";
                    getline(cin, dosis);
                    cout << endl;

                    opcion = 0;
                    break;

                case 4:

                    cout << "Introduzca la nueva regularidad: ";
                    getline(cin, regularidad);
                    cout << endl;

                    opcion = 0;
                    break;  

                default:

                    cout << "Opción incorrecta, prueba a elegir una opción del menú." << endl;

                    opcion = 0;
                    break;
            }
        }

        Tratamiento aux(duracion, medicacion, dosis, regularidad);
        aux.setEstado(true);

        list <Tratamiento>::iterator j;
        list <Tratamiento> & auxiliar2 = paciente.getTratamientos();

        for (j = auxiliar2.begin(); j != auxiliar2.end(); j++){
                
            j->setEstado(false);
        }

        paciente.setTratamientos(aux);

        escribeTratamientos();
    }
}
    

    
//Muestra todos los tratamientos de un paciente
void Sistema::mostrarTratamiento(Paciente & paciente){

    if ((paciente.getTratamientos()).empty()){

        cout << "Este paciente no tiene tratamientos que modificar." << endl;
    }

    else{

        list <Tratamiento>::iterator i;
        list <Tratamiento> aux = paciente.getTratamientos();

        string booleano;    

        for (i = aux.begin(); i != aux.end(); i++){

            cout << "\nDosis: " << i->getDosis() << endl;
            cout << "Duración: " << i->getDuracion() << endl;
            cout << "Medicación: " << i->getMedicacion() << endl;
            cout << "Regularidad: " << i->getRegularidad() << endl;

            if (i->getEstado() == true){

            booleano = "Tratamiento Vigente";
            }

            else if(i->getEstado() == false) {
                
                booleano = "Tratamiento Anterior";
            }

            cout << "Estado: " << booleano << endl;

        }
        
        cout << "\nTRATAMIENTOS MOSTRADOS CON EXITO." << endl;
    }
}

//Comprueba que la fecha y hora de cita que se introduce no exista ya en la base de datos
bool Sistema::comprobarCita(int day, int month, int year, int hora, int minutos){

            list <Cita>::iterator i;

            for (i = citas_.begin(); i != citas_.end(); i++){

                if ((i->getYear() == year) && (i->getMonth() == month) && (i->getDay() == day) && (i->getHora() == hora) && (i->getMinutos() == minutos)){

                    return true;
                }
            }
            
            return false;
}

//Muestra las citas de un paciente pedido
void Sistema::verCitas(Paciente & paciente){

    list <Cita> aux = paciente.getCitas();

            if (aux.empty()){

                cout << "No hay citas que mostrar.\n" << endl;
            } 
        
            else{
                
                list <Cita>::iterator i;
            
                cout << "Citas de: " << paciente.getNombre() << " " << paciente.getApellidos() << endl;
                cout << endl;

                for (i = aux.begin(); i != aux.end(); i++){ 

                    cout << "Fecha: " << i->getYear() << "/" << i->getMonth() << "/" << i->getDay() << endl;
                    cout << "Hora: ";

                    cout.fill('0');
                    cout.width(2);
                    cout << i->getHora();

                    cout << ":";

                    cout.fill('0');
                    cout.width(2);
                    cout << i->getMinutos();

                    cout << endl;
                    cout << endl;
                }
            } 
}

// Añade una cita pidiendo al usuario los datos de esta
void Sistema::addCita(Paciente & paciente){

    Cita c;
    int day, month, year, hora, minutos;
    string motivo;

    cout << "Año cuando quieres programar la cita: ";
    cin >> year;
    //getchar();
    cout << endl;

    cout << "Mes cuando quieres programar la cita: ";
    cin >> month;
    //getchar();
    cout << endl;

    cout << "Dia del mes cuando quieres programar la cita: ";
    cin >> day;
    //getchar();
    cout << endl;                

    cout << "Hora a la que quieres programar la cita: ";
    cin >> hora;
    //getchar();
    cout << endl;

    cout << "Minutos de la hora en la que quieres programar la cita: ";
    cin >> minutos;
    //getchar();
    cout << endl;               
    
    while ( (c.setYear(year) == false) || (c.setMonth(month) == false) || (c.setDay(day) == false) || (c.setHora(hora) == false) 
    || (c.setMinutos(minutos) == false) || (comprobarCita(day, month, year, hora, minutos) == true ) || ((year%4 != 0) && (month==2) && (day == 29))
    || (((month==4) || (month==6) || (month==9) || (month==11)) && (day == 31)) || ((month == 2) && (day == 30))){

        cout << "Debido a los siguientes errores tendras que volver a añadir la cita: \n" << endl;

        if ((c.setYear(year) == false) ){cout << "El año ha sido introducido en un rango incorrecto. (Años positivos)" << endl;}
        if ((c.setMonth(month) == false) ){cout << "El mes ha sido introducido en un rango incorrecto. (De 1 a 12)" << endl;}
        if ((c.setDay(day) == false) ){cout << "El dia ha sido introducido en un rango incorrecto. (De 1 a 31)" << endl;}
        if ((c.setHora(hora) == false) ){cout << "La hora ha sido introducida en un rango incorrecto. (De 0 a 23)" << endl;}
        if ((c.setMinutos(minutos) == false) ){cout << "Los minutos han sido introducidos en un rango incorrecto. (De 0 a 59)" << endl;}
        if ((year%4 != 0) && (month==2) && (day == 29)){ cout << "No hay dia 29 en los meses de febrero de los años no-bisiestos." << endl;}
        if (((month==4) || (month==6) || (month==9) || (month==11)) && (day == 31)){cout << "No hay dia 31 en los meses de Febrero, Abril, Junio, Septiembre y Octubre."
        << endl;}
        if ((month == 2) && (day == 30)){cout << "No hay dia 30 en los meses de Febrero." << endl;}
        if ((comprobarCita(day, month, year, hora, minutos) == true )){cout << "Ya hay una cita programada en la misma fecha y hora." << endl;} 

        cout << endl;

        cout << "Año cuando quieres programar la cita: ";
        cin >> year;
        //getchar();
        cout << endl;

        cout << "Mes cuando quieres programar la cita: ";
        cin >> month;
        //getchar();
        cout << endl;

        cout << "Dia del mes cuando quieres programar la cita: ";
        cin >> day;
        //getchar();
        cout << endl;

        cout << "Hora a la que quieres programar la cita: ";
        cin >> hora;
        //getchar();
        cout << endl;

        cout << "Minutos de la hora en la que quieres programar la cita: ";
        cin >> minutos;
        //getchar();
        cout << endl;
    }

    c.setDniPaciente(paciente.getDNI());

    citas_.push_front(c);
    paciente.setCitas(c);

    cout << "Cita introducida con éxito." << endl;

    escribeCitas();
}

bool Sistema::buscaCita(Paciente paciente, int day, int month, int year, int hora, int minutos){

    list <Cita>::iterator i;
    list <Cita> aux = paciente.getCitas();

        for (i = aux.begin(); i != aux.end(); i++){

            if ((i->getYear() == year) && (i->getMonth() == month) && (i->getDay() == day) && 
            (i->getHora() == hora) && (i->getMinutos() == minutos)){

                return true;
            }
        }

    return false;
}

void Sistema::modificarCita(Paciente & paciente){

    list <Cita> & aux = paciente.getCitas();

    if (aux.empty()){

        cout << "El paciente no tiene citas que modificar." << endl;
    }  

    int day, month, year, hora, minutos;

    cout << "Introduce el año de la cita que quieres modificar: ";
    cin >> year;
    //getchar();
    cout << endl;

    cout << "Introduce el mes de la cita que quieres modificar: ";
    cin >> month;
    //getchar();
    cout << endl;

    cout << "Introduce el dia de la cita que quieres modificar: ";
    cin >> day;    
    //getchar();
    cout << endl;        

    cout << "Introduce la hora de la cita que quieres modificar: ";
    cin >> hora;
    //getchar();
    cout << endl;

    cout << "Introduce los minutos de la cita que quieres modificar: ";
    cin >> minutos;
    //getchar();
    cout << endl;

    if (!buscaCita(paciente, day, month, year, hora, minutos)){

        cout << "No existe dicha cita en la base de datos." << endl;
    }

    else{

        Cita c;
        int day2, month2, year2, hora2, minutos2;

        cout << "\nModificación de la cita:\n";
        cout << "··········································\n";

        cout << "Año cuando quieres programar la cita: ";
        cin >> year2;
        //getchar();
        cout << endl;

        cout << "Mes cuando quieres programar la cita: ";
        cin >> month2;
        //getchar();
        cout << endl;

        cout << "Dia del mes cuando quieres programar la cita: ";
        cin >> day2;
        //getchar();
        cout << endl;                

        cout << "Hora a la que quieres programar la cita: ";
        cin >> hora2;
        //getchar();
        cout << endl;

        cout << "Minutos de la hora en la que quieres programar la cita: ";
        cin >> minutos2;
        //getchar();
        cout << endl;               
        
        while ( (c.setYear(year2) == false) || (c.setMonth(month2) == false) || (c.setDay(day2) == false) || (c.setHora(hora2) == false) 
        || (c.setMinutos(minutos2) == false) || (comprobarCita(day2, month2, year2, hora2, minutos2) == true ) || (((year2)%4 != 0) && (month2==2) && (day2 == 29))
        || (((month2==4) || (month2==6) || (month2==9) || (month2==11)) && (day2 == 31)) || ((month2 == 2) && (day2 == 30))){

            cout << "Debido a los siguientes errores tendras que volver a modificar la cita: \n" << endl;

            if ((c.setYear(year2) == false) ){cout << "El año ha sido introducido en un rango incorrecto. (Años positivos)" << endl;}
            if ((c.setMonth(month2) == false) ){cout << "El mes ha sido introducido en un rango incorrecto. (De 1 a 12)" << endl;}
            if ((c.setDay(day2) == false) ){cout << "El dia ha sido introducido en un rango incorrecto. (De 1 a 31)" << endl;}
            if ((c.setHora(hora2) == false) ){cout << "La hora ha sido introducida en un rango incorrecto. (De 0 a 23)" << endl;}
            if ((c.setMinutos(minutos2) == false) ){cout << "Los minutos han sido introducidos en un rango incorrecto. (De 0 a 59)" << endl;}
            if (((year2)%4 != 0) && (month2==2) && (day2 == 29)){ cout << "No hay dia 29 en los meses de febrero de los años no-bisiestos." << endl;}
            if (((month2==4) || (month2==6) || (month2==9) || (month2==11)) && (day2 == 31)){cout << "No hay dia 31 en los meses de Febrero, Abril, Junio, Septiembre y Octubre."
            << endl;}
            if ((month2 == 2) && (day2 == 30)){cout << "No hay dia 30 en los meses de Febrero." << endl;}
            if ((comprobarCita(day2, month2, year2, hora2, minutos2) == true )){cout << "Ya hay una cita programada en la misma fecha y hora." << endl;} 

            cout << endl;

            cout << "Año cuando quieres programar la cita: ";
            cin >> year2;
            //getchar();
            cout << endl;

            cout << "Mes cuando quieres programar la cita: ";
            cin >> month2;
            //getchar();
            cout << endl;

            cout << "Dia del mes cuando quieres programar la cita: ";
            cin >> day2;
            //getchar();
            cout << endl;

            cout << "Hora a la que quieres programar la cita: ";
            cin >> hora2;
            //getchar();
            cout << endl;

            cout << "Minutos de la hora en la que quieres programar la cita: ";
            cin >> minutos2;
            //getchar();
            cout << endl;
        }

        c.setDniPaciente(paciente.getDNI());

        list <Cita>::iterator i;

        for (i = aux.begin(); i != aux.end(); i++){

            if ((i->getYear() == year) && (i->getMonth() == month) && (i->getDay() == day) && 
            (i->getHora() == hora) && (i->getMinutos() == minutos)){

                i->setYear(year2);
                i->setMonth(month2);
                i->setDay(day2);
                i->setHora(hora2);
                i->setMinutos(minutos2);
                i->setDniPaciente(paciente.getDNI());
            }
        }

        list <Cita>::iterator j;

        for (j = citas_.begin(); j != citas_.end(); j++){   
            
            if ((j->getYear() == year) && (j->getMonth() == month) && (j->getDay() == day) && 
            (j->getHora() == hora) && (j->getMinutos() == minutos)){

                j->setYear(year2);
                j->setMonth(month2);
                j->setDay(day2);
                j->setHora(hora2);
                j->setMinutos(minutos2);
                j->setDniPaciente(paciente.getDNI());
            }
        }

        cout << "Cita modificada con éxito." << endl;
    }

    escribeCitas();
}

void Sistema::borrarCita(Paciente & paciente){

    list <Cita> & aux = paciente.getCitas();

    if (aux.empty()){

        cout << "El paciente no tiene citas que borrar." << endl;
    }  

    int day, month, year, hora, minutos;

    cout << "Año de la cita que quieres borrar: ";
    cin >> year;
    //getchar();
    cout << endl;

    cout << "Mes de la cita que quieres borrar: ";
    cin >> month;
    //getchar();
    cout << endl;

    cout << "Dia de la cita que quieres borrar: ";
    cin >> day;    
    //getchar();
    cout << endl;        

    cout << "Hora de la cita que quieres borrar: ";
    cin >> hora;
    //getchar();
    cout << endl;

    cout << "Minutos de la cita que quieres borrar: ";
    cin >> minutos;
    //getchar();
    cout << endl;

    if (!buscaCita(paciente, day, month, year, hora, minutos)){

        cout << "No existe dicha cita en la base de datos." << endl;
    }

    else{

        list <Cita>::iterator i;

        for (i = aux.begin(); i != aux.end(); i++){

            if ((i->getYear() == year) && (i->getMonth() == month) && (i->getDay() == day) && 
            (i->getHora() == hora) && (i->getMinutos() == minutos)){

                i = aux.erase(i);
            }
        }

        list <Cita>::iterator j;

        for (j = citas_.begin(); j != citas_.end(); j++){   
            
            if ((j->getYear() == year) && (j->getMonth() == month) && (j->getDay() == day) && 
            (j->getHora() == hora) && (j->getMinutos() == minutos)){

                j = aux.erase(j);
            }
        }

        cout << "Cita borrada con éxito de la base de datos." << endl;
    }

    escribeCitas();
}

//Muestra las citas con fecha igual a la que marca el ordenador
void Sistema::verCitasHoy(){ 

    if (citas_.empty()){

        cout << "No hay citas que mostrar en la base de datos." << endl;
    }

    else{

        int contador=0;

        list <Cita>::iterator i;

        cout << "Sus citas de hoy son las siguientes:\n" << endl;

        for (i = citas_.begin(); i != citas_.end(); i++){

            if ((i->getDay() == tiempo->tm_mday) && (i->getMonth() == (tiempo->tm_mon)+1) && (i->getYear() == ((tiempo->tm_year)+1900))){

                contador++;
                cout << "DNI del paciente: " << i->getDniPaciente() << endl;
                

                cout << "Fecha: " << i->getYear() << "/" << i->getMonth() << "/" << i->getDay() << endl;
                cout << "Hora: ";

                cout.fill('0');
                cout.width(2);
                cout << i->getHora();

                cout << ":";

                cout.fill('0');
                cout.width(2);
                cout << i->getMinutos();

                cout << endl;
                cout << endl;
            }
        }
        if (contador == 0){

            cout << "Hoy no hay citas programadas." << endl;
        }
    }
}


void Sistema::addHistorial(Paciente & paciente){

    now = time(0);
    tiempo = localtime(&now);

    Historial c;

    string motivo;
    cout << "Introduce el motivo de la visita: " << endl;
    getline(cin, motivo);
    cout << endl;

    c.setMotivo(motivo);

    c.setDay(tiempo->tm_mday);
    c.setMonth((tiempo->tm_mon)+1);
    c.setYear((tiempo->tm_year)+1900);
    c.setHora(tiempo->tm_hour);
    c.setMinutos(tiempo->tm_min);
    c.setDniPaciente(paciente.getDNI());

    paciente.setHistorial(c);

    cout << "Entrada en el historial introducida con éxito." << endl;

    escribeHistorial();
}

void Sistema::verHistorial(Paciente & paciente){

    list <Historial>::iterator i;
    list <Historial> & aux = paciente.getHistorial();

    if (aux.empty()){

        cout << "El historial está vacio." << endl;
    } 

    else{

        for (i = aux.begin(); i != aux.end(); i++){

            cout << "Fecha de entrada en el historial: " << i->getDay() << "/" 
            << i->getMonth() << "/" << i->getYear() << endl;
            cout << "Hora: ";

            cout.fill('0');
            cout.width(2);

            cout << i->getHora();

            cout << ":";

            cout.fill('0');
            cout.width(2);

            cout << i->getMinutos();

            cout << endl;

            cout << "Motivo de la visita: \n" << endl;
            cout << i->getMotivo(); 

            cout << endl;
        }

        cout << "Historial mostrado con éxito." << endl;
    }    
}