#include "../include/NodoBPlusBase.h"

NodoBPlusBase::NodoBPlusBase(int orden, bool es_hoja){
    this->orden=orden;
    this->es_hoja=es_hoja;
    this -> claves = new int[orden];
}
bool NodoBPlusBase::hoja(){
    return es_hoja;
}
int NodoBPlusBase::getOrden(){
    return orden;
}
int* NodoBPlusBase::getClaves(){
    return claves;
}
int NodoBPlusBase::getCount(){
    return count;
}
void NodoBPlusBase::setCount(int s){
    this->count=s;
}