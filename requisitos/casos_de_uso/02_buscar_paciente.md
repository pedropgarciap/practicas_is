# Buscar paciente por DNI.

**ID:** 02	**Descripción:** Se introduce el DNI del paciente a buscar y el programa lo busca en la base de datos.

**Actores principales:** Administrador

**Precondiciones:**
* Debe existir el paciente en la base de datos.

**Flujo principal:**
	1. El usuario desea buscar un paciente.
	2. Selecciona la opción buscar paciente por DNI.
	3. El usuario introduce el DNI.
	4. El programa compara el DNI introducido con todos los registrados.
	5. El programa muestra por pantalla todos los datos del paciente.

**Postcondiciones:**
* Se muestran al usuario todas las opciones disponibles a continuación.

**Flujos relativos:**
* Si el paciente no esta en la base de datos mostrara un mensaje de error.

