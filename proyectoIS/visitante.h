/*
 * visitante.h
 *
 *
 *  Autores: i12cofem e i82gavaj
 *  Fecha inicio del proyecto: 23/11/2022
 *  Fecha finalización del proyecto: 06/12/2022
 *
 *
 *
 */
/*
 * En este fichero vamos a tener la definición de la clase Visitantes, con sus respectivos atributos y métodos
 *
 *
 *
 *
 *
 * */






#ifndef VISITANTE_H
#define VISITANTE_H
#include "usuarios.h"
#include "alumnos.h"

class Visitante{
    private:
        int idV_;
    public: 
        Visitante(int idV = 0){idV_ = idV;};
        //void ver_cursos(Cursos curso1);
        bool registrarse(Alumnos alumnos1); //Bool -> void

    //Getters
    inline int getidVisitante(){return idV_;};
    //Setters
    inline int setidVisitante(int idV){return idV_ = idV;};
};





#endif
