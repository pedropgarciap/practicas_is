#include "menus.h"
#include <iostream>

using namespace std;

//constructor clase menu
Menu::Menu(){}

//destructor clase menu
Menu::~Menu(){}

//menu principal
int Menu::menuPrincipal(){

    int opcion;

    cout << "\nIntroduzca una de las siguientes opciones:\n";
    cout << "··········································\n";
    cout << "[1] -> Agregar un paciente a la base de datos.\n";
    cout << "[2] -> Buscar paciente por dni.\n";
    cout << "[3] -> Modificar paciente por dni.\n";
    cout << "[4] -> Mostrar todos los pacientes de la base de datos.\n";
    cout << "[5] -> Borrar paciente por dni.\n";
    cout << "\n";

    cout << "[-1] -> SALIR.\n";
    cout << "\n";
    cout << "Su opcion: ";
    cin >> opcion;
    cout << endl;
    getchar();

    return opcion;
}

int Menu::submenuModificar(){

    int opcion;

    cout << "\nIntroduzca la variable a modificar:\n";
    cout << "···································\n";
    cout << "[1] -> Modificar nombre.\n";
    cout << "[2] -> Modificar apellidos.\n";
    cout << "[3] -> Modificar fecha de nacimiento.\n";
    cout << "[4] -> Modificar direccion postal.\n";
    cout << "[5] -> Modificar numero de telefono.\n";
    cout << "[6] -> Modificar seguro.\n";
    cout << "\n";

    cout << "[-1] -> SALIR.\n";
    cout << "\n";
    cout << "Su opcion: ";
    cin >> opcion;
    cout << endl;
    getchar();

    return opcion;
}

int Menu::submenuPaciente(){

    int opcion;

    cout << "\nIntroduzca una de las siguientes opciones:\n";
    cout << "··········································\n";
    cout << "[1] -> Apartado de Tratamientos.\n";
    cout << "[2] -> Apartado de Historial.\n";
    cout << "\n";

    cout << "[-1] -> SALIR.\n";
    cout << "\n";
    cout << "Su opcion: ";
    cin >> opcion;
    cout << endl;
    getchar();

    return opcion;
}

int Menu::submenuTratamientos(){

    int opcion;

    cout << "\nIntroduzca una de las siguientes opciones:\n";
    cout << "··········································\n";
    cout << "[1] -> Añadir tratamiento.\n";
    cout << "[2] -> Modificar tratamiento.\n";
    cout << "[3] -> Ver tratamientos.\n";
    cout << "\n";

    cout << "[-1] -> SALIR.\n";
    cout << "\n";
    cout << "Su opcion: ";
    cin >> opcion;
    cout << endl;
    getchar();

    return opcion;
}

int Menu::submenuModificarTratamientos(){

    int opcion;

    cout << "\nIntroduzca una de las siguientes opciones:\n";
    cout << "··········································\n";
    cout << "[1] -> Modificar duración.\n";
    cout << "[2] -> Modificar medicación.\n";
    cout << "[3] -> Modificar dosis.\n";
    cout << "[4] -> Modificar regularidad.\n";
    cout << "\n";

    cout << "[-1] -> SALIR.\n";
    cout << "\n";
    cout << "Su opcion: ";
    cin >> opcion;
    cout << endl;
    getchar();

    return opcion;
}