/*
 * usuarios.h
 *
 *  Autores: i12cofem e i82gavaj
 *  Fecha inicio del proyecto: 23/11/2022
 *  Fecha finalización del proyecto: 06/12/2022
 *
 *
 *
 */
/*
 * En este fichero vamos a tener la definición de la clase Usuarios, con sus respectivos atributos y métodos
 *
 *
 * NOTA:Las clases han sido pensadas para un nivel de desarrollo de codigo mas sofisticado,sin embargo:
 * 		Se han dejado creadas con todos sus atributos por un posible desarrollo del sistema posterior.
 * 		Al no usar bases de datos por incompatibilidad con c++ en eclipse se llega al desarrollo de:
 *
 *
 * 						USO FICHEROS DE TEXTO PLANO DEJANDO INDICADAS LAS CLASES;
 *
 *
 *
 * */






#ifndef USUARIOS_H
#define	USUARIOS_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>
#include "cursos.h"

using namespace std;

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

		Usuarios(string dni, string nombre="", string apellido="", string correo_uco="", string password="");
		bool login();
		void ver_admin();
		void visualizar_cursos(Cursos curso1, string codigo);
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














#endif
