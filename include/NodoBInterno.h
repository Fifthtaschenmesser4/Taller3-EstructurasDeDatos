#pragma once
#include "NodoBPlusBase.h"
class NodoBInterno: public NodoBPlusBase {
public:
NodoBInterno(int orden);
NodoBPlusBase* avanzar(int id); //NUEVO MÉTODO, QUE UTILIZA buscar_siguiente()
private:
NodoBPlusBase** punteros; // Vector del tipo NodoBPlusBase*
// función que dado un id de NodoGrafo indica a cual Nodo del árbol B hay
// que moverse. Devuelve el índice de vector punteros.
int buscar_siguiente(int id);
};
