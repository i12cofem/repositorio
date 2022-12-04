#ifndef VISITANTE_H
#define VISITANTE_H
#include "usuarios.h"
#include "alumnos.h"

class Visitante{
    private:
        int idV_;
    public: 
        Visitante(int idV = 0){idV_ = idV;};
        void ver_cursos(Cursos curso1);
        void registrarse(Alumnos alumnos1); //Bool -> void

    //Getters
    inline int getidVisitante(){return idV_;};
    //Setters
    inline int setidVisitante(int idV){return idV_ = idV;};
};



#endif