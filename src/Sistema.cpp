#include "../include/Sistema.h"
#include <iostream>
Sistema::Sistema(){
    this -> arbolB = new ArbolBP();
}
void Sistema::insertarNodo(){
    int id;
    std::cout<<"Ingrese ID del directorio padre: ";
    std::cin>>id;
    if(arbolB->buscar_nodo_grafo(id)==nullptr){
        std::cout<<"ERROR:Ingrese ID válido"<<std::endl;
        return;
    }
    arbolB->crear_nodo(id);
}

void Sistema::buscarNodo(){

}

void Sistema::eliminarArch(){

}

void Sistema::listarDirectorio(){
}

void Sistema::printRuta(){

}

void Sistema::espacioDirectorio(){

}

