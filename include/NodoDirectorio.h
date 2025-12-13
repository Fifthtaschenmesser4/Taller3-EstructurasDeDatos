#pragma once
#include "NodoGrafo.h"
class NodoDirectorio: public NodoGrafo {
public:
NodoDirectorio(int id);
void show();
bool es_directorio() { return true; }
std::vector<int> lista_hijos;
void agregarHijo(int id_hijo);
bool removerHijo(int id_archivo);
};
