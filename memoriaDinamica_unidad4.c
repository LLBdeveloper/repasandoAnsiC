/////////////////////////////////////////////////////////////////
//// MEMORIA DINAMICA (MALLOC - CALLOC - REALOC - FREE)  //////
///////////////////////////////////////////////////////////////




/*
En C, el heap (o montón) es una región de memoria dinámica donde puedes asignar y liberar memoria manualmente durante la ejecución del programa

¿Qué es el heap?
Es una zona de memoria gestionada por el programador.

La memoria se asigna y libera manualmente (con malloc, calloc, realloc y free).

El tamaño no es fijo: crece o disminuye según lo que necesites.

/////////////////////////////////////////////////////////////////



                            Comparación

    Stack                       vs       Heap

Stack (Pila)    	                     Heap (Montón)
Memoria automática  	                 Memoria manual
Tamaño fijo                         	 Tamaño flexible
Más rápida	                             Más lenta
Variables locales	                     Datos persistentes
Se libera al salir de la función	     Se libera con free()
Limitada en tamaño	                     Mucho más grande




Usar stack cuando:

* sabes de antemano el tamaño maximo

* el array no es gigante.

* buscamos simplicidad y velocidad.



Usar heap  cuando:

/ no se el tamaño hasta que el programa corre ej.el usuario escribe  datos

* necesitas estructuras grandes (listas, aboles, vectores gigantes

* queres que la memoria sobreviva mas alla de una funcion






/////////////////////////////////////////////////////////////////

La diferencia entre malloc () y calloc ():

malloc() no inicializa el espacio asignado después de que asigna espacio.
calloc() inicializa el espacio asignado a 0.

calloc() es menos eficiente que malloc()
En general, si no requiero inicialización uso malloc()

NO olvidar liberar memoria!!

Tras reservar memoria y usarla, deberemos hacer uso de free() para liberarla.









------------------------Diferencia clave


Un puntero normal apunta a una variable ya existente.

malloc reserva memoria en el heap (un bloque sin nombre) y te devuelve la dirección de la primera celda de ese bloque.



///////Array estatico:

Vive en el stack.

Tamaño fijo en tiempo de compilación (int arr[5]).

Se destruye al salir del scope.


///////Array dinamico:

Vive en el heap.

Tamaño elegido en tiempo de ejecución (malloc).

Se destruye solo cuando hacés free(p).


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
} // ¡Contiene valores basura!




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
free(arr);   // ¡Liberar!
arr = NULL;  // Buena práctica: evitar punteros colgantes

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
Cambia el tamaño de un bloque de memoria ya asignado.





4. free() - Liberar memoria
c
free(numeros); // ¡Siempre liberar!
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



