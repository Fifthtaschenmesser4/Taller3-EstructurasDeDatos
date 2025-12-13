#include "../include/NodoDirectorio.h"
#include <iostream>
NodoDirectorio::NodoDirectorio(int id) : NodoGrafo(id,true){}

void NodoDirectorio::show(){
    std::cout<<"ID: "<<getID()<<std::endl;
    std::cout<<"Es directorio"<<std::endl;
}

void NodoDirectorio::agregarHijo(int id_hijo){
    lista_hijos.push_back(id_hijo);
}

std::vector<int> NodoDirectorio::getHijos(){
    return lista_hijos;
}