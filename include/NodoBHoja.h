#pragma once
#include "NodoBPlusBase.h"
#include "NodoGrafo.h"
class NodoBHoja: public NodoBPlusBase {
public:
NodoBHoja(int orden);
private:
NodoGrafo** datos; // vector del tipo NodoGrafo*
NodoBHoja* siguiente_hoja; // puntero del tipo NodoBHoja*
};