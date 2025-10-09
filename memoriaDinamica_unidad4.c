/////////////////////////////////////////////////////////////////
//// MEMORIA DINAMICA (MALLOC - CALLOC - REALOC - FREE)  //////
///////////////////////////////////////////////////////////////




/*
En C, el heap (o mont�n) es una regi�n de memoria din�mica donde puedes asignar y liberar memoria manualmente durante la ejecuci�n del programa

�Qu� es el heap?
Es una zona de memoria gestionada por el programador.

La memoria se asigna y libera manualmente (con malloc, calloc, realloc y free).

El tama�o no es fijo: crece o disminuye seg�n lo que necesites.

/////////////////////////////////////////////////////////////////



                            Comparaci�n

    Stack                       vs       Heap

Stack (Pila)    	                     Heap (Mont�n)
Memoria autom�tica  	                 Memoria manual
Tama�o fijo                         	 Tama�o flexible
M�s r�pida	                             M�s lenta
Variables locales	                     Datos persistentes
Se libera al salir de la funci�n	     Se libera con free()
Limitada en tama�o	                     Mucho m�s grande




Usar stack cuando:

* sabes de antemano el tama�o maximo

* el array no es gigante.

* buscamos simplicidad y velocidad.



Usar heap  cuando:

/ no se el tama�o hasta que el programa corre ej.el usuario escribe  datos

* necesitas estructuras grandes (listas, aboles, vectores gigantes

* queres que la memoria sobreviva mas alla de una funcion






/////////////////////////////////////////////////////////////////

La diferencia entre malloc () y calloc ():

malloc() no inicializa el espacio asignado despu�s de que asigna espacio.
calloc() inicializa el espacio asignado a 0.

calloc() es menos eficiente que malloc()
En general, si no requiero inicializaci�n uso malloc()

NO olvidar liberar memoria!!

Tras reservar memoria y usarla, deberemos hacer uso de free() para liberarla.









------------------------Diferencia clave


Un puntero normal apunta a una variable ya existente.

malloc reserva memoria en el heap (un bloque sin nombre) y te devuelve la direcci�n de la primera celda de ese bloque.



///////Array estatico:

Vive en el stack.

Tama�o fijo en tiempo de compilaci�n (int arr[5]).

Se destruye al salir del scope.


///////Array dinamico:

Vive en el heap.

Tama�o elegido en tiempo de ejecuci�n (malloc).

Se destruye solo cuando hac�s free(p).


*/






/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////// MEMORIA DINAMICA  ///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*

////////////////////////
// MALLOC()
//Asigna un bloque de memoria no inicializada (basura).


//sintaxis
void* malloc(size_t size);

//ejemplo
int *arr = (int*)malloc(5 * sizeof(int)); // Array de 5 enteros
if (arr == NULL) {
    printf("Error: Memoria insuficiente\n");
    exit(1);
} // �Contiene valores basura!




//////////////////////////////////////
//CALLOC()
// Asigna memoria inicializada a cero


//sintaxis
void* calloc(size_t num, size_t size);

//Ejemplo
int *arr = (int*)calloc(5, sizeof(int)); // 5 enteros inicializados a 0
if (arr == NULL) {
    printf("Error: Memoria insuficiente\n");
    exit(1);
}



//////////////////////////////////////
//REALLOC
//Redimensiona un bloque de memoria previamente asignado.


//Sintaxis
void* realloc(void* ptr, size_t new_size);

//ejemplo
int *arr = (int*)malloc(3 * sizeof(int));
arr[0] = 1; arr[1] = 2; arr[2] = 3;

// Ampliar a 5 elementos
int *new_arr = (int*)realloc(arr, 5 * sizeof(int));
if (new_arr == NULL) {
    printf("Error: No se pudo redimensionar\n");
    free(arr);
    exit(1);
}
arr = new_arr;
arr[3] = 4; arr[4] = 5;




//////////////////////////////////////
//FREE
//Libera memoria previamente asignada para evitar fugas.


//sintaxis
void free(void* ptr);

//ejemplo
int *arr = (int*)malloc(5 * sizeof(int));
// Usar la memoria...
free(arr);   // �Liberar!
arr = NULL;  // Buena pr�ctica: evitar punteros colgantes

*/











/*

#include <stdio.h>

int main(){
    // MALLOC
    //void * malloc (unsigned int num_bytes) // PROTOTIPO (bytes a solicitar)
    //  int *numeros = (int*)malloc(10 * sizeof(int)); // Asigna memoria no inicializada (10 enteros)
    p = (int*) malloc(20 * sizeof(int));

    //siempre despues de malloc verificar si el vector no es null,,, si es null es error



    //CALLOC
    // void * calloc (size_t n, size_t size) // PROTOTIPO
    //int *numeros = (int*)calloc(10, sizeof(int)); // Asigna memoria e inicializa en 0. (10 enteros en 0)
    p = (int*) calloc(20, sizeof(int));

    return 0;
}

*/






/*
3. realloc() - Redimensionar
c
numeros = (int*)realloc(numeros, 20 * sizeof(int)); // Ahora 20 enteros
Cambia el tama�o de un bloque de memoria ya asignado.





4. free() - Liberar memoria
c
free(numeros); // �Siempre liberar!
Devuelve la memoria al sistema.

Evita fugas de memoria.
*/




/*

// Practicando3

//Malloc

#include <stdio.h>
#include <stdlib.h>


#define MAX 9


int main(){

    int * pArrNumeros = (int*)malloc(MAX * sizeof(int));


    if (pArrNumeros == NULL) {
        printf("Error al reservar espacio en memoria \n");
        return 1;
    }

    printf("Se reservo espacio en memoria con exito \n");

    int aux
    for(int i = 0; i<MAX; i++){
        printf("espacio en exa: %x  indice del arrNumeros: %d \n",(pArrNumeros), i );
        pArrNumeros++;
    }

    free(pArrNumeros);


    return 0;
}


*/




/*

//practicando 2

//malloc & calloc



#include <stdio.h>
#include <stdlib.h>
// tengo que hacer andar el aux. (sin el ya funciona pero se me corre de posicion el puntero original lpm)

int main(){


//MALLOC
    printf("\n\n\n ----- MALLOC : \n\n");

    int maximo=10;
    int *pConMalloc=(int*)malloc(maximo*sizeof(int));
    // int *aux=pConMalloc;
    printf("\n\n\nla direccion en memoria de pConMalloc posicion 1 es: %x \n", pConMalloc);

    int *aux;
    aux = pConMalloc;
    printf("\n\n\nla direccion en memoria de aux posicion 1 es: %x \n\n", aux);

    for (int i=0; i < maximo; i++){
        *aux= i+1;
        printf("el contenido de pConMalloc es: %d \n", *aux);
        aux++;
    }
        printf("\n\n\nla direccion en memoria de pConMalloc posicion 1 es: %x \n", pConMalloc);
        printf("\n\n\nla direccion en memoria de aux posicion 1 es: %x \n\n", aux);



//CALLOC
    printf("\n\n\n ----- CALLOC : \n\n");


    int max = 3;

        int * pConCalloc = (int*)calloc(max,sizeof(int));

    if (pConCalloc == NULL) {
        printf("Error al reservar memoria\n");
        return 1; // por si falla ya tenemos la salida
    }


    for (int i=0; i < max; i++){
        printf("el contenido de pConCalloc es: %d \n", *pConCalloc);
        }



    //for escribiendo el calloc
    int *aux2;
    aux2 = pConCalloc;

    for (int i=0; i < max; i++){
        *aux2=i;
        printf("\n\n\nla direccion en memoria de aux2 posicion %d es: %x \n\n", i, aux2);
        printf("el contenido de aux2 es: %d \n", *aux2);
        aux2++;
    }


//REALLOC
    printf("\n\n\n ----- REALLOC : \n\n");

    int *pConRealloc = (int*)realloc(pConCalloc,sizeof(int) * (max+2));
    if(pConRealloc == NULL){
        printf("error al asignar memoria \n");
        free(pConCalloc);
        return 1; // por si falla ya tenemos la salida

    }

    pConCalloc = pConRealloc;


    free(pConCalloc);

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FALTARIA ACOMODAR UN POCO EL CODIGO VERIFICAR QUE ESTE TODO BIEN que el aux       ////////////////////////
//y el puntero del calloc este apuntando bien y demostrar que el realloc ya impacto ////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////

*/






/*
//////////////////////////////////////
////   Ejemplo en clase 11/9   //////
////////////////////////////////////



//librerias
#include <stdio.h>
#include <stdlib.h>
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

  //harcodeando para probar
 //   struct perrito firulais;
   // firulais.id = 1;
    //strcpy(firulais.name,"firulais");
    //firulais.age = 9;
    //strcpy(firulais.adress.street,"alem");
   // firulais.adress.number= 233;
   // dogs[0]= firulais;



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



*/






//////////////////////////////////////////////////////////////////////////////
//////////////////////// EJERCICIOS MEMORIA DINAMICA ////////////////////////
////////////////////////////////////////////////////////////////////////////





/*
////////////////////////
// ejercicio 1




//librerias
#include <stdio.h>
#include <stdlib.h>



//prototipos de funciones
void aumentarContador(int* direccionDelcontador);
void disminuirContador(int* direccionDelcontador);
void menu(int* direccionDelContador);


//main+
int main (){

    int max=1;

    int* contadorCompartido = (int*)malloc(max*sizeof(int));
    if(contadorCompartido == NULL){
        printf("Error al reservar memoria\n");
    }else{
        printf("La direccion de memoria de contadorCompartido es:%x\n", contadorCompartido);
    }

    *contadorCompartido=15;
    printf("El contador es:%d\n", *contadorCompartido);


    menu(contadorCompartido);


    return 0;
}


////////////////
//funciones

void menu(int* direccionDelContador){
        int eleccion;
    do{
        printf("Para aumentar el contador ingrese 1\nPara disminuir el contador ingrese 2\nPara salir ingrese 3\n");
        scanf("%d", &eleccion);
        if (eleccion == 1) {
            aumentarContador(direccionDelContador);
        }else if (eleccion == 2) {
            disminuirContador(direccionDelContador);
        }
       }while(eleccion!=3);
}


void aumentarContador(int* direccionDelcontador){
    (*direccionDelcontador)++;
    printf("Aumentamos en +1 el contadorCompartido\n");
    printf("El contador actual es:%d\n",*direccionDelcontador);

}


void disminuirContador(int* direccionDelcontador){
    (*direccionDelcontador)--;
    printf("Disminuimos en -1 el contadorCompartido\n");
    printf("El contador actual es:%d\n",*direccionDelcontador);

}

*/




/*
////////////////////////
// ejercicio 2


//librerias
#include <stdio.h>
#include <stdlib.h>


//prototipos
void mostrarVec(int max, char* vec);


//main
int main (){

    //declaraciones
    int maxOriginal=20;

    //reservamos memoria en el heap
    char* vector1 = (char*)malloc(maxOriginal * sizeof(char));
    if(vector1 == NULL){
        printf("Error al reservar memoria\n");
    }else{
        printf("La direccion de memoria para verctor1 se reservo con exito y es:%p\n",(void*)vector1);
    }

    char* vector2 = (char*)calloc(maxOriginal, sizeof(char));
    if(vector2 == NULL){
        printf("Error al reservar memoria\n");
    }else{
        printf("La direccion de memoria para verctor2 se reservo con exito y es:%p\n", vector2);
    }


    printf("\n///////////////////////////////////////////////////////");
    printf("///////////////////////////////////////////////////////\n");


    //mostarmos
    printf("\nVamos a mostrar vector1 con malloc\n");
    mostrarVec(maxOriginal,vector1);

    printf("\nVamos a mostrar vector2 con calloc\n");
    mostrarVec(maxOriginal,vector2);

    printf("\n///////////////////////////////////////////////////////");
    printf("///////////////////////////////////////////////////////\n");


    //expandimos los vector en 10 bytes
    int maxNuevo=maxOriginal+10;

    char* auxRealloc1 = (char*)realloc(vector1, sizeof(char)*maxNuevo);
    if(auxRealloc1 == NULL){
        printf("Error al expandir memoria\n");
    }else{
        printf("La direccion de memoria para verctor1 se expandio con exito y es:%p\n",(void*)auxRealloc1);
    }


    char* auxRealloc2 = (char*)realloc(vector2, sizeof(char)*maxNuevo);
    if(auxRealloc2 == NULL){
        printf("Error al expandir memoria\n");
    }else{
        printf("La direccion de memoria para verctor2 se expandio con exito y es:%p\n",(void*)auxRealloc2);
    }


    vector1 = auxRealloc1;
    vector2 = auxRealloc2;


    //mostramos ambos vectores expandidos
    printf("\nVamos a mostrar vector1 con malloc expandido en 10 bytes\n\n");
    mostrarVec(maxNuevo,auxRealloc1);

    printf("\nVamos a mostrar vector2 con calloc expandido en 10 bytes\n\n");
    mostrarVec(maxNuevo,auxRealloc2);


    //liberamos memoria
    free(vector1);
    free(vector2);

    return 0;
}


////////////////
//FUNCIONES


//funcion que muestra vec
void mostrarVec(int max, char* vec){
    printf("\n");
    char* auxVec = vec;
    for(int i=0; i<max; i++){

        printf("%d",*auxVec);


        auxVec++;
    }
    printf("\n");

}

// PENDIENTE
//funcion que agranda el tamano del vector en 10 bytes
//void agrandaVec(){
//}


*/



////////////////////////
// ejercicio 3


#include <stdio.h>
#include <stdlib.h>


void agregarInt(int* vec, int* cont);
void mostrarEnteros(int* vec, int* cont);


int main(){

    int maximo = 10;
    int* contador = 0;

     //reservamos vector en el heap de 10 int
    int* vectorInt = (int*)malloc(maximo*sizeof(int));
    if(vectorInt == NULL){
        printf("ERROR - No se pudo reservar memoria para almacenar enteros\n");
    }else{
        printf("Memoria reservada con exito\n");
    }



    //menu

    int botonMenu;
    do{

        printf("\nSOFTWARE PARA REGISTRAR ENTEROS\n\n");
        printf("1 - Agregar enteros\n");
        printf("2 - Ver enteros registrados\n");
        printf("\nElige una opcion: ");
        scanf("%d",&botonMenu);

        switch (botonMenu) {
            case 1:
                printf("agregarInt - Agregar entero nuevo\n");
                agregarInt(vectorInt,contador);
                printf("El contador de numeros es:%d\n", contador);
                break;

            case 2:
                printf("mostrarEnteros - ver enteros guardados\n");
                mostrarEnteros(vectorInt,contador);
                break;

            case 0:
                printf("EXIT\n");
                botonMenu = 0;
                break;

            default:
                printf("- ERROR - Ingreso invalido\n");
                break;
        }

    }while(botonMenu != 0);






    return 0;
}


////////////////
//FUNCIONES




//agregar entero
void agregarInt(int* vec, int* cont){

    int numNuevo;
    printf("Escriba el entero que quiere ingresar:\n");
    scanf("%d",&numNuevo);
    (*vec)= numNuevo;
    printf("Ingresado el entero:%d\n", *vec);
    *cont++;

}



/// TERMINST EL CONTADOR no aumenta
//ver todos los enteros
void mostrarEnteros(int* vec, int* cont){

    int* auxVec=vec;

    if(auxVec == NULL){
        printf("No hay enteros ingresados");
    }

    for(int i = 0; i<(*cont); i++){
        printf("%d",*auxVec);
        auxVec++;
    }

    printf("El contador de numeros es:%d\n", cont);

}
