#pragma once
#include <vector>
class NodoGrafo{
private:
int id;
public:
NodoGrafo(int id, bool esDirectorio);
bool es_directorio;
std::vector<int> lista_padres;
int getID();
void agregarPadre(int id_padre);
};