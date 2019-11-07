## Extracción de requisitos

#### Partes interesadas:
* Doctores
* Secretarios
* Desarrolladores de Software


#### Datos que gestiona el sistema:
* Pacientes
	* Nombre
	* Apellido
	* CP
	* Fecha de nacimiento
	* Telefono
	* Libre/Seguro
* Citas
	* Fecha y hora de entrada
	* Fecha y hora de salida
	* Nombre Paciente
* Tratamientos
	* Duracion
	* Medicamento
	* Dosis
	* Regularidad
* Historial del paciente
	* Motivo de la visita

#### Requisitos funcionales:		
1. Añadir paciente
1. Buscar paciente
1. Modificar paciente
1. Mostrar todos los pacientes
1. Añadir cita
1. Modificar cita
1. Mostrar citas del dia
1. Busqueda de citas
1. Eliminar cita
1. Mostrar historial del paciente
1. Añadir Tratamiento
1. Modificar tratamiento
1. Eliminar paciente (con comprobación)
1. Consultar citas de un paciente
1. Añadir entrada al historial médico
1. Consultar tratamientos de un paciente


#### Requisitos no funcionales
* Sistema operativo Linux
* Interfaz CLI abierta a cambio por una GUI
* Lenguaje de implementación: C++
* Aparentemente no hay límite de almacenamiento (varios teras de memoria)
* Aplicar ley de protección de datos 
* Seguridad ante perdida de datos
