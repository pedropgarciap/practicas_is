#include "sistema.h"
#include "pacientes.h"

using namespace std;

int main(){

    Sistema system;
    
    int sistema = system.addPaciente();

    system.mostrarPacientes();

    return 0;
}