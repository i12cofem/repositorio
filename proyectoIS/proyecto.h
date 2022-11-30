#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>
#include <time>

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
		bool login();
		void ver_admin();
		void mostrar_cursos();
		void estadisticas();

	inline string get_dni(){return dni_;};
};


class Alumnos: public Usuarios{
	public:


		bool inscribirse();


	private:
};

class Admin : public Usuarios{
	public:

		list<string> mostrar_usuarios();
		void eliminar_usuario();
		void anadir_curso();
		bool comprobar_curso();
		bool borrar_curso();
		string listar_cursos();
		void estadisticas();

	private:
};

class Coordinador : public Usuarios {
	public:

		void asignar_recurso();
		void modificar_cursos();


	private:
};

class Cursos{

	private:
		int idC_;
		string nombre_;
		string fechaInicio;
		string fechaFin;
		list<Usuarios>lista_espera_;
		string asignatura_;
		string recursos_;
		string descripcion_;
	public:
		string mostrar_informacion();
		string ver_asignaturas();
		string ver_profesor();
};

class Visitante{
	private:
		int idV_;
	public:
		string ver_cursos();
		bool registrarse();

};

//getters y setters usuarios





#endif












