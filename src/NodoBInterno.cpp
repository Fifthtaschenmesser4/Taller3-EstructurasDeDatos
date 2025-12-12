#include "../include/NodoBInterno.h"
NodoBInterno::NodoBInterno(int orden) : NodoBPlusBase(orden, false){
    punteros = new NodoBPlusBase*[orden];
}
int NodoBInterno::buscar_siguiente(int id){
    int* cl = getClaves();
    int count=-1;
    for (int i = 0; i < getOrden(); i++) {
        count++;
        if (cl[i]) {
            if(cl[i]  > id) return i;
        } else {
            break;
        }
    }
    return count; //Si no lo encuentra, se avanza por el último.
}
NodoBPlusBase* NodoBInterno::avanzar(int id){
    int siguienteID = buscar_siguiente(id);
    return punteros[siguienteID];
}