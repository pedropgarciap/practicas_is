# Consultar tratamientos de un paciente
**ID**:16 **Descripción**: Se muestran todos los tratamientos de un paciente.

**Actores principales**: Administrador.

**Precondiciones**:

* El paciente debe existir.
* Debe existir como mínimo un tratamiento.

**Flujo principal**:

1. El secretario/a o médico/a desea mostrar los tratamientos de un paciente determinado.
2. El secretario/a o médico/a abre el panel de búsqueda de pacientes.
3. El secretario/a o médico/a introduce el dni del paciente en cuestión.
4. El secretario/a o médico/a selecciona al paciente deseado.
5. El secretario/a o médico/a selecciona mostrar tratamientos.
6. El sistema muestra todos los tratamientos del paciente.

**Postcondiciones**:

* El sistema muestra todos los tratamientos del paciente (tanto los que están e curso como los terminados).

**Flujos alternativos**:
  3.a. Si el dni del paciente no existe, se mostrará por pantalla un error.
  5.a. Si no hay ningun tratamiento, el sistema mostrará un mensaje de que aún no se han introducido tratamientos.
