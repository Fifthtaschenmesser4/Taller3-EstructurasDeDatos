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
void NodoGrafo::removerPadre(int id_directorio_padre){
    int index=-1;
    for(int i = 0;i<lista_padres.size();i++){
        if(lista_padres[i]==id_directorio_padre) {index=i; break;}
    }
    lista_padres.erase(lista_padres.begin()+index);
}

