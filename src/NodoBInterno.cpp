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
   int countPrevio = getCount();
   int i = countPrevio-1;
   //PRIMERO ORDENA LA LISTA Y AGREGA EL ID NUEVO
   while(i>=0 and claves[i]>idTrasladado){
        i-=1;
   }
    int posicionClave = i+1;
    for(int j=countPrevio;j>=posicionClave+1;j--){
        punteros[j+1]=punteros[j];
    }
    for(int j=countPrevio-1;j>=posicionClave;j--){
        claves[j+1]=claves[j];
    }
    claves[posicionClave]=idTrasladado;
    punteros[posicionClave+1]=nodo;
      
    setCount(countPrevio+1);

    if(countPrevio<orden-1){ //si no está lleno, se inserta normal
        Spliter s(0,nullptr,false); //NO HUBO SPLIT
        return s;
    } else { //está lleno, hay que dividirlo
        int count = getCount();
        int mitad = count/2; //dividimos izq. y der..
        int claveElevada = claves[mitad];
        
        NodoBInterno* nuevo = new NodoBInterno(getOrden());
        int* clavesNuevo = nuevo->getClaves();
        NodoBPlusBase** punterosNuevo = nuevo->punteros;

        int c = 0;
        for(int i = mitad+1;i<count;i++){
            clavesNuevo[c]=claves[i];
            c++;
        }
        nuevo->setCount(c);
        c=0;
        for(int i = mitad+1;i<=count;i++){
            punterosNuevo[c]=punteros[i];
            c++;
        }
        setCount(mitad);
        Spliter s(claveElevada,nuevo,true);
        return s;
    }
}