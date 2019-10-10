# Modificar tratamiento
**ID**:14 **Descripción**: Se modifica un tratamiento de paciente determinado.

**Actores principales**: Administrador.

**Precondiciones**:

* El paciente debe existir.
* El tratamiento no se puede modificar si no existe.

**Flujo principal**:

1. El secretario/a o médico/a desea modificar un tratamiento de un paciente determinado.
2. El secretario/a o médico/a abre el panel de búsqueda de pacientes.
3. El secretario/a o médico/a busca al paciente en cuestión.
4. El secretario/a o médico/a selecciona al paciente al cual modificar el tratamiento.
5. El secretario/a o médico/a selecciona modificar tratamiento.
6. El sistema recoge y guarda los cambios hechos por el secretario/a o médico/a en el tratamiento seleccionado.


**Postcondiciones**:

* El sistema guarda el tratamiento modificado

**Flujos alternativos**:
  3.a. Si el paciente no existe, se mostrará por pantalla un error.
  5.a. Si no existe un tratamiento como mínimo, se mostrará por pantalla un error.
