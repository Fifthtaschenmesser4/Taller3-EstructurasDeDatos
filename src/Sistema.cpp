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
void Sistema::ingresarOrden(){
    int n;
    std::cout<<"Ingrese el orden (factor m) del árbol: ";
    std::cin>>n;
    while(n<1){
        std::cout<<"Ingrese un valor válido: ";
        std::cin>>n;
    }
    this->orden=orden;
}