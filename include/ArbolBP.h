#pragma once
#include "NodoBHoja.h"
#include "NodoBInterno.h"
#include "NodoArchivo.h"
#include "NodoDirectorio.h"
#include <string>
class ArbolBP{
    public:
    ArbolBP();
    ~ArbolBP(){};
    void insertar_nodo_grafo(int clave, NodoGrafo* nodo_grafo);
    NodoGrafo* buscar_nodo_grafo(int clave);
    void crear_nodo(int id_padre);
    void eliminar_archivo(int id_archivo, int id_directorio_padre);
    void listar_contenido(int id_directorio);
    std::string* obtener_rutas_completas(int id_archivo);
    int calcular_espacio_ocupado(int id_directorio);
    void setOrden(int orden);
    

    private:
    NodoBPlusBase* raiz;
    NodoBPlusBase* buscar_nodo_bplus(int clave);
    int IDmaker;
    int nuevoID();
    int ordenArbol;
};