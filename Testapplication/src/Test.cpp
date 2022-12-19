#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "alumnos.h"
#include "admin.h"
#include "cursos.h"
#include "visitante.h"

void comprobarLogin() {
	Alumnos alumnosaux;
	bool resultado;
	resultado = alumnosaux.login();
	ASSERT(resultado == false);
}

void comprobarBorrado(){
	Admin administradoraux;
	Cursos cursosaux;
	bool resultado;
	resultado = administradoraux.borrar_curso(cursosaux);
	ASSERT(resultado == false);
}

void comprobarRegistrado(){
	Visitante visitanteaux;
	Alumnos alumnoaux;
	bool resultado;
	resultado = visitanteaux.registrarse(alumnoaux);
	ASSERT_EQUAL(false, resultado);

}

void comprobarAnadirCurso(){
	Admin administradoraux;
	Cursos cursosaux;
	bool resultado;
	resultado  = administradoraux.anadir_curso(cursosaux);
	ASSERT(resultado == false);

}


bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	s.push_back(CUTE(comprobarLogin));
	s.push_back(CUTE(comprobarBorrado));
	s.push_back(CUTE(comprobarRegistrado));
	s.push_back(CUTE(comprobarAnadirCurso));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
