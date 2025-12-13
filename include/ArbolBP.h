#pragma once
#include "NodoBHoja.h"
#include "NodoBInterno.h"
#include "NodoArchivo.h"
#include "NodoDirectorio.h"
#include <string>
class ArbolBP{
    public:
    ArbolBP(int orden);
    ~ArbolBP(){};
    void insertar_nodo_grafo(int clave, NodoGrafo* nodo_grafo);
    NodoGrafo* buscar_nodo_grafo(int clave);
    void crear_nodo(int id_padre);
    void eliminar_archivo(int id_archivo, int id_directorio_padre);
    void listar_contenido(int id_directorio);
    std::vector<std::string>* obtener_rutas_completas(int id_archivo);
    int calcular_espacio_ocupado(int id_directorio);
    void setOrden(int orden);
    NodoGrafo* buscar_nodo_grafoSINTEXTO(int clave);
    void rutasREC(NodoGrafo* actual, std::string rutaParcial,
    std::vector<std::string>& rutasFinales);
    int espacioREC(int id_nodo);
    
    NodoBHoja* buscarNodoHoja(int clave);
    private:
    NodoBPlusBase* raiz;
    void insertarRaiz(NodoBHoja* root, NodoGrafo* nodo_grafo, int clave);
    int IDmaker;
    int nuevoID();
    int ordenArbol;
};