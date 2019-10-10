# Buscar historial del paciente
**ID**:12 **Descripción**: Se busca y muestra el historial completo de un paciente determinado.

**Actores principales**: Administrador.

**Precondiciones**:

* El administrador del cual queremos saber su historial debe existir.

**Flujo principal**:

1. El secretario/a o médico/a desea buscar el historial médico de un paciente determinado.
2. El secretario/a o médico/a abre el panel de búsqueda de pacientes.
3. El secretario/a o médico/a busca al paciente determinado.
4. El secretario/a o médico/a selecciona el paciente determinado.
5. El sistema muestra la información del paciente, incluyendo su historial.

**Postcondiciones**:

* El historial del paciente se muestra por pantalla junto a la demás información del paciente.

**Flujos alternativos**:
  3.a. Si el paciente no existe, se mostrará por pantalla un error.
