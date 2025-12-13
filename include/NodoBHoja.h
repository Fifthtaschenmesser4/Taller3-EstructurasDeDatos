#pragma once
#include "NodoBPlusBase.h"
#include "NodoGrafo.h"
#include "Spliter.h"
class NodoBHoja: public NodoBPlusBase {
public:
NodoBHoja(int orden);
NodoGrafo* buscar(int id, int ordenArbol);
void insertarDato(int clave, NodoGrafo* nodo);
Spliter insertAndSplit(NodoGrafo* nodo_grafo, int clave);
void setSiguiente(NodoBHoja* nodo);
NodoGrafo** getDatos();
private:
NodoGrafo** datos; // vector del tipo NodoGrafo*
NodoBHoja* siguiente_hoja; // puntero del tipo NodoBHoja*
};