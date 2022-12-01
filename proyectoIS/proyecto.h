#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>

using namespace std;

#ifndef CURSO_H
#define	CURSO_H




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
	inline string get_nombre(){return nombre_;};
	inline string get_apellido(){return apellido_;};
	inline string get_correoUco(){return correo_uco_;};
	inline string get_password(){return password_;};
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
		string nombrecurso_;
		string fechaInicio;
		string fechaFin;
		list<Usuarios>lista_espera_;
		string asignatura_;
		string recursos_;
		string descripcion_;
	public:

		Cursos(int idC, string nombrecurso, string fechaInicio, string fechaFin, list<Usuarios>lista_espera = {}, string asignatura, string recursos, string descripcion);

		string mostrar_informacion();
		string ver_asignaturas();
		string ver_profesor();

};

class Visitante{
	private:
		int idV_;
	public:

		Visitante(int idV);

		string ver_cursos();
		bool registrarse();

	inline int get_idVisitante(){return idV_;};


};





#endif












