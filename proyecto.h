#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>

using namespace std;

#ifndef CURSO_H
#define	CURSO_Hola




class Usuarios{

	private:
		string dni_;
		string nombre_;
		string apellido_;
		string correo_uco_;
		string password_;

	public:

		Usuarios(string dni, string nombre, string apellido, string correo_uco, string password);

		void ver_admin();
		void mostrar_cursos();
		void estadisticas();

};


class Alumnos: public Usuarios{
	public:

		bool login();
		bool inscribirse();


	private:
};

class Admin : public Usuarios{
	public:

		list<string> mostrar_usuarios();
		void eliminar_usuario();
		void añadir_curso();
		bool comprobar_curso();
		bool borrar_curso();
		string listar_cursos();
		void estadisticas();

	private:
};

class Coordinador : public Usuarios {
	public:



};



#endif
