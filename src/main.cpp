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
            void buscarNodo();
        } else if(opcion ==3){
            void eliminarArch();
        } else if(opcion == 4){
            void listarDirectorio();
        } else if(opcion == 5){
            void printRuta();
        } else if(opcion == 6){
           void espacioDirectorio();
        } else if(opcion==7){
            std::cout<<"Saliendo..."<<std::endl;
        } else {
            std::cout<<"Ingrese una opción válida."<<std::endl;
        }
    }while(opcion != 7);
}


int main() {
    Sistema systema;
    iniciarMenu(systema);
    return 0;
}