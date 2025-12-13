#include "../include/ArbolBP.h"
#include <iostream>
#include <stack>

ArbolBP::ArbolBP(int orden){
    this->IDmaker=0;
    this->ordenArbol=orden;
    this->raiz=nullptr;
    insertar_nodo_grafo(0,new NodoDirectorio(0)); //Crea el directorio principal
}

void ArbolBP::crear_nodo(int id_padre){
    int op,id;
    std::cout<<"¿Que desea agregar?: 1. Archivo || 2. Directorio"<<std::endl;
    std::cout<<"Ingrese numero>> ";
    std::cin>>op;
    if(op==1){
        int tipo,tamaño;
        std::cout<<"¿Que tipo de archivo es?: "<<std::endl;
        std::cout<<"0: Imagen; 1: Documento; 2: ejecutable; 3: Video; 4: Comprimido"<<std::endl;
        std::cout<<"Ingrese numero>> ";
        std::cin>>tipo;
        while(tipo<0 || tipo>4){
            std::cout<<"Ingrese opcion valida>> ";
            std::cin>>tipo;
        }
        std::cout<<"¿Que tamaño tiene (MB)?: ";
        std::cin>>tamaño;
        while(tamaño<=0){
            std::cout<<"Ingrese tamaño valido: ";
            std::cin>>tamaño;   
        }
        NodoArchivo* nuevo = new NodoArchivo(nuevoID(),tipo,tamaño);
        insertar_nodo_grafo(id_padre,nuevo);
        NodoDirectorio* padre = static_cast<NodoDirectorio*>(buscar_nodo_grafo(id_padre));
        padre->agregarHijo(nuevo->getID());
        nuevo->agregarPadre(id_padre);
    }else if (op==2){
        NodoDirectorio* nuevo = new NodoDirectorio(nuevoID());
        insertar_nodo_grafo(id_padre,nuevo);
        NodoDirectorio* padre = static_cast<NodoDirectorio*>(buscar_nodo_grafo(id_padre));
        padre->agregarHijo(nuevo->getID());
        nuevo->agregarPadre(id_padre);
    }else{
    std::cout<<"ERROR:Ingrese opcion valida"<<std::endl;
    }
}
void ArbolBP::insertarRaiz(NodoBHoja* root, NodoGrafo* nodo_grafo, int clave){
    raiz=root;
    root->getClaves()[0]=clave;
    root->getDatos()[0]=nodo_grafo;
    root->setCount(1);
}
void ArbolBP::insertar_nodo_grafo(int clave, NodoGrafo* nodo_grafo){
    if(raiz==nullptr){
        NodoBHoja* nodo = new NodoBHoja(ordenArbol);
        insertarRaiz(nodo,nodo_grafo, clave);
        raiz=nodo;
        return;
    }
    
    std::stack<NodoBInterno*> ruta;
    NodoBPlusBase* aux = raiz;
    while(!aux->hoja()){
        NodoBInterno* aux2 = static_cast<NodoBInterno*>(aux);
        ruta.push(aux2);
        aux = aux2->avanzar(clave);
    }
    NodoBHoja* hoja = static_cast<NodoBHoja*>(aux);
    Spliter splited = hoja->insertAndSplit(nodo_grafo, clave); 
    while(splited.wasSplit and !ruta.empty()){
        NodoBInterno* padre = ruta.top();
        ruta.pop();
        splited=padre->insertTrasladado(splited.idTrasladado,splited.nuevoNodo);
    }

    if (splited.wasSplit) { //Llegamos a la raíz
        NodoBInterno* newRoot = new NodoBInterno(ordenArbol);
        int* newClaves = newRoot->getClaves();
        NodoBPlusBase** newPunteros = newRoot->getPunteros();
        newClaves[0] = splited.idTrasladado;
        newPunteros[0] = raiz;
        newPunteros[1] = splited.nuevoNodo;
        newRoot->setCount(1);
        raiz = newRoot; 
    }

}

NodoGrafo* ArbolBP::buscar_nodo_grafo(int clave){
    if(raiz==nullptr) return nullptr;
    NodoBPlusBase* aux = raiz;
    int ES=1;
    while(!aux->hoja()){
        NodoBInterno* aux2 = static_cast<NodoBInterno*>(aux);
        aux = aux2->avanzar(clave);
        ES++;
    }
    NodoBHoja* leaf = static_cast<NodoBHoja*>(aux);
    NodoGrafo* data = leaf->buscar(clave,ordenArbol);
    if(data==nullptr) std::cout<<"No se encontro el nodo"<<std::endl;
    else{
        std::cout<<"Nodo encontrado!"<<std::endl;
        std::cout<<"Numero de accesos a NodosB+: "<<ES<<std::endl;
    }
    return data;
}

NodoBPlusBase* ArbolBP::buscar_nodo_bplus(int clave){ //ESTO NO FUNCIONA
    if(raiz==nullptr) return nullptr;
    NodoBPlusBase* aux = raiz;
    int ES=1;
    while(!aux->hoja()){
        NodoBInterno* aux2 = static_cast<NodoBInterno*>(aux);
        aux = aux2->avanzar(clave);
        ES++;
    }
    NodoBHoja* leaf = static_cast<NodoBHoja*>(aux);//REVISAR SI ESTÁ LLENO, E INSERTAR ORDENADO.
    NodoGrafo* data = leaf->buscar(clave,ordenArbol);
    if(data==nullptr) std::cout<<"No se encontró el nodo"<<std::endl;
    else{
        std::cout<<"¡Nodo encontrado!"<<std::endl;
        std::cout<<"Número de accesos a NodosB+: "<<ES<<std::endl;
    }
    return nullptr;
}

void ArbolBP::eliminar_archivo(int id_archivo, int id_directorio_padre){

}
void ArbolBP::listar_contenido(int id_directorio){
    NodoDirectorio* directorio = static_cast<NodoDirectorio*>(buscar_nodo_grafo(id_directorio));
    if(directorio==nullptr){
        std::cout<<"Ingrese ID valida"<<std::endl;
        return;
    }
    std::vector<int> hijos = directorio->getHijos();
    for(int i = 0;i<hijos.size();i++){
        NodoGrafo* son = buscar_nodo_grafo(hijos[i]);
        if(son->es_directorio){
            NodoDirectorio* soon = static_cast<NodoDirectorio*>(buscar_nodo_grafo(id_directorio));
            soon->show();
        } else {
            NodoArchivo* soon = static_cast<NodoArchivo*>(buscar_nodo_grafo(id_directorio));
            soon->show();
        }
    }
}
std::string* ArbolBP::obtener_rutas_completas(int id_archivo){
    std::string* s;
    return s;
}
int ArbolBP::calcular_espacio_ocupado(int id_directorio){
    return 0;
}

int ArbolBP::nuevoID(){
    this->IDmaker++;
    return IDmaker;
}
void ArbolBP::setOrden(int orden){
    this->ordenArbol=orden;
}
