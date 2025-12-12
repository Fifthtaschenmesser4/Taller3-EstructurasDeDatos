#pragma once
class NodoBPlusBase {
public:
NodoBPlusBase(int orden, bool es_hoja);
bool hoja();
int getOrden();
int* getClaves();
private:
int* claves; // vector de ids de NodoGrafo
int orden; // factor m de árbol
bool es_hoja; // indica si es nodo interno o hoja del árbol
};
