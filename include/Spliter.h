#pragma once
#include "NodoBPlusBase.h"
class Spliter{
    public:
    int idTrasladado;
    NodoBPlusBase* nuevoNodo;
    bool wasSplit;
    Spliter(int idTrasladado, NodoBPlusBase* nuevoNodo, bool wasSplit);
};