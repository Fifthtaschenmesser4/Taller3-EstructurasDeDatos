#include "../include/NodoBHoja.h"
NodoBHoja::NodoBHoja(int orden) : NodoBPlusBase(orden, true){}
NodoGrafo* NodoBHoja::buscar(int id, int ordenArbol){
    if (!datos) return nullptr;
    for (int i = 0; i < ordenArbol; ++i) {
        if (datos[i] and datos[i]->getID() == id) return datos[i];
        if (datos[i] and datos[i]->getID() > id) return nullptr;
    }
    return nullptr;
}