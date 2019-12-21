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
    cout << "BIENVENIDO A PROGECIT, SU PROGRAMA DE GESTION DE CITAS"<< endl;
    cout << "********************************************************************************" << endl;
    cout << endl;

    now = time(0);
    tiempo = localtime(&now);

    leeFichero();
    leeTratamientos();

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

                    cout << "No hay pacientes que mostrar en la base de datos." << endl;

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
            
            cout << "Direccion postal del paciente (Sin introduzca comas): ";
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

                                    cout << "Aqui ira modificar." << endl;

                                    opcion = 0;
                                    break;

                                case 3:

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

        cout << "\nIntroduce el dni del paciente a modificar: ";
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
                        
                        cout << "Introduzca el nombre para modificarlo: ";
                        getline(cin, nombre);
                        cout << endl;

                        aux->setNombre(nombre);

                        opcion = 0;
                        break;

                    case 2:

                        cout << "Introduzca los apellidos para modificarlo: ";
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
    

    cout << "Introduzca la duracion del tratamiento a añadir: ";
    getline(cin, duracion);
    cout << endl;

    cout << "Introduzca la medicación del tratamiento a añadir: ";
    getline(cin, medicacion);
    cout << endl;

    cout << "Introduzca la dosis del tratamiento a añadir: ";
    getline(cin, dosis);
    cout << endl;

    cout << "Introduzca por ultimo la regularidad del tratamiento a añadir: ";
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

                    cout << "Introduzca la duración para modificarla: ";
                    getline(cin, duracion);
                    cout << endl;

                    opcion = 0;
                    break;
                    
                case 2:

                    cout << "Introduzca la medicación para modificarla: ";
                    getline(cin, medicacion);
                    cout << endl;

                    opcion = 0;
                    break;
                            
                case 3:

                    cout << "Introduzca la dosis para modificarla: ";
                    getline(cin, dosis);
                    cout << endl;

                    opcion = 0;
                    break;

                case 4:

                    cout << "Introduzca la regularidad para modificarla: ";
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

                    cout << "Año: " << i->getYear() << endl;
                    cout << "Mes: " << i->getMonth() << endl;
                    cout << "Dia: " << i->getDay() << endl;
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

                    cout << i->getMotivo();

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

            cout << "Introduce el numero del año cuando quieres programar la cita: ";
            cin >> year;
            //getchar();
            cout << endl;

            cout << "Introduce el numero del mes cuando quieres programar la cita: ";
            cin >> month;
            //getchar();
            cout << endl;

            cout << "Introduce el numero del dia del mes cuando quieres programar la cita: ";
            cin >> day;
            //getchar();
            cout << endl;                

            cout << "Introduce la hora a la que quieres programar la cita: ";
            cin >> hora;
            //getchar();
            cout << endl;

            cout << "Introduce los minutos de la hora en la que quieres programar la cita: ";
            cin >> minutos;
            getchar();
            cout << endl;               
            
            while ( (c.setYear(year) == false) || (c.setMonth(month) == false) || (c.setDay(day) == false) || (c.setHora(hora) == false) 
            || (c.setMinutos(minutos) == false) || (comprobarCita(day, month, year, hora, minutos) == true ) || ((year%4 != 0) && (month==2) && (day == 29))
            || (((month==4) || (month==6) || (month==9) || (month==11)) && (day == 31)) || ((month == 2) && (day == 30))){

                cout << "Debido a los siguientes errores tendras que volver a añadir la cita: \n" << endl;

                if ((c.setYear(year) == false) ){cout << "El año ha sido introducido en un rango incorrecto. (Años positivos)" << endl;}
                if ((c.setMonth(month) == false) ){cout << "El mes ha sido introducido en un rango incorrecto. (De 1 a 12)" << endl;}
                if ((c.setDay(day) == false) ){cout << "El dia ha sido introducido en un rango incorrecto. (De 1 a 31)" << endl;}
                if ((c.setHora(hora) == false) ){cout << "El año ha sido introducido en un rango incorrecto. (De)" << endl;}
                if ((c.setMinutos(minutos) == false) ){cout << "El año ha sido introducido en un rango incorrecto." << endl;}
                if ((year%4 != 0) && (month==2) && (day == 29)){ cout << "No hay dia 29 en los meses de febrero de los años no-bisiestos." << endl;}
                if (((month==4) || (month==6) || (month==9) || (month==11)) && (day == 31)){cout << "No hay dia 31 en los meses de Febrero, Abril, Junio, Septiembre y Octubre."
                << endl;}
                if ((month == 2) && (day == 30)){cout << "No hay dia 30 en los meses de Febrero." << endl;}
                if ((comprobarCita(day, month, year, hora, minutos) == true )){cout << "Ya hay una cita programada en la misma fecha y hora." << endl;} 

                cout << endl;

                cout << "Introduce el numero del año cuando quieres programar la cita: ";
                cin >> year;
                //getchar();
                cout << endl;

                cout << "Introduce el numero del mes cuando quieres programar la cita: ";
                cin >> month;
                //getchar();
                cout << endl;

                cout << "Introduce el numero del dia del mes cuando quieres programar la cita: ";
                cin >> day;
                //getchar();
                cout << endl;

                cout << "Introduce la hora a la que quieres programar la cita: ";
                cin >> hora;
                //getchar();
                cout << endl;

                cout << "Introduce los minutos de la hora en la que quieres programar la cita: ";
                cin >> minutos;
                //getchar();
                cout << endl;
            }

            cout << "Introduce ahora el motivo de la visita: " << endl;
            getline(cin, motivo);
            //getchar();
            cout << endl;

            c.setMotivo(motivo);

            c.setDniPaciente(paciente.getDNI());

            citas_.push_front(c);
            paciente.setCitas(c);

            cout << "Cita introducida con éxito." << endl;
        }

//Muestra las citas con fecha igual a la que marca el ordenador
void Sistema::verCitasHoy(){ 

    list <Cita>::iterator i;

    cout << "Sus citas de hoy son las siguientes:" << endl;

    for (i = citas_.begin(); i != citas_.end(); i++){

        if ((i->getDay() == tiempo->tm_mday) && (i->getMonth() == (tiempo->tm_mon)+1) && (i->getYear() == ((tiempo->tm_year)+1900))){

            cout << "Año: " << i->getYear() << endl;

                    cout << "DNI del paciente: " << i->getDniPaciente() << endl;
                    cout << "Mes: " << i->getMonth() << endl;
                    cout << "Dia: " << i->getDay() << endl;
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

                    cout << i->getMotivo();

                    cout << endl;
                    cout << endl;
        }
    }
}

