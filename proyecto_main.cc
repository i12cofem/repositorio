/*
 * main.cc
 *
 *  Created on: 28 nov. 2022
 *      Author: delprado__
 */
/*
 * Aqui vamos a tenr el menu de los ficheros que vamos a usar
 * como interfaz dentro del trabajo pp
 *
 *
 *
 * */
#include <iostream>
#include <string>
#include "proyecto.h"
using namespace std;
int main(){

	int eleccion;
	do{
		cout<<"1.-Registrar usuario"<<endl;
		cout<<"2.-Iniciar Sesion"<<endl;
		cout<<"3.-Crear Cursos"<<endl;
		cout<<"4.-Listar Cursos"<<endl;
		cout<<"5.-Cerrar Sesion y cerras sistema"<<endl;
		cin>>eleccion;
		switch(eleccion){
				case 1:
					cout<<"Has elegido la oopcion de registrar usuario"<<endl;
					cout<<"Inserte Nombre,Apellidos,Dni,CorreoUCO"<<endl;
					cout<<"Ya has sido registrado"<<endl;
					break;
				case 2:
					break;

				case 3:
				{
						Admin aux("0","0","0","0","0");
						aux.anadir_curso();

				//anadir_cursoprueba();
					break;
				}
				case 4:
				{
						Usuarios u("pepe");
						//u.mostrar_cursos();
				}
					break;

				default:
					return 0;
					break;
				}
	}while(eleccion==0);

		return 0;


}
