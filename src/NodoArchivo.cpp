#include "../include/NodoArchivo.h"

NodoArchivo::NodoArchivo(int id, int tipo, int tamaño) : NodoGrafo(id) {
    this->tipo=tipo;
    this->tamaño=tamaño;
}