#include "../include/NodoDirectorio.h"
#include <iostream>
NodoDirectorio::NodoDirectorio(int id) : NodoGrafo(id){}

void NodoDirectorio::show(){
    std::cout<<"ID: "<<getID()<<std::endl;
    std::cout<<"Es directorio"<<std::endl;
}