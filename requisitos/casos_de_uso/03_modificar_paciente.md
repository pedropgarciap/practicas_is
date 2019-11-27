# Modificar paciente.

**ID:** 03	**Descripción:** Se busca el paciente para posteriormente modificar alguno de sus campos.

**Actores principales:** Administrador

**Precondiciones:**
* Que el paciente se encuentre en la base de datos.
	

**Flujo principal:**
1. El usuario busca un paciente gracias a la funcion buscar paciente.
2. El usuario elige el campo a cambiar.
3. El programa cambia la información deseada.
4. El programa vuelve a guardar la nueva informacion en el fichero.

**Postcondiciones:**
* El programa muestra el usuario con los datos cambiados.

**Flujos relativos:**
* Si el paciente no esta en la base de datos mostrara un mensaje de error.
