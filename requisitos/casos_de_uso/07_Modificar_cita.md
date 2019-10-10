# Modificar paciente

**ID:** 07	**Descripción:** Se busca la cita para posteriormente modificar alguno de sus campos.

**Actores Principales:** Administrador

**Precondiciones:**
* Que la cita se encuentre en la base de datos.
	

**Flujo principal:**
1. El usuario busca una cita gracias a la funcion buscar cita.
2. El usuario elige el campo a cambiar.
3. El programa cambia la información deseada.
4. El programa vuelve a guardar la nueva informacion en el fichero.

**Postcondiciones:**
* El programa muestra la cita con los datos cambiados.

**Flujos relativos:**
* Si la cita no esta en la base de datos mostrará un mensaje de error.
m