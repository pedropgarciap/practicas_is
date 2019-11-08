# Clase: *Pacientes*
## Esta clase contendrá toda la información personal relacionada con los pacientes . Así mismo, sus funciones irán dirigidas tanto al movimiento de los mismos por la base de datos como a su muestra por pantalla, entre otras.

  ### Datos:
    +DNI
     Cadena de carácteres.
      DNI del paciente en cuestión.
    +Nombre
      Cadena de carácteres.
      Nombre del paciente.
    +Apellido
      Cadena de carácteres.
      Ambos apellidos del paciente.
    +CP
      Número.
      Correo postal del paciente.
    +Fecha de nacimiento
      Número.
      Fecha de nacimiento del paciente en cuestión.
    +Teléfono
      Número.
      Teléfono de contacto del paciente.
    +Libre/Seguro
      Cadena de carácteres.
      Indica si el paciente viene de forma libre o por el seguro contratado

### Métodos

    -Añadir_paciente
      Función que permite añadir un nuevo paciente en la base de datos junto con toda su información.
    -Buscar_paciente
      Función que permite encontrar a un paciente en la base de datos solo con introducir el dni del mismo
    -Modificar_paciente
      Función que permite alterar los datos de un paciente determinado.
    -Mostrar_todos
      Función que muestra por pantalla a todos los pacientes de la base de datos.
    -Eliminar_Paciente
      Función que permite eliminar a un paciente de la base de datos junto a toda su información.

# Clase: *Citas*
## Esta clase contendrá toda la información referida a las citas de los pacientes (tanto entrada como salida). Como en la clase pacietne, las funciones relacionadas con esta clase van dirigidas a alterar el estado de las citas o añadir nuevas entre otras.

   ### Datos:
    
      +Fecha_entrada
        Número.
        Fecha a la que entra el paciente a consulta.
      +Fecha_salida
        Número.
        Fecha a la que el paciente deja la consulta.
      +Nombre_paciente
        Cadena de carácteres.
        Nombre del paciente en cuestión.

   ### Métodos
    
      -Añadir_cita
        Función que permite añadir una nueva cita en la base de datos..
      -Buscar_cita
        Función que permite encontrar una cita e un paciente determinado en la base de datos.
      -Modificar_cita
        Función que permite alterar los datos de una cita determinada.
      -Mostrar_citas_hoy
        Función que muestra por pantalla todas las citas del día de hoy.
      -Eliminar_cita
        Función que permite eliminar una cita de la base de datos.

# Clase: *Tratamientos*
## Esta clase contendrá toda la información referida a los tratamientos que un médico receta a un paciente. El tratamiento no es eliminable pero si modificable.

  ### Datos
    +Duración
      Cadena de caractéres
      Duración del tratamiento. La unidad de tiempo la especificará el médico/a o secretario/a.
    +Medicamento
      Cadena de caractéres
      Nombre del medicamento recetado.
    +Dosis
      Número
      Dosis recetada.
    +Regularidad
      Cadena de caractéres
      Frecuencia del tratamiento

  ### Métodos
    -Añadir_tratamiento
      Función que permite añadir un tratamineto nuevo a la base de datos.
    -Modificar_tratamiento
      Función que permite modificar un determinado tratamiento y sus campos.
    -Consultar_tratamiento
      Función que muestra un determinado tratamiento pedido por el secretario/a o médico/a.

# Clase: *Hitorial del Paciente*
## Esta clase contiene información a cerca del motivo de la visita del paciente. No es eliminable pero si modificable.

  ### Datos
    +Motivo
      Cadena de carácteres
      Razón de la cita del paciente
  ### Métodos
    -Mostrar_historial_paciente
      Función que muestra por pantalla el historial completo de un determinado paciente.
    -Añadir_entrada
      Función que permite añadir una nueva entrada al historial del paciente.
