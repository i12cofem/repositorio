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