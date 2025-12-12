#pragma once
#include "NodoGrafo.h"
class NodoDirectorio: public NodoGrafo {
public:
NodoDirectorio(int id);
void show();
bool es_directorio() { return true; }
int* lista_hijos();
};
