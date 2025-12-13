#include "../include/NodoDirectorio.h"
#include <iostream>
NodoDirectorio::NodoDirectorio(int id) : NodoGrafo(id,true){}

void NodoDirectorio::show(){
    std::cout<<"ID: "<<getID()<<std::endl;
}

void NodoDirectorio::agregarHijo(int id_hijo){
    lista_hijos.push_back(id_hijo);
}
