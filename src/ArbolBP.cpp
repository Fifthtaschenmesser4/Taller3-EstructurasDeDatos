#include "../include/ArbolBP.h"
#include <iostream>

ArbolBP::ArbolBP(){
    this->raiz=nullptr;
    
}

void ArbolBP::crear_nodo(int id_padre){
    int op,id;
    std::cout<<"¿Qué desea agregar?: 1. Archivo || 2. Directorio"<<std::endl;
    std::cout<<"Ingrese numero>> ";
    std::cin>>op;
    if(op==1){
        int tipo,tamaño;
        std::cout<<"¿Qué tipo de archivo es?: "<<std::endl;
        std::cout<<"0: Imagen; 1: Documento; 2: ejecutable; 3: Video; 4: Comprimido"<<std::endl;
        std::cout<<"Ingrese numero>> ";
        std::cin>>tipo;
        std::cout<<"¿Qué tamaño tiene (MB)?: ";
        std::cin>>tamaño;
        NodoArchivo* nuevo = new NodoArchivo(nuevoID(),tipo,tamaño);
        insertar_nodo_grafo(id_padre,nuevo);
    }else if (op==2){
        NodoDirectorio* nuevo = new NodoDirectorio(nuevoID());
        insertar_nodo_grafo(id_padre,nuevo);
    }else{
    std::cout<<"ERROR:Ingrese opción válida"<<std::endl;
    }
}

void ArbolBP::insertar_nodo_grafo(int clave, NodoGrafo* nodo_grafo){

}
NodoGrafo* ArbolBP::buscar_nodo_grafo(int clave){
    return nullptr;
}
void ArbolBP::eliminar_archivo(int id_archivo, int id_directorio_padre){

}
void ArbolBP::listar_contenido(int id_directorio){

}
std::string* ArbolBP::obtener_rutas_completas(int id_archivo){
    std::string* s;
    return s;
}
int ArbolBP::calcular_espacio_ocupado(int id_directorio){
    return 0;
}

int ArbolBP::nuevoID(){
    this->IDmaker++;
    return IDmaker;
}