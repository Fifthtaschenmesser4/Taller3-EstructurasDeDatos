#pragma once
#include "NodoArchivo.h"
#include "NodoDirectorio.h"

class Grafo{
    public:
    Grafo();
    ~Grafo(){};
    private:
    NodoDirectorio* principal;
    void insertar();
    void buscar();
    void eliminar();
};