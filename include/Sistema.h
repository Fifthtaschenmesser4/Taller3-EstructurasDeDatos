#pragma once
#include <string>
#include "NodoArchivo.h"
#include "NodoDirectorio.h"
#include "NodoBHoja.h"
#include "NodoBInterno.h"
#include "Grafo.h"
#include "ArbolBP.h"

class Sistema{
    public:
        void insertarNodo(int clave);
        void buscarNodo(int clave);
        void eliminarArch(int idArch, int idDirect);
        void listarDirectorio(int idDirect);
        void printRuta(int idArch);
        void espacioDirectorio(int idDirect);
    private:
        Grafo* sistemaAr;
        ArbolBP* arbolB;
        void insertar_nodo_grafo(int clave, NodoGrafo* nodo_grafo);
        NodoGrafo* buscar_nodo_grafo(int clave);
        void crear_nodo(int id_padre);
        void eliminar_archivo(int id_archivo, int id_directorio_padre);
        std::string* obtener_rutas_completas(int id_archivo);
        std::string* obtener_rutas_completas(int id_archivo);
        int calcular_espacio_ocupado(int id_directorio);
};