#include "../include/Sistema.h"
#include <iostream>
Sistema::Sistema(int n){
    this->orden=n;
    this -> arbolB = new ArbolBP(n);
}

void Sistema::insertarNodo(){
    int id;
    std::cout<<"Ingrese ID del directorio padre: ";
    std::cin>>id;
    if(arbolB->buscar_nodo_grafo(id)==nullptr){
        std::cout<<"ERROR:Ingrese ID valido"<<std::endl;
        return;
    }
    arbolB->crear_nodo(id);
}
void Sistema::buscarNodo(){
    int id;
    std::cout<<"Ingrese ID del nodo: ";
    std::cin>>id;
    NodoGrafo* nodo = arbolB->buscar_nodo_grafo(id);
    if(nodo==nullptr){
        std::cout<<"Ese nodo no existe!"<<std::endl;
        return;
    }
    std::cout<<"Encontrado"<<std::endl;
}

void Sistema::eliminarArch(){

}

void Sistema::listarDirectorio(){
}

void Sistema::printRuta(){

}

void Sistema::espacioDirectorio(){

}
