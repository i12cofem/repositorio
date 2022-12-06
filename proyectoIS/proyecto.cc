/*
 * proyecto.cc
 *
 *  Autores: i12cofem e i82gavaj
 *  Fecha inicio del proyecto: 23/11/2022
 *  Fecha finalización del proyecto: 06/12/2022
 *
 *
 *
 */
/*
 * En este fichero vamos a tener las funciones necesarias para la definición del comportamiento
 * de nuestra aplicación
 *
 *
 *
 *
 *
 * */

#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>

//Limpiar pantalla


#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif


//Limpiar pantalla
#include "usuarios.h"
#include "cursos.h"
#include "visitante.h"
#include "admin.h"
#include "alumnos.h"
//#include "coordinador.h"



using namespace std;


Usuarios::Usuarios(string dni, string nombre, string apellido, string correo_uco, string password){

	dni_ = dni;
	nombre_ = nombre;
	apellido_ = apellido;
	correo_uco_ = correo_uco;
	password_ = password;

}

Cursos::Cursos(string idCurso, string nombrecurso, string fechaInicio, string fechaFin, string asignatura, string recursos, string descripcion, string aforo){

	idCurso_ = idCurso;
	nombrecurso_ = nombrecurso;
	fechaInicio_ = fechaInicio;
	fechaFin_ = fechaFin;
	//lista_espera_ = lista_espera;
	asignatura_ = asignatura;
	recursos_ = recursos;
	descripcion_ = descripcion;
	aforo_ = aforo;


}





//------------------------------Función que permite visualizar el curso que haya seleccionado un usuarios--------------------//

void Usuarios::visualizar_cursos(Cursos curso1, string codigo){
    ifstream mostrar;

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


    mostrar.open("cursos.txt",ios::in);
    getline(mostrar,iniciar_Codigo);
    while(!mostrar.eof())
    {
        getline(mostrar,iniciar_Nombrecurso);
        getline(mostrar,iniciar_Fechainicio);
        getline(mostrar,iniciar_FechaFin);
        getline(mostrar,iniciar_Asignatura);
        getline(mostrar,iniciar_Recurso);
        getline(mostrar,iniciar_Descripcion);
        getline(mostrar,iniciar_aforo);

        if(codigo==iniciar_Codigo)
        {
            cout<<"\n\nRegistro Encontrado\n\n";
            cout<<"------------------------------------------------------------------------"<<endl;
            cout<<"C\242digo del curso: "<<iniciar_Codigo<<endl;
            cout<<"Nombre del curso: "<<iniciar_Nombrecurso<<endl;
            cout<<"Fecha de inicio del curso: "<<iniciar_Fechainicio<<endl;
            cout<<"Fecha de finalizaci\242n del curso: "<<iniciar_FechaFin<<endl;
            cout<<"Asignatura: "<<iniciar_Asignatura<<endl;
            cout<<"Recursos disponibles: "<<iniciar_Recurso<<endl;
            cout<<"Descripcion: "<<iniciar_Descripcion<<endl;
            cout<<"Aforo del curso: "<<iniciar_aforo<<endl;
            cout<<"-------------------------------------------------------------------------"<<endl;
            cout<<"\n\n";
        }

        getline(mostrar,iniciar_Codigo);
    }

    mostrar.close();

}


//---------------------------------------------------------------------------------------------------------------------------//






//------------------------Funcion que permite modificar un curso al admin----------------------------------------------------//

void Admin::modificar_curso(Cursos curso1)
{
    ifstream lectura;
    ifstream verificador;
    ofstream auxiliar;
    string auxCodigo;
    string codigoModif;
    string auxcurso;
    string auxinicio;
    string auxfinal;
    string auxasignatura;
    string auxrecursos;
    string auxdescripcion;
    string auxaforo;
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



    bool encontrado=false;
    bool coincidencia=false;
    bool mismoCodigo=false;
    lectura.open("cursos.txt",ios::in);
    verificador.open("cursos.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\t\t\t\t***Modificar los datos de un curso***\t\t\t\t\n\n";
    if(lectura.is_open()&&verificador.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingrese el c\242digo del curso que desee modificar: ";
        getline(cin,auxCodigo);

        if(auxCodigo=="")
        {
            do
            {
                cout<<"c\242digo del curso no v\240lido!, intentalo nuevamente: ";
                getline(cin,auxCodigo);
            }
            while(auxCodigo=="");
        }

        codigoModif=auxCodigo;

        getline(lectura,iniciar_Codigo);
        while(!lectura.eof())
        {
            getline(lectura,iniciar_Nombrecurso);
            getline(lectura,iniciar_Fechainicio);
            getline(lectura,iniciar_FechaFin);
            getline(lectura,iniciar_Asignatura);
            getline(lectura,iniciar_Recurso);
            getline(lectura,iniciar_Descripcion);
            getline(lectura,iniciar_aforo);

            if(auxCodigo==iniciar_Codigo)
            {
                encontrado=true;
                //mostarRegistro(codigoModif);

                cout<<"**********************************************";
                cout<<"\n\n";
                cout<<"Ingresa la nueva informacion para el curso\n\n";
                fflush(stdin);
                cout<<"Ingresa el codigo del curso: ";
                getline(cin,auxCodigo);
                if(auxCodigo==codigoModif)
                {
                    mismoCodigo=true;
                }
                if(mismoCodigo==false)
                {
                    do
                    {
                        if(auxCodigo==codigoModif)
                        {
                            coincidencia=false;
                            break;
                        }
                        verificador.seekg(0);
                        getline(verificador,iniciar_Codigo);
                        while(!verificador.eof())
                        {
                            getline(verificador,iniciar_Nombrecurso);
                            getline(verificador,iniciar_Fechainicio);
                            getline(verificador,iniciar_FechaFin);
                            getline(verificador,iniciar_Asignatura);
                            getline(verificador,iniciar_Recurso);
                            getline(verificador,iniciar_Descripcion);
                            getline(verificador,iniciar_aforo);

                            if(auxCodigo==iniciar_Codigo)
                            {
                                coincidencia=true;
                                cout<<"\n\nYa existe un curso con ese c\242digo!\n\n";
                                cout<<"El curso con ese c\242digo es: "<<iniciar_Nombrecurso<<"\n\n";
                                cout<<"Ingresa un c\242digo v\240lido!: ";
                                getline(cin,auxCodigo);

                                if(auxCodigo=="")
                                {
                                    do
                                    {
                                        cout<<"\nc\242digo de curso no v\240lido!, ";
                                        cout<<"intentalo nuevamente: ";
                                        getline(cin,auxCodigo);
                                    }
                                    while(auxCodigo=="");
                                }
                                break;
                            }

                            getline(verificador,iniciar_Codigo);
                        }

                        if(verificador.eof()&&auxCodigo!=iniciar_Codigo)
                        {
                            coincidencia=false;
                        }

                    }
                    while(coincidencia==true);
                }
                system(CLEAR);
                cout<<"***Modificar los datos de un curso***\n\n";
                cout<<"Ingresa el c\242digo del curso que deseas modificar: ";
                cout<<codigoModif;
                //mostarRegistro(codigoModif);
                cout<<"**********************************************";
                cout<<"\n\n";
                cout<<"Ingresa la nueva informaci\242n para el curso\n\n";
                cout<<"Ingresa el c\242digo del curso: ";
                cout<<auxCodigo;
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el nombre del curso: ";
                getline(cin,auxcurso);
                curso1.set_nombreCurso(auxcurso);
                fflush(stdin);
                cout<<"\n\n";
                cout<<"Ingresa la fecha de inicio del curso: ";
                getline(cin,auxinicio);
                curso1.set_fechaInicio(auxinicio);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa la fecha final del curso: ";
                getline(cin,auxfinal);
                curso1.set_fechaFin(auxfinal);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa la asignatura del curso: ";
                getline(cin,auxasignatura);
                curso1.set_asignatura(auxasignatura);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa los recursos disponibles para el curso: ";
                getline(cin,auxrecursos);
                curso1.set_recursos(auxrecursos);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el aforo del cliente: ";
                getline(cin, auxaforo);
                curso1.set_aforo(auxaforo);
                cout<<"\n\n";
                fflush(stdin);

                auxiliar<<curso1.get_idCurso()<<"\n"<<curso1.get_nombreCurso()<<"\n"<<curso1.get_fechaInicio()<<"\n"<<curso1.get_fechaFin()
                            <<"\n"<<curso1.get_asignatura()<<"\n"<<curso1.get_recursos()<<"\n"<<curso1.get_descripcion()<<"\n"<<curso1.get_aforo()<<"\n";
                cout<<"El Registro se ha modificado correctamente.\n\n";
            }


            else
            {
                auxiliar<<curso1.get_idCurso()<<"\n"<<curso1.get_nombreCurso()<<"\n"<<curso1.get_fechaInicio()<<"\n"<<curso1.get_fechaFin()
                            <<"\n"<<curso1.get_asignatura()<<"\n"<<curso1.get_recursos()<<"\n"<<curso1.get_descripcion()<<"\n"<<curso1.get_aforo()<<"\n";

            }


            getline(lectura,iniciar_Codigo);
        }

    }

    if(encontrado==false)
    {
        cout<<"\n\nNo se encontro ningun registro con ese codigo!\n\n";
    }
    lectura.close();
    verificador.close();
    auxiliar.close();
    remove("cursos.txt");
    rename("auxiliar.txt","cursos.txt");
    //pausa();
}








//--------------------------------------------------------------------------------------------------------------------------//













//----------------------------Funcion que permite borrar un cuso al admin---------------------------------------------------//




bool Admin::borrar_curso(Cursos curso1)
{
    ifstream lectura;
    ofstream auxiliar;
    bool encontrado=false;
    string auxCodigo;
    char respuesta[5];
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

    lectura.open("cursos.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\t\t\t\t***Borrar un curso de extension***\t\t\t\t\n\n";
    if(lectura.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el c\242digo del curso que deseas borrar: ";
        getline(cin,auxCodigo);
        getline(lectura,iniciar_Codigo);
        while(!lectura.eof())
        {
            getline(lectura,iniciar_Nombrecurso);
            getline(lectura,iniciar_Fechainicio);
            getline(lectura,iniciar_FechaFin);
            getline(lectura,iniciar_Asignatura);
			getline(lectura,iniciar_Recurso);
			getline(lectura,iniciar_Descripcion);
			getline(lectura,iniciar_aforo);

            if(auxCodigo==iniciar_Codigo)
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"----------------------------------------------------------------------------"<<endl;
                cout<<"C\242digo: "<<iniciar_Codigo<<endl;
                cout<<"Nombre del curso: "<<iniciar_Nombrecurso<<endl;
                cout<<"Fecha inicio del curso: "<<iniciar_Fechainicio<<endl;
                cout<<"Fecha final del curso: "<<iniciar_FechaFin<<endl;
                cout<<"Asignatura que se imparte: "<<iniciar_Asignatura<<endl;
				cout<<"Recursos del curso: "<<iniciar_Recurso<<endl;
				cout<<"Descripcion del curso: "<<iniciar_Descripcion<<endl;
                cout<<"Aforo del curso: "<<iniciar_aforo<<endl;
                cout<<"----------------------------------------------------------------------------"<<endl;
                cout<<"\n\n";
                cout<<"Realmente deseas dar de baja a: "<<iniciar_Nombrecurso<<" (s/n)?: ";
                cin.getline(respuesta,5);
                if(strcmp(respuesta,"s")==0||strcmp(respuesta,"S")==0||
                        strcmp(respuesta,"si")==0||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                {
                    cout<<"\n\nEl cliente se ha dado de baja correctamente\n\n";
                }

                else
                {

                    cout<<"\n\nCliente conservado\n\n";
                    auxiliar<<iniciar_Codigo<<"\n"<<iniciar_Nombrecurso<<"\n"<<iniciar_Fechainicio<<"\n"<<iniciar_FechaFin
                            <<"\n"<<iniciar_Asignatura<<"\n"<<iniciar_Recurso<<"\n"<<iniciar_Descripcion<<"\n"<<iniciar_aforo<<"\n";

                }

            }
            else
            {
                auxiliar<<iniciar_Codigo<<"\n"<<iniciar_Nombrecurso<<"\n"<<iniciar_Fechainicio<<"\n"<<iniciar_FechaFin
                            <<"\n"<<iniciar_Asignatura<<"\n"<<iniciar_Recurso<<"\n"<<iniciar_Descripcion<<"\n"<<iniciar_aforo<<"\n";
            }
            getline(lectura,iniciar_Codigo);
        }
        if(encontrado==false)
        {
            cout<<"\n\nNo se encontr\242 el c\242digo: "<<auxCodigo<<"\n\n";
        }

    }

    lectura.close();
    auxiliar.close();
    remove("cursos.txt");
    rename("auxiliar.txt","cursos.txt");
    return encontrado;

}




//----------------------------------------------------------------------------------------------------------------------------//














//---------------------------Función que permite iniciar sesión al usuario------------------------------------------------------//


bool Usuarios::login(){
	//me tiene que leer el fichero registrarme
	//si el dni y la contraseña coinciden a lo introducido me lo guardo en un fichero y retorno true, si no, pues error
	ofstream escritura;
	ifstream lectura;
	string dniprueba,passwordp;
	string aux;


	//-----------------------------Iniciadores--------------------------//

	string iniciar_Dni = dni_;
	string iniciar_Password = password_;

	//------------------------------------------------------------------//


	bool existe=false;
	escritura.open("login.txt",ios::out);
	lectura.open("alumnos.txt",ios::in);
	if(escritura.is_open()&&lectura.is_open()){
		cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
		cout<<"|                                     Ingresa el Dni para iniciar sesion                                                  |"<<endl;
		cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
		fflush(stdin);
		cin>>dniprueba;
		cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
		cout<<"|                                    Ingresa la password para iniciar sesion                                              |"<<endl;
		cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
		fflush(stdin);
		cin>>passwordp;
		   getline(cin,iniciar_Dni);
		        do{
		            lectura.seekg(0);

		            getline(lectura,iniciar_Dni);
		            while(!lectura.eof()){
		                getline(lectura,aux);
		                getline(lectura,aux);
		                getline(lectura,aux);
		                getline(lectura,iniciar_Password);

		                if(iniciar_Dni==dniprueba&&iniciar_Password==passwordp){ //Se comprueba que el dni y la contraseña están en el fichero alumnos
		                   //existe = true;
		                   escritura<<iniciar_Dni<<endl;
		                   escritura<<iniciar_Password<<endl;
		                   cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
		                   cout<<"|                                             INICIO SESION CORRECTAMENTE                                                 |"<<endl;
		                   cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
		                }
		                getline(lectura,iniciar_Dni);
		            }
		            if(lectura.eof()&&iniciar_Dni!=dniprueba&&iniciar_Password!=passwordp)

		                existe=false;
		        }while(existe==true);


		  escritura.close();
		  lectura.close();
		 }

return existe;

}


//------------------------------------------------------------------------------------------------------------//










//------------------------------FUNCIONA---------------------------------//




bool Admin::anadir_curso(Cursos curso1){
	ofstream escritura;
    ifstream verificador;
    string auxCodigo;

	//-------------Iniciadores-----------------------------//

	string iniciar_Codigo = curso1.get_idCurso();
	string iniciar_Nombrecurso = curso1.get_nombreCurso();
	string iniciar_Fechainicio = curso1.get_fechaInicio();
	string iniciar_FechaFin = curso1.get_fechaFin();
	string iniciar_Asignatura = curso1.get_asignatura();
	string iniciar_Recurso = curso1.get_recursos();
	string iniciar_Descripcion = curso1.get_descripcion();
	string iniciar_aforo = curso1.get_aforo();

	//-----------------------------------------------------//

    bool coincidencia=false;
    verificador.open("cursos.txt",ios::in);
    escritura.open("cursos.txt",ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"\t\t\t\t***Dar de alta un curso***\t\t\t\t\n\n";
        fflush(stdin);
        cout<<"Ingresa el c\242digo del curso: ";
        getline(cin,auxCodigo);
        if(auxCodigo=="")
            do
            {
                cout<<"c\242digo de curso no v\240lido!, intentalo nuevamente: ";
                getline(cin,auxCodigo);
            }
            while(auxCodigo=="");
        do
        {
            verificador.seekg(0);
            getline(verificador,iniciar_Codigo);
            while(!verificador.eof())
            {
                
                getline(verificador,iniciar_Nombrecurso);
                getline(verificador,iniciar_Fechainicio);
                getline(verificador,iniciar_FechaFin);
                getline(verificador,iniciar_Asignatura);
				getline(verificador,iniciar_Recurso);
				getline(verificador,iniciar_Descripcion);
				getline(verificador,iniciar_aforo);

                if(iniciar_Codigo==auxCodigo)
                {
                    coincidencia=true;
                    cout<<"\n\nYa existe un curso con ese c\242digo!\n\n";
                    cout<<"El curso con ese codigo es: "<< curso1.get_nombreCurso()<<"\n\n";
                    cout<<"Ingresa un c\242digo v\240lido!: ";
                    getline(cin,auxCodigo);
                    if(auxCodigo=="")
                        do
                        {
                            cout<<"\n codigo de curso no v\240lido!, intentalo nuevamente: ";
                            getline(cin,auxCodigo);
                        }
                        while(auxCodigo=="");

                    break;
                }

                getline(verificador,iniciar_Codigo);
            }

            if(verificador.eof()&&auxCodigo!=iniciar_Codigo)
                coincidencia=false;

        }
        while(coincidencia==true);
        system(CLEAR);
        curso1.set_idCurso(auxCodigo);
        cout<<"\t\t\t\t***Dar de alta un curso***\t\t\t\t\n\n";

        cout<<"Ingresa el codigo del curso: ";
        cout<<curso1.get_idCurso();
        cout<<"\n\n";
        fflush(stdin);

        cout<<"Ingrese el nombre del curso: ";
		string nombrecurso2;
        getline(cin,nombrecurso2);
		curso1.set_nombreCurso(nombrecurso2);
        cout<<"\n\n";
        fflush(stdin);

        cout<<"Ingrese la fecha de inicio del curso: ";
		string fechainicio2;
        getline(cin,fechainicio2);
		curso1.set_fechaInicio(fechainicio2);
        cout<<"\n\n";
        fflush(stdin);

        cout<<"Ingrese la fecha final del curso: ";
		string fechaFinal2;
        getline(cin,fechaFinal2);
		curso1.set_fechaFin(fechaFinal2);
        cout<<"\n\n";
        fflush(stdin);

        cout<<"Ingrese la asignatura que se imparte en el curso: ";
		string asignatura2;
        getline(cin,asignatura2);
		curso1.set_asignatura(asignatura2);
        cout<<"\n\n";
		fflush(stdin);

		cout<<"Ingrese los recursos disponibles del curso: ";
		string recurso2;
        getline(cin, recurso2);
		curso1.set_recursos(recurso2);
        cout<<"\n\n";
		fflush(stdin);

		cout<<"Ingresa descripci\242n del curso: ";
		string descripcion2;
        getline(cin, descripcion2);
		curso1.set_descripcion(descripcion2);
        cout<<"\n\n";
		fflush(stdin);

		cout<<"Ingrese el aforo del curso: ";
		string aforo2;
        getline(cin, aforo2);
		curso1.set_aforo(aforo2);
        cout<<"\n\n";

        escritura<<curso1.get_idCurso()<<"\n"<<curso1.get_nombreCurso()<<"\n"<<curso1.get_fechaInicio()<<"\n"<<curso1.get_fechaFin()
                 <<"\n"<<curso1.get_asignatura()<<"\n"<< curso1.get_recursos()<<"\n"<< curso1.get_descripcion()<<"\n"<<curso1.get_aforo()<<"\n";

        cout<<"El registro se ha completado correctamente.\n\n";
    }

    /* else
    {
        error();
    } */

    escritura.close();
    verificador.close();
    //pausa();

    ofstream nuevo;
    string nombrenuevo= curso1.get_idCurso() +".txt";
    nuevo.open(nombrenuevo,ios::out); //si existe se pierden los datos anteriores y si no existe se crea
    return coincidencia;
    
}

//---------------------------------------------------------------------------------------------------------------------------//


//----------------------------Función que permite inscribir un alumno a un curso-------------------------------------------------------------------------------//


void Alumnos::inscribirse(Cursos curso1, Alumnos alumno1){
		ifstream verificador;
		ifstream lecturalogin;
		ofstream escritura;
		//escritura.open(nuevocurso,ios::out);
		verificador.open("cursos.txt",ios::in);
		//lecturalogin.open("login.txt",ios::in);
		string auxCodigo;
		bool coincidencia = false;

		//----------------------Iniciador--------------------//
			string iniciar_Codigo = curso1.get_idCurso();
			string iniciar_Nombrecurso = curso1.get_nombreCurso();
			string iniciar_Fechainicio = curso1.get_fechaInicio();
			string iniciar_FechaFin = curso1.get_fechaFin();
			string iniciar_Asignatura = curso1.get_asignatura();
			string iniciar_Recurso = curso1.get_recursos();
			string iniciar_Descripcion = curso1.get_descripcion();
			string iniciar_aforo = curso1.get_aforo();
		//---------------------------------------------------//

	    if(verificador.is_open())
    	{
        cout<<"\t\t\t\t***Comprobando si existe el curso***\t\t\t\t\n\n";
        fflush(stdin);
        cout<<"Ingresa el codigo del curso a inscribirse: ";
        getline(cin,auxCodigo);
        if(auxCodigo=="")
            do
            {
                cout<<"codigo del curso no v\240lido!, intentalo nuevamente: ";
                getline(cin,auxCodigo);
            }
            while(auxCodigo=="");
        do
        {
            verificador.seekg(0);
            getline(verificador,iniciar_Codigo);
            while(!verificador.eof())
            {

                getline(verificador, iniciar_Nombrecurso);
                getline(verificador,iniciar_Fechainicio);
                getline(verificador,iniciar_FechaFin);
                getline(verificador,iniciar_Asignatura);
				getline(verificador,iniciar_Recurso);
				getline(verificador,iniciar_Descripcion);
				getline(verificador, iniciar_aforo);

                if(iniciar_Codigo==auxCodigo)
                {
                    coincidencia=true;
                    cout<<"\n\nYa existe un curso con ese codigo!\n\n";
                    cout<<"El curso con ese codigo es: "<<curso1.get_nombreCurso()<<"\n\n";
                    cout<<"Ingresa un codigo v\240lido!: ";
                    getline(cin,auxCodigo);
                    if(auxCodigo=="")
                        do
                        {
                            cout<<"\n codigo de curso no v\240lido!, intentalo nuevamente: ";
                            getline(cin,auxCodigo);
                        }
                        while(auxCodigo=="");

                    break;
                }

                getline(verificador,iniciar_Codigo);
            }

            if(verificador.eof()&&auxCodigo!=iniciar_Codigo)
                coincidencia=false;

        }
        while(coincidencia==true);
        system(CLEAR);
        iniciar_Codigo=auxCodigo;
		}
		ifstream verificador2;
		string nuevocurso = iniciar_Codigo +  ".txt";
		escritura.open(nuevocurso, ios::app);
		verificador2.open("login.txt", ios::in);
		string dniaux;

		//---------------Iniciadores----------------------------------//
			string iniciar_Dni = alumno1.get_dni();
			string iniciar_Password = alumno1.get_password();

		//-----------------------------------------------------------//


		if(verificador2.is_open() && escritura.is_open()){

			cout<<"\t\t\t\t***Comprobando si existe el curso***\t\t\t\t\n\n";
        fflush(stdin);
        cout<<"Ingresa el codigo del curso a inscribirse: ";
        getline(cin,dniaux);
        if(dniaux=="")
            do
            {
                cout<<"codigo de curso no valido!, intentalo nuevamente: ";
                getline(cin,dniaux);
            }
            while(dniaux=="");
        do
        {
            verificador2.seekg(0);
            getline(verificador2,iniciar_Dni);
            while(!verificador2.eof())
            {

				getline(verificador2, iniciar_Password);

                if(iniciar_Codigo==dniaux)
                {
                    coincidencia=true;
                    cout<<"\n\nYa existe un curso con ese codigo!\n\n";
                    cout<<"El curso con ese codigo es: "<<alumno1.get_dni()<<"\n\n";
                    cout<<"Ingresa un codigo valido!: ";
                    getline(cin,dniaux);
                    if(dniaux=="")
                        do
                        {
                            cout<<"\n codigo de curso no valido!, intentalo nuevamente: ";
                            getline(cin,dniaux);
                        }
                        while(dniaux=="");

                    break;
                }

                getline(verificador2,iniciar_Dni);
            }

            if(verificador2.eof()&&dniaux!=iniciar_Dni)
                coincidencia=false;

        }
        while(coincidencia==true);
        system(CLEAR);
        iniciar_Dni=dniaux;

			//getline(lecturalogin, iniciar_Dni);

			escritura<<iniciar_Dni<<"\n";
			cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
			cout<<"|-------------------------------------YA SE HA INSCTRITO A UN CURSO. ¡Bienvenido!-----------------------------------------|"<<endl;
			cout<<"|-------------------------------------------------------------------------------------------------------------------------|"<<endl;
		}
		escritura.close();
		verificador.close();
		verificador2.close();
		lecturalogin.close();


}

//------------------------------------------------------------------------------------------------------------------------------------------------------------//


//------------------------------------------Función que permite registrar un Visitante al sistema-----------------------------------------------------//

bool Visitante::registrarse(Alumnos alumno1){
	
    ofstream escritura; // Sirve para abrir el fichero y escribir en el
    ifstream verificador; // Sirve para abrir el fichero y leer en el
    string DNIPRUEBA;

	//


	string iniciardni = alumno1.get_dni();
	string iniciarnombre = alumno1.get_nombre();
	string iniciarapellido = alumno1.get_apellido();
	string iniciarcorreouco = alumno1.get_correoUco();
	string iniciarcontrasena = alumno1.get_password();
    bool coincidencia=false;
    verificador.open("alumnos.txt",ios::in); //abrir en modo entrada
    escritura.open("alumnos.txt",ios::app); //Añade y si no existe lo crea
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"\t\t\t\t***Registar un alumno***\t\t\t\t\n\n";
        fflush(stdin);
        cout<<"Ingresa el DNI del  alumno a registrar: ";
        getline(cin,DNIPRUEBA);
        if(DNIPRUEBA=="")
            do
            {
                cout<<"DNI de Alumno no v\240lido!, intentalo nuevamente: ";
                getline(cin,DNIPRUEBA);
            }
            while(DNIPRUEBA=="");
        do
        {
            verificador.seekg(0);
            getline(verificador, iniciardni);
            while(!verificador.eof())
            {
                getline(verificador, iniciardni);
                getline(verificador,iniciarnombre);
                getline(verificador,iniciarapellido);
                getline(verificador,iniciarcorreouco);
				getline(verificador, iniciarcontrasena);

                if(iniciardni==DNIPRUEBA)
                {
                    coincidencia=true;
                    cout<<"\n\nYa existe un alumno con ese c\242digo!\n\n";
                    cout<<"El alumno con ese DNI es: "<<alumno1.get_nombre()<<"\n\n";
                    cout<<"Ingresa un DNI valido!: ";
                    getline(cin,DNIPRUEBA);
                    if(DNIPRUEBA=="")
                        do
                        {
                            cout<<"\n DNI de alumno no valido!, intentalo nuevamente: ";
                            getline(cin,DNIPRUEBA);
                        }
                        while(DNIPRUEBA=="");

                    break;
                }

                getline(verificador,iniciardni);
            }

            if(verificador.eof()&&DNIPRUEBA!=iniciardni)
                coincidencia=false;

        }
        while(coincidencia==true);
        system(CLEAR);
        alumno1.set_dni(DNIPRUEBA);
        cout<<"\t\t\t\t***Registrar un alumno***\t\t\t\t\n\n";
        cout<<"Ingresa el DNI del alumno a registrar: ";
        cout<<alumno1.get_dni();
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el nombre del alumno a registrar: ";
		string nombre1;
        getline(cin,nombre1);
		alumno1.set_nombre(nombre1);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el apellido del alumno a registrar: ";
		string apellido2;
        getline(cin,apellido2);
		alumno1.set_apellido(apellido2);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el correo de la uco del cliente: ";
		string correouco2;
        getline(cin, correouco2);
		alumno1.set_correo_uco(correouco2);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa la contraseña de inscripci\242n del alumno: ";
		string password2;
        getline(cin,password2);
		alumno1.set_password(password2);
        cout<<"\n\n";
        escritura<<alumno1.get_dni()<<"\n"<<alumno1.get_nombre()<<"\n"<<alumno1.get_apellido()<<"\n"<<alumno1.get_correoUco()
                 <<"\n"<<alumno1.get_password()<<"\n";

        cout<<"El registro se ha completado correctamente.\n\n";
    }

/*     else
    {
        error();
    } */

    escritura.close();
    verificador.close();
	//pause();
    return coincidencia;

}

//-------------------------------------------------------------------------------------------------------------------------------------------------//


