
//////////////////////////////////////
////   Ejemplo en clase 11/9   //////
////////////////////////////////////



//librerias
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h> // para limpiar la consola, solo funciona en windows. comando "cls"
#include <windows.h> // para el sleep y simular un delay


//constante
#define MAX 4


//struct
struct direccion{
    char street[20];
    int number;
};

struct perrito{
    int id;
    char name[40];
    int age;
    struct direccion adress;
};


//prototipos d funciones
int add(struct perrito *, int *);
void show(struct perrito *, int);
void search(struct perrito *, int);


//MAIN
int main(){
    struct perrito dogs[MAX];
    int contPerritos=0;
    int boton;

    /* //harcodeando para probar
    struct perrito firulais;
    firulais.id = 1;
    strcpy(firulais.name,"firulais");
    firulais.age = 9;
    strcpy(firulais.adress.street,"alem");
    firulais.adress.number= 233;
    dogs[0]= firulais;
    */


    //menu
do{
    printf("\n\n\n\n--- MENU ---\n\n\n");
    printf("\033[34m1. Agregar perrito\n\033[0m");// \033[34m \033[0m  ES SOLO PARA PONER COLOR AL PRINTF()
    printf("\033[34m2. Ver perritos\n\033[0m");
    printf("\033[34m3. Buscar perrito\n\033[0m");
    printf("\033[34m4. Salir\n\033[0m");
    printf("\n Elige una opcion: \n");
    scanf("%d", &boton);

    switch(boton){
        case 1:
            add(dogs,&contPerritos);
            break;
        case 2:
            show(dogs,contPerritos);
            break;
        case 3:
             search(dogs,contPerritos);
            break;
        case 4:
            boton=4;
            system("cls"); //limpia consola
            printf("\n \n \n \n \n Saliendo del programa...\n \n \n \n \n");
            Sleep(2000); // efecto delay
            system("cls"); //limpia consola

            break;
        default:
            system("cls");//limpia consola
            printf("\n \n \n \n \n \033[31m- OPCION INCORRECTA - \n\n\n Ingrese entero del 1 al 4 \033[0m\n \n \n \n \n \n");

    }
}while(boton!=4);

    return 0;
}




////////////////////////
//FUNCIONES///////////////////////////////////////////////////
///////////////////////


//
//FUNCION agrega un perrito
int add(struct perrito *pVector, int *cantTotal){
    system("cls");//limpia consola
    printf("\n\n\n\n\n AGREGAR PERRITO \n\n\n\n\n");

    //creamos instancia nueva
    struct perrito nuevo;


    //datos del perrix
    //id
    nuevo.id = *cantTotal + 1;
    //nombre
    printf("Ingrese el nombre del perrito: ");
    fflush(stdin);
    fgets(nuevo.name, sizeof(nuevo.name), stdin);
    size_t len = strlen(nuevo.name);
    if(len > 0 && nuevo.name[len-1] == '\n') nuevo.name[len-1] = '\0';//quitar salto de linea
    //edad
    printf("Ingrese la edad del perrito: ");
    scanf("%d", &nuevo.age);
    //calle
    printf("Ingrese la calle donde vive el perrito: ");
    fflush(stdin);
    fgets(nuevo.adress.street, sizeof(nuevo.adress.street), stdin);
    len = strlen(nuevo.adress.street);
    if(len > 0 && nuevo.adress.street[len-1] == '\n') nuevo.adress.street[len-1] = '\0';//quitar salto de linea
    //numero calle
    printf("Ingrese el numero de la calle: ");
    scanf("%d", &nuevo.adress.number);


    //cargamos al vec la nueva instancia
    pVector[*cantTotal]=nuevo;

    //actualizamoss el total
    (*cantTotal)++;

    //feedback
    system("cls"); //limpia cconsola
    printf("\n \033[32mPerrito cargado al sistema con exito!!!\033[0m");

    return 0;
};


//
//FUNCION muestra todos los perritos (en este lo hice con acceso por aritmetica de punteros)
void show(struct perrito *pVector, int cantTotal){
    system("cls");//limpia consola
    printf("\n\n\n\n\n Agenda de perritos \n\n\n\n\n");

    //bucle q muestra los datos del vector dogs
    if(cantTotal!=0){
        for(int i=0; i<cantTotal; i++){
            printf("-Datos del Perrito- \nID:%d \nNombre:%s \nEdad:%d \nDireccion:%s %d\n\n",
                   pVector->id,
                   pVector->name,
                   pVector->age,
                   pVector->adress.street,
                   pVector->adress.number);

                   pVector++;
        }
    }else{
        printf("No hay perritos en sistema!\n\n :(\n");//msj error
    }
};


/*
//FUNCION muestra todos los perritos (en este lo hice con acceso por indices) PEOR ?? NO TAN OPTIMO EN TERMINOS DE MEMORIA ??? CONSULTAR

void show(struct perrito *pVector, int cantTotal){
    system("cls");//limpia consola
    printf("\n\n\n\n\n Agenda de perritos \n\n\n\n\n");

    //bucle q muestra los datos del vector dogs
    if(cantTotal!=0){
        for(int i=0; i<cantTotal; i++){
            printf("-Datos del Perrito- \nID:%d \nNombre:%s \nEdad:%d \nDireccion:%s %d\n\n",
                   pVector[i].id,
                   pVector[i].name,
                   pVector[i].age,
                   pVector[i].adress.street,
                   pVector[i].adress.number);
                    }
    }else{
        printf("No hay perritos en sistema!\n\n :(\n");//msj error
    }
};

*/



//
//FUNCION busca un perrito por id
void search(struct perrito *pVector, int cantTotal){

    int idABuscar;
    system("cls");
    //ingreso de id
    printf("\n\n\n\n\n\n BUSQUEDA DE PERRITOS POR ID \n\n\n\n\n\n");
    printf("Ingrese ID del perrito a buscar: \n");
    scanf("%d",&idABuscar);

    //bucle que busca perrix
    for(int i=0; i<cantTotal; i++){
        if(idABuscar==pVector->id){
            system("cls");
            printf("\n\n\n\n\n\n BUSQUEDA DE PERRITOS POR ID \n\n\n\n\n\n");
            printf("\033[32m- COINCIDENCIA DE ID - \n PERRITO ENCONTRADO! \n\n Nombre: %s\033[0m", pVector->name);
        }else{
            system("cls");
            printf("\n\n\n\n\n\n BUSQUEDA DE PERRITOS POR ID \n\n\n\n\n\n");
            printf("\033[31mID NO ENCONTRADO\033[0m");
        }
        pVector++;
    }
};


//////////////////////////////////////////////////////
// COLORES EN TEXTO  //
//////////////////////
    // Texto rojo
   // printf("\033[31mEste texto es rojo\033[0m\n");
    // Texto verde
   // printf("\033[32mEste texto es verde\033[0m\n");
    // Texto azul
   // printf("\033[34mEste texto es azul\033[0m\n");
////////////////////////////////////////////////////////
