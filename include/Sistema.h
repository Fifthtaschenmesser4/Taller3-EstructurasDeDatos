#pragma once
#include <string>
#include "NodoArchivo.h"
#include "NodoDirectorio.h"
#include "NodoBHoja.h"
#include "NodoBInterno.h"
#include "ArbolBP.h"

class Sistema{
    public:
        Sistema(int n);
        void insertarNodo();
        void buscarNodo();
        void eliminarArch();
        void listarDirectorio();
        void printRuta();
        void espacioDirectorio();
    private:
        ArbolBP* arbolB;
        int orden;
};