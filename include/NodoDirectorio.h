#pragma once
#include "NodoGrafo.h"
class NodoDirectorio: public NodoGrafo {
public:
bool es_directorio() { return true; }
int* lista_hijos();
};
