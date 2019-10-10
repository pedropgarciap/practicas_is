# Eliminar cita
**ID**:10 **Descripción**: Se elimina la cita que se desea por completo.

**Actores principales**: Administrador.

**Precondiciones**:

* La cita debe existir para poder ser eliminada.

**Flujo principal**:

1. El secretario/a o médico/a desea eliminar una cita.
2. El secretario/a o médico/a abre el panel de búsqueda de citas.
3. El secretario/a o médico/a busca la cita que desea eliminar gracias a la función buscar cita.
4. El secretario/a o médico/a selecciona la cita a eliminar.
5. El secretario/a o médico/a acepta el aviso de estar seguro a cerca de la eliminación de la cita.
6. La cita seleccionada es eliminada del sistema.

**Postcondiciones**:

* La cita eliminada no se encuentra en el sistema.

**Flujos alternativos**:
  3.a. Si la cita no existe, se mostrará por pantalla que no se encuentra en el sistema.
  5.a. Si el secretario/a o médico/a se ha equivocado a la hora de seleccionar la cita a borrar, cancelara la eliminación gracias a el aviso de eliminación.
