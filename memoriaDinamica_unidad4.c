/////////////////////////////////////////////////////
// MEMORIA DINAMICA ( MALLOC - CALLOC- FREE)  //////
///////////////////////////////////////////////////




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




/////////////////////////////////////////////////////////////////

La diferencia entre malloc () y calloc ():

malloc() no inicializa el espacio asignado después de que asigna espacio.
calloc() inicializa el espacio asignado a 0.

calloc() es menos eficiente que malloc()
En general, si no requiero inicialización uso malloc()

NO olvidar liberar memoria!!

Tras reservar memoria y usarla, deberemos hacer uso de free() para liberarla.
*/





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
