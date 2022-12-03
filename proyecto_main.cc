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
	string respuesta;
	string confirmacion="si";
	int eleccion;
	cout<<"ACCEDIENDO AL SISTEMA"<<endl;
	cout<<"CADA VEZ QUE SE ACCEDA A UNA DE LAS OPCIONES:\nEL PROGRAMA FINALIZARA SU ESTADO PARA REALIZAR CAMBIOS EN LA BASE DE DATOS"<<endl;
	cout<<"¿Es usted admin?"<<endl;
	cin>>respuesta;
	if(respuesta=="si"){
		cout<<"Introduzca la contraseña admin"<<endl;
		string pass;
		cin>>pass;
		if(pass!="root"){
			perror("USTED NO ES EL ADMIN");
			exit(-1);
			}else{
				cout<<"Accediendo al menu de admin"<<endl;

					do{
						cout<<"1.-Crear Cursos"<<endl;
						cout<<"2.-Listar Cursos"<<endl;
						cout<<"3.-Cerrar Sesion y cerras sistema"<<endl;
						cin>>eleccion;
						switch(eleccion){

							case 1:
							{
									Admin aux("0","0","0","0","0");//Existe un admin auxiliar al que se le asigna la funcion de añadir curso;
									aux.anadir_curso();


								break;
							}
							case 2:
							{
									Admin aux("0","0","0","0","0"); //Existe un usuario auxiliar al que se le asigna la funcion para listar todos los cursos
									aux.mostrar_cursos();

							}
								break;

							default:
								return 0;
								break;
							}
					}while(eleccion==0);
			}
		}else{
			cout<<"ACCEDIENDO AL MENU DE VISITANTES...ESPERE"<<endl;

			do{

					cout<<"1.-Registrar usuario"<<endl;
					cout<<"2.-Iniciar Sesion"<<endl;
					cout<<"3.-Listar Cursos"<<endl;
					cout<<"4.-Cerrar Sesion y cerras sistema"<<endl;
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
									Usuarios u("pepe");
									u.mostrar_cursos();
									//u.mostrar_cursos();
							}
								break;

							default:
								return 0;
								break;
							}
				}while(eleccion==0);
		}



		return 0;


}
