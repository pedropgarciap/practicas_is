# Añadir entradas al historial
**ID**:15 **Descripción**: Se añade una nueva entrada al historial de un paciente.

**Actores principales**: Administrador.

**Precondiciones**:

* El paciente debe existir.

**Flujo principal**:

1. El secretario/a o médico/a desea añadir una entrada al historial médico de un paciente.
2. El secretario/a o médico/a abre el panel de búsqueda de pacientes.
3. El secretario/a o médico/a introduce el dni del paciente en cuestión.
4. El secretario/a o médico/a selecciona al paciente deseado.
5. El secretario/a o médico/a selecciona mostrar historial del paciente.
6. El secretario/a o médico/a selecciona introducir una nueva entrada al historial.
7. El secretario/a o médico/a introduce la entrada en cuestión.
8. El sistema guarda la nueva entrada a continuación de la anterior sin modificar las que ya se encuentran en el historial.

**Postcondiciones**:

* El sistema guarda la nueva entrada en el historial médico del paciente.

**Flujos alternativos**:
  3.a. Si el dni del paciente no existe, se mostrará por pantalla un error.
