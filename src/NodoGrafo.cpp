#include "../include/NodoGrafo.h"
#include <iostream>
NodoGrafo::NodoGrafo(int id, bool esDirectorio){
    this->id=id;
    this->es_directorio=esDirectorio;
}

int NodoGrafo::getID(){
    return id;
}

void NodoGrafo::agregarPadre(int id_padre){
    this->lista_padres.push_back(id_padre);
}

