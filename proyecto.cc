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
    cout<<"Ingresa el codigo del curso"<<endl;
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
    cout<<"Ingresa el codigo del curso"<<endl;
    cout<<codigo<<endl;
    cout<<"Introduce el nombre del curso"<<endl;
    fflush(stdin);
    getline(cin,nombre);
    cout<<"Ingresa la fecha de inicio del curso"<<endl;
    fflush(stdin);
    getline(cin,fechainicio);
    cout<<"Ingresa la fecha de fin del curso"<<endl;
    fflush(stdin);
    getline(cin,fechafinal);
    escritura<<codigo<<"\n"<<nombre<<"\n"<<fechainicio<<"\n"<<fechafinal<<"\n";
    escritura.close();

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
		cout<<"EL codigo del curso es: "<<codigo<<endl;
		cout<<"EL nombre del curso "<<codigo<<" es "<< nombre<<endl;
		cout<<"La fecha inicio del curso "<<codigo<<" es "<< fechainicio<<endl;
		cout<<"La fecha fin del curso "<<codigo<<" es "<< fechafin<<endl;
		getline(lectura,codigo);

	}
	}
	lectura.close();

}


