/*
 * alumnos.h
 *
 *  Autores: i12cofem e i82gavaj
 *  Fecha inicio del proyecto: 23/11/2022
 *  Fecha finalización del proyecto: 06/12/2022.
 *
 *
 *
 */
/*
 * En este fichero vamos a tener la definición de la clase Alumnos (hereda de Usuarios), con sus respectivos atributos y métodos
 *
 *
 *
 *
 *
 * */



#ifndef ALUMNOS_H
#define ALUMNOS_H

#include "usuarios.h"
#include "cursos.h"

class Alumnos: public Usuarios{
	public:

        Alumnos(string dni = "", string nombre="empty", string apellido="empty", string correo_uco="empty", string password="empty") : Usuarios(dni, nombre, apellido, correo_uco, password){};

		void inscribirse(Cursos curso1, Alumnos Alumno1);//era bool


	private:
};



#endif
