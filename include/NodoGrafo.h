#pragma once
#include <vector>
class NodoGrafo{
private:
int id;

public:
NodoGrafo(int id, bool esDirectorio);
std::vector<int> lista_padres;
bool es_directorio;
int getID();
void agregarPadre(int id_padre);
void removerPadre(int id_directorio_padre);
};