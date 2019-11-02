# Consultar citas de un paciente
**ID**:14 **Descripción**: Se consulta las citas de un paciente.

**Actores principales**: Administrador.

**Precondiciones**:

* El paciente debe existir.
* Debe existir como mínimo una cita.

**Flujo principal**:

1. El secretario/a o médico/a desea ver las citas de un paciente.
2. El secretario/a o médico/a abre el panel de búsqueda de pacientes.
3. El secretario/a o médico/a busca al paciente en cuestión introduciendo el DNI.
4. El secretario/a o médico/a selecciona al paciente para ver sus citas.
5. El secretario/a o médico/a selecciona mostrar todas las citas.
6. El sistema muestra todas las citas del paciente, tanto las recientes como las ya finalizadas.


**Postcondiciones**:

* El sistema muestra todas las citas del paciente.

**Flujos alternativos**:
  3.a. Si el paciente no existe, se mostrará por pantalla un error.
  5.a. Si hay una cita como mínimo, se mostrará por pantalla un error.
  
