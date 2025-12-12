#include "../include/NodoBInterno.h"
NodoBInterno::NodoBInterno(int orden) : NodoBPlusBase(orden, false){
    punteros = new NodoBPlusBase*[orden];
}
NodoBPlusBase** NodoBInterno::getPunteros(){
    return punteros;
}
int NodoBInterno::buscar_siguiente(int id){
    int* cl = getClaves();
    for (int i = 0; i < getCount(); i++) {
        if(cl[i]  > id) return i;
    }
    return getCount(); //Si no lo encuentra, se avanza por el último.
}
NodoBPlusBase* NodoBInterno::avanzar(int id){
    int siguienteID = buscar_siguiente(id);
    return punteros[siguienteID];
}
Spliter NodoBInterno::insertTrasladado(int idTrasladado, NodoBPlusBase* nodo){
   int* claves = getClaves();
   int orden = getOrden();
   int ordenPrevio = getOrden();
    if(getCount()<getOrden()-1){ //si no está lleno, se inserta normal
        int i = ordenPrevio-1;
        while(i>=0 and claves[i]>idTrasladado){
            i-=1;
        }
        int posicionClave = i+1;
        for(int j=getCount()-1;j>posicionClave+1;j--){
            punteros[j]=punteros[j-1];
        }
        for(int j=getCount();j>posicionClave+1;j--){
            claves[j]=claves[j-1];
        }
        claves[posicionClave]=idTrasladado;
        punteros[posicionClave+1]=nodo;
      
        setCount(ordenPrevio+1);
        Spliter s(0,nullptr,false); //NO HUBO SPLIT
        return s;
    } else { //está lleno, hay que dividirlo
        //ORDENA LA LISTA (QUE TIENE 1 ESPACIO EXTRA) Y AGREGA LA CLAVE NUEVA
        int c = getCount() - 1;
        while (c >= 0 && claves[c] > idTrasladado) {
            claves[c+1] = claves[c];
            punteros[c+1] = punteros[c];
            c -= 1;
        }
        claves[c+1] = idTrasladado;
        punteros[c+1] = nodo;

        int countPrevio = getCount();
        setCount(countPrevio+1);

        //TRAS ORDENAR, DIVIDE
        int count = getCount();
        int mitad = count/2; //dividimos izq. y der..
        int claveElevada = claves[mitad];
        
        NodoBInterno* nuevo = new NodoBInterno(getOrden());
        int* clavesNuevo = nuevo->getClaves();
        NodoBPlusBase** punterosNuevo = nuevo->punteros;

        int c = 0;
        for(int i = mitad;i<count;i++){
            clavesNuevo[c]=claves[i];
            punterosNuevo[c]=punteros[i];
            c++;
        }
        nuevo->setCount(c);
        setCount(mitad);
        Spliter s(claveElevada,nuevo,true);
    }
}