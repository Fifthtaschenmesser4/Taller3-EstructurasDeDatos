#include "../include/NodoDirectorio.h"
#include <iostream>
NodoDirectorio::NodoDirectorio(int id) : NodoGrafo(id,true){}

void NodoDirectorio::show(){
    std::cout<<"ID: "<<getID()<<std::endl;
}

void NodoDirectorio::agregarHijo(int id_hijo){
    lista_hijos.push_back(id_hijo);
}
bool NodoDirectorio::removerHijo(int id_archivo){
    int index=-1;
    for(int i = 0;i<lista_hijos.size();i++){
        if(lista_hijos[i]==id_archivo) {index=i; break;}
    }
    if(index==-1) return false;
    lista_hijos.erase(lista_hijos.begin()+index);
    return true;
}
