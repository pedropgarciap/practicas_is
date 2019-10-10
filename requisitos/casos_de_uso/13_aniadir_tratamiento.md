# Añadir tratamiento
**ID**:13 **Descripción**: Se añade un nuevo tratamiento a un paciente determinado.

**Actores principales**: Administrador.

**Precondiciones**:

* El paciente debe existir.

**Flujo principal**:

1. El secretario/a o médico/a desea añadir un nuevo tratamiento a un paciente.
2. El secretario/a o médico/a abre el panel de búsqueda de pacientes.
3. El secretario/a o médico/a busca al paciente en cuestión.
4. El secretario/a o médico/a selecciona al paciente al cual añadir el tratamiento.
5. El secretario/a o médico/a selecciona añadir un nuevo tratamiento.
6. El secretario/a o médico/a añade un nuevo tratamiento.
7. El sistema guarda un nuevo tratamiento en el paciente seleccionado anteriormente.

**Postcondiciones**:

* El sistema guarda un nuevo tratamiento en el paciente anteriormente seleccionado.

**Flujos alternativos**:
  3.a. Si el paciente no existe, se mostrará por pantalla un error.
