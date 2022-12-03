#ifndef CURSO_H
#define	CURSO_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>

using namespace std;
bool iniciar_sesion();
/*
 * Las clases han sido pensadas para un nivel de desarrollo de codigo mas sofisticado,sin embargo:
 * 		Se han dejado creadas con todos sus atributos por un posible desarrollo del sistema psoterior.
 * 		Al no usar bases de datos por incompatibilidad con c++ en eclipse se llega al desarrollo de:
 * 			USAR FICHEROS DE TEXTO PLANO DEJANDO INDICADAS LAS CLASES;
 */


class Usuarios{

	private:
		string dni_;
		string nombre_;
		string apellido_;
		string correo_uco_;
		string password_;

	public:

		Usuarios(string dni, string nombre="empty", string apellido="empty", string correo_uco="empty", string password="empty");
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

        Alumnos(string dni, string nombre, string apellido, string correo_uco, string password) : Usuarios(dni, nombre, apellido, correo_uco, password){};

		bool inscribirse();


	private:
};



class Admin : public Usuarios{
	public:
        Admin(string dni, string nombre, string apellido, string correo_uco, string password): Usuarios(dni, nombre ,apellido, correo_uco, password){};
		//list<string> mostrar_usuarios(); NO SE TRABAJARA POR FALTA DE TIEMPO
		void eliminar_usuario();
		bool comprobar_curso();
		string listar_cursos();
		void estadisticas();
		void anadir_curso();
		bool borrar_curso();


	private:
};
/*
class Coordinador : public Usuarios {
	public:
        Coordinador(string dni, string nombre, string apellido, string correo_uco, string password);
		void asignar_recurso();
		void modificar_cursos();
	private:
};
*/

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

		Cursos(int idC, string nombrecurso="empty", string fechaInicio="empty", string fechaFin="empty", string asignatura="empty", string recursos="empty", string descripcion="empty", list<Usuarios>lista_espera = {});

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
        Visitante(int idV){idV_ = idV;};
        string ver_cursos();
        void registrarse(); //Bool -> void
    //Getters
    inline int getidVisitante(){return idV_;};
    //Setters
    inline int setidVisitante(int idV){return idV_ = idV;};
};


#endif
