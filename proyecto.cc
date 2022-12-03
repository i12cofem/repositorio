/*aqui se van a introducir
 *las funciones que vamos a necesitar para elaborar el proyecto;
 *las
 */
#include "proyecto.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>

using namespace std;


Usuarios::Usuarios(string dni, string nombre, string apellido, string correo_uco, string password){

	dni_ = dni;
	nombre_ = nombre;
	apellido_ = apellido;
	correo_uco_ = correo_uco;
	password_ = password;

}

Cursos::Cursos(int idC, string nombrecurso, string fechaInicio, string fechaFin, string asignatura, string recursos, string descripcion, list<Usuarios>lista_espera){

	idC_ = idC;
	nombrecurso_ = nombrecurso;
	fechaInicio_ = fechaInicio;
	fechaFin_ = fechaFin;
	lista_espera_ = lista_espera;
	asignatura_ = asignatura;
	recursos_ = recursos;
	descripcion_ = descripcion;


}


string getString(string msj){
	string m;
	cout<<msj<<endl;
	getline(cin,m);
	return m;
}
int getint(string msj){
	int n;
	cout<<msj<<endl;
	cin>>n;
	return n;
}

void Admin::anadir_curso(){
   ofstream escritura;
   string codigo;
    string id;
    string nombre,fechainicio,fechafinal,aforo;
    ifstream comprobar;
    bool existe=false;
    comprobar.open("cursos.txt",ios::in);
    escritura.open("cursos.txt",ios::app);
    if(escritura.is_open()&&comprobar.is_open()){
    	cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
    	 cout<<"|                                                Ingresa el codigo del curso                                              |"<<endl;
    cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
    fflush(stdin);
    getline(cin,id);
        do{
            comprobar.seekg(0);

            getline(comprobar,codigo);
            while(!comprobar.eof()){
                getline(comprobar,nombre);
                getline(comprobar,fechainicio);
                getline(comprobar,fechafinal);

                if(codigo==id){
                	existe=true;

                    perror("\nINTENTASTE DUPLICAR UN CURSO::ERROR INTEGRIDAD\n");
                 exit(-1);

                }
                getline(comprobar,codigo);
            }
            if(comprobar.eof()&&codigo!=id)
                existe=false;
        }while(existe==true);

    codigo=id;
    cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
    cout<<"|                                                Ingresa el codigo del curso                                              |"<<endl;

    cout<<codigo<<endl;
    cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
    cout<<"|                                              Introduce el nombre del curso                                              |"<<endl;
    fflush(stdin);
    getline(cin,nombre);
    cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
    cout<<"|                                           Ingresa la fecha de inicio del curso                                          |"<<endl;
    fflush(stdin);

    getline(cin,fechainicio);
    cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
    cout<<"|                                              Ingresa la fecha de fin del curso                                          |"<<endl;
    fflush(stdin);

    getline(cin,fechafinal);
    cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;

    escritura<<codigo<<"\n"<<nombre<<"\n"<<fechainicio<<"\n"<<fechafinal<<"\n";
    escritura.close();
    cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
    cout<<"|                          EL CURSO FUE CREADO-----------------------------CERRANDO SISTEMA                               |"<<endl;
    cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
    ofstream nuevo;
    string nombrenuevo=codigo+".txt";
    nuevo.open(nombrenuevo,ios::out);
    }
}
void Usuarios::mostrar_cursos(){
	ifstream lectura;
	string codigo;
	string nombre;
	string fechainicio;
	string fechafin;
	lectura.open("cursos.txt",ios::in);

	if(lectura.is_open()){
		getline(lectura,codigo);
	while(!lectura.eof()){



		getline(lectura,nombre);
		getline(lectura,fechainicio);
		getline(lectura,fechafin);
		cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
		cout<<"                                                  CURSO: "<<codigo<<endl;
		cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
		cout<<"EL codigo del curso es: "<<codigo<<endl;
		cout<<"EL nombre del curso "<<codigo<<" es "<< nombre<<endl;
		cout<<"La fecha inicio del curso "<<codigo<<" es "<< fechainicio<<endl;
		cout<<"La fecha fin del curso "<<codigo<<" es "<< fechafin<<endl;
		getline(lectura,codigo);

	}
	}
	lectura.close();

}

void Visitante::registrarse(){
   ofstream escritura;
    string DNI;
    string DNIPRUEBA;
    string nombre, apellido, correo_uco,password;
    ifstream comprobar;
    bool existe=false;
    comprobar.open("alumnos.txt",ios::in);
    escritura.open("alumnos.txt",ios::app);
    if(escritura.is_open()&&comprobar.is_open()){
    	cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
    	cout<<"|                                             Ingresa el DNI del ALUMNO                                                   |"<<endl;
    	cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
    fflush(stdin);
    getline(cin,DNIPRUEBA);
        do{
            comprobar.seekg(0);

            getline(comprobar,DNI);
            while(!comprobar.eof()){
                getline(comprobar,nombre);
                getline(comprobar,apellido);
                getline(comprobar,correo_uco);
                getline(comprobar,password);

                if(DNI==DNIPRUEBA){
                    existe=true;

                    perror("\nINTENTASTE DUPLICAR UN ALUMNO::ERROR INTEGRIDAD\n");
                 exit(-1);

                }
                getline(comprobar,DNI);
            }
            if(comprobar.eof()&&DNI!=DNIPRUEBA)
                existe=false;
        }while(existe==true);

    DNI=DNIPRUEBA;
    cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
    cout<<"|                                                Ingresa el DNI del alumno                                                |"<<endl;
    cout<<DNI<<endl;
    cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
    cout<<"|                                             Introduce el nombre del alumno                                              |"<<endl;
    fflush(stdin);
    getline(cin,nombre);
    cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
    cout<<"|                                             Ingresa los apellidos del alumno                                            |"<<endl;
    fflush(stdin);
    getline(cin,apellido);
    cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
    cout<<"|                                               Ingresa el correo del alumno                                              |"<<endl;
    fflush(stdin);
    getline(cin,correo_uco);
    cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
    cout<<"|                                              Ingresa la password del alumno                                             |"<<endl;
    fflush(stdin);
    getline(cin,password);
    cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
    cout<<"|                                        CREANDO USUARIO-----------CERRANDO SISTEMA                                       |"<<endl;
    cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
    escritura<<DNI<<"\n"<<nombre<<"\n"<<apellido<<"\n"<<correo_uco<<"\n"<<password<<"\n";
    escritura.close();

    }
}

bool iniciar_sesion(){
	//me tiene que leer el fichero registrarme
	//si el dni y la contraseña coinciden a lo introducido me lo guardo en un fichero y retorno true, si no, pues error
	ofstream escritura;
	ifstream lectura;
	string dni,dniprueba,password,passwordp;
	string aux;
	bool existe=false;
	escritura.open("login.txt",ios::out);
	lectura.open("alumnos.txt",ios::in);
	if(escritura.is_open()&&lectura.is_open()){
		cout<<"Ingresa el Dni para iniciar sesion"<<endl;
		fflush(stdin);
		cin>>dniprueba;
		cout<<"Ingresa la password para iniciar sesion"<<endl;
		fflush(stdin);
		cin>>passwordp;
		   getline(cin,dni);
		        do{
		            lectura.seekg(0);

		            getline(lectura,dni);
		            while(!lectura.eof()){
		                getline(lectura,aux);
		                getline(lectura,aux);
		                getline(lectura,aux);
		                getline(lectura,password);

		                if(dni==dniprueba&&password==passwordp){
		                   escritura<<dni<<endl;
		                   escritura<<password<<endl;

		                }
		                getline(lectura,dni);
		            }
		            if(lectura.eof()&&dni!=dniprueba)
		                existe=false;
		        }while(existe==true);


		  escritura.close();
		  lectura.close();
		 }

return existe;

}


