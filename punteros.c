///////////PUNTEROS//////////


//FORMATO PUNTERO
//EJEMPLO
//    tipo * nom_puntero;
//
//    NOM_PUNTERO es el identificador de la variable.
//      *       es el operador que nos indica en la declaraciön, que la variable es de tipo puntero.
//    TIPO:     es el tipo de variable apuntada por el puntero, denominado tipo base.

// El tipo base, es muy importante, porque tiene incidencia en el comportamiento del puntero frente a la aritmética de punteros.


//DECLARACION DE PUNTERO
//EJEMPLO
//    int x, *p;
//
// El * no se aplica a todos los nombres de variables de una declaraciön.
// Cada puntero debe Ilevar su nombre precedido por *
// En el ejemplo, "x" es un entero, pero "p" es un puntero a entero.
//
//
//EJEMPLO
// char *puntero = NULL
//
// Al crear *p, se crea con un valor desconocido es necesario inicializarlo con el valor adecuado. Es un  error comun y de ultima se pueda inicializarlo con NULL.


//OPERADORES PUNTEROS & y *
//EJEMPLO
//    int x,*p;
//    p=$x;
//
// & devuelve la direcciön de memoria de su operando. Con este operador, se puede relacionara los punteros con las variables a ser apuntadas.
// El * es complementario al &, retorna el valor de la variable cuya direccion es la que apunta. Se opera con el contenido a lo que apunta la variable de tipo puntero.
//
//
//EJEMPLO
// int main(){
//    int *ptr;
//    int dato=300;
//
//    ptr=&dato;
//    *ptr=50;
//
//    printf("Dato = %d\n", dato);
//
//    return 0;
// }
// !!No hay que confundir el * que aparece en la declaracion con el operador de indireccion !!


//ASIGNACION DE PUNTEROS
//EJEMPLO
//  int x,*p,*q;
//  p=&x;           p contiene la direccion de x
//  q=p;            p contiene la direccion de x
//                  p y q apuntan a x
//
// COMPARACION DE PUNTEROS: == != < <= > >=
// p<q: compara las direcciones a Ias que apuntan.
// p==&x: compara la direcciön de memoria a Ia que apunta p con la direcciön de memoria de la variable x
// p!=q: compara si los punteros p y q apuntan a distintas direcciones de memoria.







//PASAJE A FUNCIONES POR REFERENCIA
#include <stdio.h>

void pasoChar()
void pasoVec
void pasoInt


void main(){

v

}



