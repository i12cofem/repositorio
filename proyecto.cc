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
/*
Alumnos getAlumnos(long ced){
	fstream e("registro.txt", ios::out | ios::in | ios:: binary);
	Alumnos aux;
	if(e.is_open()){
		e.seekg((ced-1)*sizeof(Alumnos));
		e.read((char*)&aux,sizeof(Alumnos));
		e.close();
	}
	return aux;
}*/
/*
Cursos getCursos(string ced){
	fstream e("cursos.txt", ios::out | ios::in | ios:: binary);
	Cursos aux;
	if(e.is_open()){
		e.seekg(()*sizeof(Cursos));
		e.read((char*)&aux,sizeof(Cursos));
		e.close();
	}
	return aux;
}*/
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
    cout<<"Ingresa el codigo del curso";
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
                    cout<<"Ya existe un curso con ese identificador";
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
/*
void Cursos::anadir_curso(){
	Cursos aux(0);
	int id;
	string nombrecurso;
	fflush(stdin);
	id=getint("Identificador del curso");
	fflush(stdin);
	nombrecurso=getString("Introduce el nombre del curso");

	aux.set_nombreCurso(nombrecurso);
	aux.set_idC(id);
	fstream e("cursos.txt",ios:: out | ios::in | ios::binary );
	if(e.is_open()){
		e.seekp((+1)*sizeof(Cursos));
		e.write((char*)&aux,sizeof(Cursos));
		e.close();
	}
}
void Usuarios::mostrar_cursos(){
	string s;
	ifstream f( "cursos.txt" );
	 if ( f.is_open() ) {
	 getline( f, s );
	 cout << s << endl;

	 getline( f, s );
	 cout << atof( s.c_str() ) << endl;
	 }
}
void anadir_cursoo(){
*/


/*
bool Alumnos::inscribirse(){
	Alumnos a;
	string correo;
	cout<<"Introduce el correo que tienes como alumno"
	cin>>correo;
	a.set_correo(correo);

	fstream e("")

}
*/
