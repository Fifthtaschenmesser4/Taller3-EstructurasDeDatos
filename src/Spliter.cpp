#include "../include/Spliter.h"
Spliter::Spliter(int idTrasladado, NodoBPlusBase* nuevoNodo, bool wasSplit){
    this->idTrasladado=idTrasladado;
    this->nuevoNodo=nuevoNodo;
    this->wasSplit=wasSplit;
}