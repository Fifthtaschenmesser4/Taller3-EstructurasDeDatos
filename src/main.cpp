#include "../include/Sistema.h"
#include <iostream>

void printMenu(){
    std::cout<<"----- Explorador de archivos -----"<<std::endl;
    std::cout<<"1. Crear archivo o directorio"<<std::endl;
    std::cout<<"2. Buscar archivo o directorio"<<std::endl;
    std::cout<<"3. Eliminar archivo"<<std::endl;
    std::cout<<"4. Listar contenidos de directorio"<<std::endl;
    std::cout<<"5. Obtener rutas a un archivo"<<std::endl;
    std::cout<<"6. Calcular espacio"<<std::endl;
    std::cout<<"7. Salir"<<std::endl;
    std::cout<<"Ingrese numero>> ";
}

void iniciarMenu(Sistema &systema){
    int opcion;
    do{
        printMenu();
        std::cin>>opcion;
        if(opcion == 1){
            systema.insertarNodo();
        } else if (opcion == 2){
            systema.buscarNodo();
        } else if(opcion ==3){
            systema.eliminarArch();
        } else if(opcion == 4){
            systema.listarDirectorio();
        } else if(opcion == 5){
            systema.printRuta();
        } else if(opcion == 6){
           systema.espacioDirectorio();
        } else if(opcion==7){
            std::cout<<"Saliendo..."<<std::endl;
        } else {
            std::cout<<"Ingrese una opcion valida."<<std::endl;
        }
    }while(opcion != 7);
}

int ingreseOrden(){
    int n;
    std::cout<<"Ingrese el orden (factor m) del arbol: ";
    std::cin>>n;
    while(n<1){
        std::cout<<"Ingrese un valor valido: ";
        std::cin>>n;
    }
    return n;
}

int main() {
    int ord = ingreseOrden();
    Sistema systema(ord);
    iniciarMenu(systema);
    return 0;
}