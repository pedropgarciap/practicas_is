#ifndef MENUS_H
#define MENUS_H

/*
Se encarga de controlar todos los diferentes menus que necesita 
el programa para remitir al usuario a las diferentes funciones.
*/

class Menu{

private:
    
public:

    Menu();
    ~Menu();

    int menuPrincipal();
    int submenuModificar();
    int submenuPaciente();
    int submenuTratamientos();
    int submenuHistorial();
    int submenuCitas();
    int submenuModificarTratamientos();
        
};

#endif