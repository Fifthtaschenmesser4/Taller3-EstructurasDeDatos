#include "../include/NodoBHoja.h"
#include "../include/NodoBInterno.h"
#include <queue>
NodoBHoja::NodoBHoja(int orden) : NodoBPlusBase(orden, true){}
NodoGrafo* NodoBHoja::buscar(int id, int ordenArbol){
    if (!datos) return nullptr;
    for (int i = 0; i < getCount(); ++i) {
        if (datos[i]->getID() == id) return datos[i];
        if (datos[i]->getID() > id) return nullptr;
    }
    return nullptr;
}
void NodoBHoja::insertarDato(int clave, NodoGrafo* nodo){
}
Spliter NodoBHoja::insertAndSplit(NodoGrafo* nodo_grafo, int clave){
    int* claves = getClaves();
    if(getCount()<getOrden()-1){ //si no está lleno, se inserta normal
        int c = getCount()-1;

        while(c>=0 and claves[c]>clave){
            claves[c+1]=claves[c];
            datos[c+1]=datos[c];
            c-=1;
        }
        claves[c+1]=clave;
        datos[c+1]=nodo_grafo;
        int countPrevio = getCount();
        setCount(countPrevio+1);

        Spliter s(0,nullptr,false); //NO HUBO SPLIT
        return s;
    } else { //está lleno, hay que dividirlo
        //ORDENA LA LISTA (QUE TIENE 1 ESPACIO EXTRA) Y AGREGA LA CLAVE NUEVA
        int c = getCount() - 1;
        while (c >= 0 && claves[c] > clave) {
            claves[c+1] = claves[c];
            datos[c+1] = datos[c];
            c -= 1;
        }
        claves[c+1] = clave;
        datos[c+1] = nodo_grafo;

        int countPrevio = getCount();
        setCount(countPrevio+1);

        //TRAS ORDENAR, DIVIDE
        int count = getCount();
        int mitad = count/2; //dividimos izq. y der..
        int claveElevada = claves[mitad];
        
        NodoBHoja* nuevo = new NodoBHoja(getOrden());
        int* clavesNuevo = nuevo->getClaves();
        NodoGrafo** punteros = nuevo->datos;

        c = 0;
        for(int i = mitad;i<count;i++){
            clavesNuevo[c]=claves[i];
            punteros[c]=datos[i];
            c++;
        }
        nuevo->setCount(c);
        setSiguiente(nuevo);
        setCount(mitad);
        Spliter s(claveElevada,nuevo,true);
        return s;
    }
}

void NodoBHoja::setSiguiente(NodoBHoja* nodo){
    this->siguiente_hoja=nodo;
}