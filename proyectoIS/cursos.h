/*
 * cursos.h
 *
 *  Autores: i12cofem e i82gavaj
 *  Fecha inicio del proyecto: 23/11/2022
 *  Fecha finalización del proyecto: 06/12/2022
 *
 *
 *
 */
/*
 * En este fichero vamos a tener la definición de la clase Cursos, con sus respectivos atributos y métodos
 *
 *
 *
 *
 *
 * */




#ifndef CURSOS_H
#define CURSOS_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>
#include "usuarios.h"

using namespace std;

class Cursos{

	private:
		string idCurso_;
		string nombrecurso_;
		string fechaInicio_;
		string fechaFin_;
		//list<Usuarios>lista_espera_;
		string asignatura_;
		string recursos_;
		string descripcion_;
        string aforo_;

	public:

		Cursos(string idCurso = "", string nombrecurso="", string fechaInicio="", string fechaFin="", string asignatura="", string recursos="", string descripcion="", string aforo = "");

		string mostrar_informacion();
		//void visualizar_cursos(string codigo);
		string ver_asignaturas();
		//string ver_profesor();


		//Getters

		inline string get_idCurso(){return idCurso_;};
		inline string get_nombreCurso(){return nombrecurso_;};
		inline string get_fechaInicio(){return fechaInicio_;};
		inline string get_fechaFin(){return fechaFin_;};
		inline string get_asignatura(){return asignatura_;};
		inline string get_recursos(){return recursos_;};
        inline string get_descripcion(){return descripcion_;};
        inline string get_aforo(){return aforo_;};

		//Setters

		inline string set_idCurso(string idCurso){return idCurso_ = idCurso;};
        inline string set_nombreCurso(string nombrecurso){return nombrecurso_ = nombrecurso;};
		inline string set_fechaInicio(string fechaInicio){return fechaInicio_ = fechaInicio;};
        inline string set_fechaFin(string fechaFin){return fechaFin_ = fechaFin;};
        inline string set_asignatura(string asignatura){return asignatura_ = asignatura;};
        inline string set_recursos(string recursos){return recursos_ = recursos;};
        inline string set_descripcion(string descripcion){return descripcion_ = descripcion;};
        inline string set_aforo(string aforo){return aforo_ = aforo;};




};


#endif
