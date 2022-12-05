#ifndef COORDINADOR_H
#define COORDINADOR_H
#include "usuarios.h"

class Coordinador : public Usuarios {
	public:
        Coordinador(string dni, string nombre, string apellido, string correo_uco, string password) : Usuarios(dni, nombre, apellido, corre_uco, password){};
		//void asignar_recurso();
		//void modificar_cursos();
	private:
};

#endif