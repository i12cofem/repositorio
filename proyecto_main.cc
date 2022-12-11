/*
 * Iniciado 25/11 --- Creado 30/11
 * AUTHOR: i82gavaj & i12cofem
 *
 */
/*
 * PROGRAMA FINALIZADO DIA: 06/12/2022
 *
 *
 *
 * */
#include <iostream>
#include <string>
#include "usuarios.h"
#include "cursos.h"
#include <fstream>
#include <locale.h>
#include "visitante.h"
//#include "coordinador.h"
#include "admin.h"
#include "alumnos.h"
#include <stdlib.h>
#define CLEAR "cls"
using namespace std;



void ver_cursos(Cursos curso1)
{
    int i=0;
    ifstream lectura;
    lectura.open("cursos.txt",ios::in);

    //------------------------------------------Iniciadores----------------------------------------//
	string iniciar_Codigo = curso1.get_idCurso();
	string iniciar_Nombrecurso = curso1.get_nombreCurso();
	string iniciar_Fechainicio = curso1.get_fechaInicio();
	string iniciar_FechaFin = curso1.get_fechaFin();
	string iniciar_Asignatura = curso1.get_asignatura();
	string iniciar_Recurso = curso1.get_recursos();
	string iniciar_Descripcion = curso1.get_descripcion();
	string iniciar_aforo = curso1.get_aforo();

	//---------------------------------------------------------------------------------------------//


    if(lectura.is_open())
    {
        cout<<"\t\t\t\t***Listado de todos los cursos***\t\t\t\t\n\n";
        getline(lectura,iniciar_Codigo);
        while(!lectura.eof())
        {
            i++;
            getline(lectura,iniciar_Nombrecurso);
            getline(lectura,iniciar_Fechainicio);
            getline(lectura,iniciar_FechaFin);
            getline(lectura,iniciar_Asignatura);
            getline(lectura,iniciar_Recurso);
            getline(lectura,iniciar_Descripcion);
            getline(lectura,iniciar_aforo);


           cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
            cout<<"C\242digo: "<<iniciar_Codigo<<endl;
            cout<<"Nombre: "<<iniciar_Nombrecurso<<endl;
            cout<<"Fecha de inicio: "<<iniciar_Fechainicio<<endl;
            cout<<"Fecha de Finalizaci\242n: "<<iniciar_FechaFin<<endl;
            cout<<"Asignatura: "<<iniciar_Asignatura<<endl;
            cout<<"Recursos disponibles: "<<iniciar_Recurso<<endl;
            cout<<"Descripci\242n del curso: "<<iniciar_Descripcion<<endl;
            cout<<"Aforo: "<<iniciar_aforo<<endl;
            cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
            cout<<"\n\n";
            getline(lectura,iniciar_Codigo);
        }

        if(i==1)
            cout<<"Hay un solo curso registrado en el sistema\n\n";

        else

            cout<<"Hay un total de "<<i<<" cursos registrados en este sistema\n\n";
    }
     else
    {
        exit(-1);
    }
    lectura.close();
    //pausa();
}
void limpiarlogin(){
	ofstream login;
	login.open("login.txt",ios::out);
	if(login.is_open()){
		login<<endl;
	}
}

int main(){
	int rol,eleccion;
	cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"|                                                  Introduzca quien es:                                                   |"<<endl;
	cout<<"|         Admin 1                                        Alumno 2                                     Visitante 3         |"<<endl;
	cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;

				cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
				cin>>rol;
	if(rol==1){
		cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
				cout<<"|                                              Introduzca la contrasena admin                                             |"<<endl;
				cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
				string pass;
				cin>>pass;
				if(pass!="root"){
					perror("USTED NO ES EL ADMIN");
					exit(-1);
					}else {
						cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
						cout<<"|                                                    @Menu ADMIN@                                                         |"<<endl;
						cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;

							do{ cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
								cout<<"|                                                    1.-Crear Cursos                                                      |"<<endl;
								cout<<"|                                                    2.-Borrar Cursos                                                     |"<<endl;
								cout<<"|                                                    3.-Modificar Cursos                                                  |"<<endl;
								cout<<"|                                                    4.-Mostrar cursos                                                    |"<<endl;
								cout<<"|                                             5.-Cerrar Sesion y cerrar sistema                                           |"<<endl;
								cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
								cin>>eleccion;
								switch(eleccion){

									case 1:
									{
											Admin administradoraux;//Existe un admin auxiliar al que se le asigna la funcion de añadir curso;
											Cursos cursoaux;
											administradoraux.anadir_curso(cursoaux);
		    								break;
									}
									case 2:
									{
											Admin administradoraux1; //Existe un usuario auxiliar al que se le asigna la funcion para listar todos los cursos
											Cursos cursoaux1;
											administradoraux1.borrar_curso(cursoaux1);

									}
										break;
									case 3:{
										Admin administradoraux2;
										Cursos cursoaux2;
										administradoraux2.modificar_curso(cursoaux2);

									}
										break;
									case 4:
									{
										Cursos cursoauxilar;
										ver_cursos(cursoauxilar);
									}
										break;

									default:
										cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
										cout<<"|                                         CERRANDO SISTEMA...HASTA PRONTO                                                 |"<<endl;
										cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;

										return 0;
										break;
									}
							}while(eleccion!=5);
					}
	}else if(rol==2){
		cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
		cout<<"|                                         ACCEDIENDO AL MENU DE ALUMNOS...ESPERE                                          |"<<endl;
		cout<<"|                                                  Inicia Sesion                                                          |"<<endl;
		cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
		Alumnos alumnoauxliar;
		alumnoauxliar.login();
			do{
						cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
						cout<<"|                                                   1.-Visualizar Curso                                                   |"<<endl;
						cout<<"|                                                   2.-Inscribirse                                                        |"<<endl;
						cout<<"|                                                   3.-Mostrar Cursos                                                     |"<<endl;
						cout<<"|                                                   4.-Cerrar                                                             |"<<endl;
						cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
						cin>>eleccion;

							switch(eleccion){

								case 1:
								{
									Alumnos alumnoaux;
									Cursos cursoaux3;
									string codigo;
									cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
									cout<<"|                                           Introduce el Identificador del Curso                                          |"<<endl;
									cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
									cin >> codigo;
									alumnoaux.visualizar_cursos(cursoaux3, codigo);
								}
									break;
								case 2:
								{
									Alumnos alumnnoaux2;
									//Alumnos alumno_aux;
									//Cursos cursoaux4;
									alumnnoaux2.inscribirse(/*cursoaux4, alumno_aux*/);
								}
									break;
								case 3:
								{
									Cursos cursoaux5;
									ver_cursos(cursoaux5);

								}
									break;

								default:
										limpiarlogin();
										cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
										cout<<"|                                         CERRANDO SISTEMA...HASTA PRONTO                                                 |"<<endl;
										cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
										return 0;
										break;
							}
						}while(eleccion!=4);
	}else{
					cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
					cout<<"|                                         ACCEDIENDO AL MENU DE VISITANTES...ESPERE                                       |"<<endl;
					cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
					do{
										cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
										cout<<"|                                                1.-Registrar usuario                                                     |"<<endl;
										cout<<"|                                                   2.-Listar Cursos                                                      |"<<endl;
										cout<<"|                                            3.-Cerrar Sesion y cerrar sistema                                            |"<<endl;
										cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
										cin>>eleccion;
										switch(eleccion){
												case 1:
												{
													Visitante visitanteaux;
													Alumnos alumnoaux;
													visitanteaux.registrarse(alumnoaux);


													break;
												}

												case 2:
												{
														Cursos cursoaux5;
														ver_cursos(cursoaux5);
														//u.mostrar_cursos();
												}
												break;

												default:
													limpiarlogin();
													cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
													cout<<"|                                         CERRANDO SISTEMA...HASTA PRONTO                                                 |"<<endl;
													cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
													return 0;
													break;
												}
									}while(eleccion!=3);
							}

	}


