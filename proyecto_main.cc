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
#include <stdlib.h>
#define CLEAR "cls"

using namespace std;
int main(){
	string respuesta;
	string confirmacion="si";
	int eleccion;
	cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"|                                                     ACCEDIENDO AL SISTEMA                                               |"<<endl;
	cout<<"|                                       CADA VEZ QUE SE ACCEDA A UNA DE LAS OPCIONES:                                     |"<<endl;
	cout<<"|                         EL PROGRAMA FINALIZARA SU ESTADO PARA REALIZAR CAMBIOS EN LA BASE DE DATOS                      |"<<endl;
	cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"|                                                        ¿Es usted admin?                                                 |"<<endl;
	cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
	cin>>respuesta;
	if(respuesta=="si"){
		cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
		cout<<"|                                              Introduzca la contraseña admin                                             |"<<endl;
		cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
		string pass;
		cin>>pass;
		if(pass!="root"){
			perror("USTED NO ES EL ADMIN");
			exit(-1);
			}else{
				cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
				cout<<"|                                                    @Menu ADMIN@                                                         |"<<endl;
				cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;

					do{ cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
						cout<<"|                                                    1.-Crear Cursos                                                      |"<<endl;
						cout<<"|                                                    2.-Listar Cursos                                                     |"<<endl;
						cout<<"|                                             3.-Cerrar Sesion y cerrar sistema                                           |"<<endl;
						cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
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
					}while(eleccion!=3);
			}
		}else{

			cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
			cout<<"|                                         ACCEDIENDO AL MENU DE VISITANTES...ESPERE                                       |"<<endl;
			cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
			cout<<"|                                                ¿ES USTED ALUMNO DEL SISTEMA?                                            |"<<endl;
			cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
			cin>>respuesta;

			if(respuesta=="si"){
				cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
				cout<<"|                                         ACCEDIENDO AL MENU DE ALUMNOS...ESPERE                                          |"<<endl;
				cout<<"|                                                  1.-Iniciar Sesion                                                      |"<<endl;
				cout<<"|                                                   2.-Listar Cursos                                                      |"<<endl;
				cout<<"|                                                   3.-Inscrbirse                                                         |"<<endl;
				cout<<"|                                                   4.-Cerrar                                                             |"<<endl;
				cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
				cin>>eleccion;
				do{
					switch(eleccion){
						case 1:
						{
							Alumnos a("aux");
							a.login();
						}
							break;
						case 2:
						{
							Usuarios u("aux");
							u.mostrar_cursos();
						}
							break;
						case 3:
						{
							Alumnos a("aux");
							a.inscribirse();
						}
						break;
					}
				}while(eleccion!=4);

			}else{

			do{
					cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
					cout<<"|                                                1.-Registrar usuario                                                     |"<<endl;
					cout<<"|                                                  2.-Iniciar Sesion                                                      |"<<endl;
					cout<<"|                                                   3.-Listar Cursos                                                      |"<<endl;
					cout<<"|                                            4.-Cerrar Sesion y cerrar sistema                                            |"<<endl;
					cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
					cin>>eleccion;
					switch(eleccion){
							case 1:
							{
								Visitante aux(0);
								aux.registrarse();


								break;
							}
							case 2:
							{	Usuarios u("aux");
								u.login();
							}
								break;
							case 3:
							{
									Usuarios u("aux");
									u.mostrar_cursos();
									//u.mostrar_cursos();
							}
							break;

							default:
								return 0;
								break;
							}
				}while(eleccion!=4);
		}

		}

		return 0;


}
