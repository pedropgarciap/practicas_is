#include <string> 
#include <iostream>
#include <fstream>
#include "tratamientos.h"

/*void Tratamiento::leeTratamiento()
{
    Tratamiento aux;
    tratamientos_.clear(); //Limpia la lista
    char linea[100];
    string nomfich = getDNI() + ".txt";
    ifstream fich(nomfich.c_str());
    if(fich.is_open())
    {
        while (fich.getline(linea,50,','))
	    {
	    	aux.duracion_ = atoi(linea);
	       	fich.getline(linea,50,',');
	       	aux.medicamento_ = linea;
	       	fich.getline(linea,50,',');
	       	aux.dosis_ = linea;
            fich.getline(linea,50,'\n');
	       	aux.regularidad_ = linea;
	       	tratamientos_.push_back(aux);
		}

	    fich.close();
    }
    else
    {
        cout << "No se pudo abrir el fichero" << endl;
    }
} */
