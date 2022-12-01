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

	//Getters

	inline string get_dni(){return dni_;};
	inline string get_nombre(){return nombre_;};
	inline string get_apellido(){return apellido_;};
	inline string get_correoUco(){return correo_uco_;};
	inline string get_password(){return password_;};

	//Setters

	inline string set_dni(string dni){return dni_ = dni;};
	inline string set_nombre(string nombre){return nombre_ = nombre;};
	inline string set_apellido(string apellido){return apellido_ = apellido;};
	inline string set_correo_uco(string correo_uco){return correo_uco_ = correo_uco;};
	inline string set_password(string password){return password_ = password;};
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
		string fechaInicio_;
		string fechaFin_;
		list<Usuarios>lista_espera_;
		string asignatura_;
		string recursos_;
		string descripcion_;
	public:

		Cursos(int idC, string nombrecurso, string fechaInicio, string fechaFin, list<Usuarios>lista_espera = {}, string asignatura, string recursos, string descripcion);

		string mostrar_informacion();
		string ver_asignaturas();
		string ver_profesor();

		//Getters

		inline int get_idC(){return idC_;};
		inline string get_nombreCurso(){return nombrecurso_;};
		inline string get_fechaInicio(){return fechaInicio_;};
		inline string get_fechaFin(){return fechaFin_;};
		inline string get_asignatura(){return asignatura_;};
		inline string get_recursos(){return descripcion_;};

		//Setters

		inline int set_idC(int idC){return idC_ = idC;};
        inline string set_nombreCurso(string nombrecurso){return nombrecurso_ = nombrecurso;};
		inline string set_fechaInicio(string fechaInicio){return fechaInicio_ = fechaInicio;};
        inline string set_fechaFin(string fechaFin){return fechaFin_ = fechaFin;};
        inline string set_asignatura(string asignatura){return asignatura_ = asignatura;};
        inline string set_recursos(string recursos){return recursos_ = recursos;};
        inline string set_descripcion(string descripcion){return descripcion_ = descripcion;};




};

class Visitante{
	private:
		int idV_;
	public:

		Visitante(int idV);

		string ver_cursos();
		bool registrarse();

	//Getters

	inline int get_idVisitante(){return idV_;};

	//Setters

	inline int set_idVisitante(int idV){return idV_ = idV;};

};





#endif












