/*
 * admin.h
 *
 *  Autores: i12cofem e i82gavaj
 *  Fecha inicio del proyecto: 23/11/2022
 *  Fecha finalización del proyecto: 06/12/2022
 *
 *
 *
 */
/*
 * En este fichero vamos a tener la definición de la clase Admin, con sus respectivos atributos y métodos
 *
 *
 *
 *
 *
 * */


#ifndef ADMIN_H
#define ADMIN_H

#include "usuarios.h"

class Admin : public Usuarios{
	public:
        Admin(string dni = "", string nombre = "root", string apellido = "", string correo_uco = "", string password = ""): Usuarios(dni, nombre ,apellido, correo_uco, password){};
		//list<string> mostrar_usuarios(); NO SE TRABAJARA POR FALTA DE TIEMPO
		//void eliminar_usuario();
		//bool comprobar_curso();
		//void estadisticas();
		bool anadir_curso(Cursos curso1);
		bool borrar_curso(Cursos curso1);
		void modificar_curso(Cursos curso1);


	private:
};

#endif
