#include "../include/NodoArchivo.h"
#include <iostream>
NodoArchivo::NodoArchivo(int id, int tipo, int tamaño) : NodoGrafo(id,false) {
    this->tipo=tipo;
    this->tamaño=tamaño;
}
void NodoArchivo::show(){
    std::cout<<"ID: "<<getID()<<std::endl;
    std::cout<<"Tamaño: "<<tamaño<<std::endl;
    std::cout<<"Tipo: "<<tipo<<std::endl;
}