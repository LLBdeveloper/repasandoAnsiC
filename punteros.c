///////////PUNTEROS//////////


//FORMATO PUNTERO
//EJEMPLO
//    tipo * nom_puntero;
//
//    NOM_PUNTERO es el identificador de la variable.
//      *       es el operador que nos indica en la declaracion, que la variable es de tipo puntero.
//    TIPO:     es el tipo de variable apuntada por el puntero, denominado tipo base.

// El tipo base, es muy importante, porque tiene incidencia en el comportamiento del puntero frente a la aritmetica de punteros.


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
//    p=&x;
//
// & devuelve la direccion de memoria de su operando. Con este operador, se puede relacionara los punteros con las variables a ser apuntadas.
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
// p==&x: compara la direccion de memoria a Ia que apunta p con la direccion de memoria de la variable x
// p!=q: compara si los punteros p y q apuntan a distintas direcciones de memoria.



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
//codeando punteros
#include <stdio.h>

int main(){
    int numero = 1;
    int *puntero ;

    puntero = &numero;

    printf("contenido de la variable a la que apunta el puntero: %d \n", *puntero);

    printf("contenido del puntero: %d \n", puntero);

    printf("contenido de la variable NUMERO: %d \n", numero);


//con vector

    int vector[4];
    int x= 3;
    int *p;

    vector[2]=x;

    p = &vector[2];
    printf("accedemos al contenido de un vector por medio de un puntero p: %d \n",*p);



    int *pdex;
    pdex = &x;
    printf("modificamos el contenido de la variable x por medio del puntero pdex: %d \n", *pdex);


    return 0;
}

*/

////////////////////////////////////////////////////////////


// Aritmetica de punteros: suma y resta de entero

/*
#include <stdio.h>

//El puntero conoce su tamanio por el tipo de dato, y al hacer los cålculos considera esa cantidad de bytes para los desplazamientos.


int main(){

    int vec[3]={3,8,9};

    int *pVec=vec;
    printf("%d \n", *pVec);

    pVec=pVec+2; // suma una unidad (int=4bits) a la direccion en memoria, en este caso al proximo elemento en el vector. Ej: 4 bits en este caso al ser un int.
    printf("%d", *pVec);


    return 0;
}
//
// &vec[2] es igual que poner (P+2)
//vec[2] es igual que poner *(p+2)


*/

/////////////////////////////////////////////////////////////////////////////////////////////////////


/*
//PASAJE A FUNCIONES POR REFERENCIA

 #include <stdio.h>



void pasoChar(char);
void pasoVec(int[]);
void pasoInt(int);


int main(){
    int vector[5]={1,2,3,4,5};
    int contador = 66;
    char letra = 'w';

    int *pVec;
    int *pCont;
    char *pLetra;

    pVec = vector;
    pCont = &contador;
    pLetra = &letra;

    pasoVec(pVec);
    pasoInt(pCont);
    pasoChar(pLetra);

    return 0;
}

void pasoVec(int vec[]){
    for(int i = 0; i<5; i++ ){
        printf("El vector es: %d \n", vec[i]);
    }
}

void pasoChar(char *caracter){
    printf("El char es: %c \n", *caracter );
}



void pasoInt(int *numero){
    printf("El numero es: %d \n", *numero );
}

*/


///////////////////////////////////////////////////////////////////////////

/*
//Punteros a string


#include <stdio.h>

void main(){
    char string[10];
    char *p;
    p=string;

    printf("escribi algo \n");
    scanf("%s", p);

    printf("%s",p);
}
*/

/*




//PASAJE POR REFERENCIA DE STRINGS


#include <stdio.h>

void leer(char*q){
    printf("escribir: \n");
    scanf("%s", q);
}

void escribir(char*q){
    printf("%s",q);
}

void main(){
    char palabra[10];
    leer(palabra);
    escribir(palabra);
}



*/
////////////////////

//PASAJE POR REFERENCIA DE STRINGS 2

/*
#include <windows.h> // para darle 1 segundo de dife entre caracter y caracter asi se nota que no escribe la palabra entera de una

#include <stdio.h>

int muestra(char *);

int main(){
    char palabra[10]= "prueba";
    muestra(palabra);

    return 0;
}

int muestra(char *puntero){
    while(*puntero!='\0'){
        printf("%c", *puntero);
        puntero++;
        Sleep(1000);   // 1000 ms = 1 segundo

    }
    printf("\n");
}

*/

////////////////////

/*
//punteros a estructuras

#include <stdio.h>

struct fecha{
    int dia;
    int mes;
    int anio;
};

void hacerAlgo(struct fecha *p);

void main(){
    struct fecha hoy;
    hoy.dia = 13;

    struct fecha *p;
    p = &hoy;

    hacerAlgo(p);
}

void hacerAlgo(struct fecha *p){
    printf("punteros+estructuras: %d", (*p).dia);
};


*/




/*

p->dia     // forma corta
(*p).dia   // forma larga


Caso: (*p).dia

p es un puntero a struct.

Con *p accedés a la estructura completa que apunta.

Después de eso, necesitás el operador . para llegar al campo dia.

ej:

#include <stdio.h>

struct fecha {
    int dia;
    int mes;
    int anio;
};

int main() {
    struct fecha hoy = {11, 9, 2025};
    struct fecha *p = &hoy;

    printf("Con estructura: %d\n", hoy.dia);    // acceso directo
    printf("Con puntero (*p).dia: %d\n", (*p).dia);
    printf("Con puntero p->dia: %d\n", p->dia);

    return 0;
}


*/
/////////////////////////////////

/*

//PASAJE DE ESTRUCTURAS A FUNCIONES ( por referencia)


#include <stdio.h>

struct fecha{
    int dia;
    int mes;
    int anio;
};

void corregir(struct fecha *p);

void main(){

    struct fecha hoy;
    hoy.dia = 29;
    hoy.mes = 2;
    hoy.anio = 2025;

    printf("\033[31m Dia sin corregir: %d \033[0m\n", hoy.dia );

    corregir(&hoy);

}

void corregir(struct fecha *p){
    if ( ((*p).dia == 29) && ((*p).mes == 2) ) {

        (*p).dia=1;
        (*p).mes=3;

        printf("\033[32m Dia corregido: %d \033[0m\n", (*p).dia );

    }
};

*/


///////////////////////////////////////

//PUNTEROS A PUNTEROS

/*

int **p;
p es un puntero a puntero entero
*p es un puntero a entero
* *p es un entero

*/



////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////


// Ejercicios_PUNTEROS_2023.pdf





/* EJERCICIO  (1)

#include <stdio.h>


int incrementar(int*);
void mostrar(int*);


int main(){
    int contador = 1;
    int *cont;

    cont = &contador;

    incrementar(cont);
    mostrar(cont);

    return 0;
}


int incrementar(int *contadorN){

    printf("contadorN es : %d", *contadorN);
    (*contadorN)++; //* nota porlas abajo

    return 0;
}

void mostrar(int *numeroAMostrar){
    printf("mostrando numero: %d", * numeroAMostrar);
}

*/

/*
 *EXPLICACION DE PARENTESIS PUNTERO
int x = 5;
int *p = &x;

*p++;       mueve el puntero, NO cambia x
(*p)++;     incrementa el valor apuntado (cambia x a 6)

*/



///////////////////////////////////////////////////////////////////////


/*

// EJERCICIO  (2)
// falta validacion mas compleja y logica para escribir el nombre del mes segun corresponda, esta harcodeado para una sola situacion.



#include <stdio.h>
#include <string.h>


struct fecha {

    int dia;
    int mes;
    int anio;

};

void validador(struct fecha *p, char *resultado);



int main(){
    char resultado[50];

    struct fecha fechita;

    fechita.dia = 29;
    fechita.mes = 2;
    fechita.anio = 1991;

    sprintf(resultado, "%d del %d de %d", fechita.dia, fechita.mes, fechita.anio);


    printf("%s \n", resultado);

    validador(&fechita, resultado);


    return 0;
}



void validador(struct fecha *p, char *resultado){

    if(    ((*p).dia==29) && ((*p).mes==2)    ){
        printf("hay que corregir fecha, procesando... \n");
        (*p).dia=1;
        (*p).mes=3;

        sprintf(resultado, "%d del %d de %d", (*p).dia, (*p).mes, (*p).anio);
        printf("%s \n", resultado);

    }
};


*/

//////////////////////////////

// EJERCICIO (3)
// no tiene en cuenta caracteres especiales ni espacios

/*

#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main (){

    char frase[]="Vaca es una perra, ella es muy Gorda!!!";

    printf("Ingrese 0 para minuscula o 1 para mayuscula \n");
    char opTipo;
    scanf("%c",&opTipo);

    char *pOpTipo = &opTipo;

    printf("%s \n", frase);

    modificarTexto(frase, pOpTipo);
    printf("%s", frase);


    return 0;
}


void modificarTexto(char *frase, char *opTipo){
    for(int i=0; frase[i] != '\0'; i++){

        if (*opTipo == '1') { // convertir a mayúsculas
            frase[i] = toupper(frase[i]);
        } else {
            frase[i] = tolower(frase[i]);
        }

    }

}


*/

//////////////////////////////////////////////////

/*

// EJERCICIO (4)

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // para limpiar la consola, solo funciona en windows ese comando "cls"
#include <windows.h> // para el sleep y simular un delay



struct articulo {
    int id;
    char nombre[30];
    int costo;
    int cantidad;
};


void calcularInv(struct articulo *, int);
void busquedaID(struct articulo *, int);


int main(){

    // XD - activar para dar efecto de CARGANDO
    printf("\n \n \n \n \n INICIANDO SOFTWARE DE INVENTARIO. . . \n \n \n \n \n");
    Sleep(750);
    system("cls");
    printf("\n \n \n \n \n CARGANDO STOCK. . . \n \n \n \n \n");
    Sleep(1200);
    system("cls");

    //Estructura principal de articulos
    struct articulo articulos[99] = {
        {1, "Teclado Mecanico", 25000, 10},
        {2, "Mouse Gamer", 15000, 20},
        {3, "Monitor 24''", 120000, 5},
        {4, "Auriculares Inalambricos", 35000, 15},
        {5, "Notebook i5", 650000, 3}
    };

    // calcula la cantidad de struct articulo hay en el vector articulos.
    // (divide el tamano total en bits por el tamano de uno solo)
    // int totalEnCatalogo = sizeof(articulos) / sizeof(articulos[0]);
    int totalEnCatalogo = 5;

    //MENU
    int boton = 0;
    while( boton != 3){

        printf("\n--- MENU ---\n");
        printf("\n1. Calcular valor total del inventario\n");
        printf("2. Busqueda de productos por ID\n");
        printf("3. Salir\n");
        printf("\n Elige una opcion: \n");
        scanf("%d", &boton);


        switch(boton){
            case 1:
                system("cls");
                calcularInv(&articulos, totalEnCatalogo);
                break;

            case 2:
                busquedaID(&articulos, totalEnCatalogo);
                break;

            case 3:
                boton=3;
                system("cls");
                printf("\n \n \n \n \n Saliendo del programa...\n \n \n \n \n");
                Sleep(2000);
                break;

            default:
                printf("\n Opcion incorrecta \n");
        }
    }
    system("cls");
    printf("\n \n \n \n \n ---GRACIAS POR UTILIZAR NUESTRO SOFTWARE DE INVENTARIO---\n \n \n \n \n");
    return 0;
}







//Funcion para calcular el valor de inventario.
void calcularInv(struct articulo *producto, int totalCatalogo){

    int valorTotal=0;
    for(int i=0; i<totalCatalogo; i++){
        valorTotal += producto[i].costo * producto[i].cantidad ;
    }

//  printf("calcularInv FUNCIONANDO OK \n");
    printf("La variedad de productos es de %d \n", totalCatalogo);
    printf("\n \n \n \n \n El valor total en pesosARG de todos los productos en el inventario es de: $ %d\n\n \n \n \n \n ",valorTotal);

}


//Funcion para buscar por ID y mostrar sus datos.
void busquedaID(struct articulo *producto, int totalCatalogo){
    //printf("busquedaID FUNCIONANDO OK \n");

    system("cls");
    printf("Ingrese ID del producto a buscar:");
    int idIngresado;
    scanf("%d", &idIngresado);

    for(int i=0; i<totalCatalogo; i++){

        if(idIngresado == producto[i].id){
            system("cls");
            printf("\n\n \n \n \n \n PRODUCTO ENCONTRADO POR ID: \n\nId:%d \nNombre:%s \nCosto:%d \nCantidad:%d \n\n\n \n \n \n \n", producto[i].id, producto[i].nombre, producto[i].costo, producto[i].cantidad);
        }
    }
}







*/


/////////////////////////////


// EJERCICIO (5)

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // para limpiar la consola, solo funciona en windows ese comando "cls"
#include <windows.h> // para el sleep y simular un delay



struct maxMin {
    float maximo;
    float minimo;
};

void buscar(float *, int, struct maxMin *);

int main(){

    // XD - activar para dar efecto de CARGANDO
    printf("\033[31m\n \n \n \n \n INICIANDO SOFTWARE DETECTOR DE MAX MIN. . . \033[0m\n \n \n \n \n");
    Sleep(990);
    system("cls");
    printf("\033[32m\n \n \n \n \n CARGANDO SISTEMA. . . \n \n \n \n \n\033[0m");
    Sleep(1500);
    system("cls");

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


    float vectorNumeros[30];
    int pedido;

    struct maxMin resultado = {0,9999999};

    //pedimos el ingreso del tamano del vector
    do {
        printf("Cuantos elementos desea introducir?\n");
        scanf("%d",&pedido);
        if (pedido<=1 || pedido>30) {
                printf("ERROR!\nIngrese un valor entre 1 y 30 como máximo total de elementos a agregar\n");
        }
    } while (pedido<1 || pedido>30);  //verificar que sea valido el dato que ingresa



    //pedimos ingreso de los elementos del vector (float)
    for(int i=0; i<pedido; i++){
        // agregar los elementos int uno por uno por el usuario por teclado
        // y meterlos en el vector con el maximo que el ya te dio
        system("cls");
        printf("Introduce el float a ingresar en el vector, quedara guardado en la posicion indice: %d\n", i);
        scanf("%f",&vectorNumeros[i]);
    }

    /*
    //recorrer vector para ver si esta bien la logica
    for(int i=0; i<pedido; i++){
        printf("mostrar elemento vector indice %d: %f \n",i,vectorNumeros[i]);
    }
    */

    buscar(&vectorNumeros,pedido,&resultado);
    system("cls");
    printf("RESULTADO\nMaximo:%f \nMinimo:%f \n", resultado.maximo,resultado.minimo);

    return 0;
}


void buscar(float *pVector, int pedido, struct maxMin *pResultado){

    //printf("anda la funcion BUSCAR \n");

    //buscar el maximo del vector pasado por referencia
    //buscar el minimo del vector pasado por referencia


    //recorrer vector
    for(int i=0; i<pedido; i++){
            //printf("mostrar elemento vector indice %d: %f \n",i,pVector[i]);
            if (pVector[i]>(*pResultado).maximo){
                (*pResultado).maximo = pVector[i];
                //printf("el elemento del vector con indice: %d ES EL NUEVO MAXIMO",i);
            }
            if (pVector[i]<(*pResultado).minimo){
                (*pResultado).minimo = pVector[i];
                //printf("el elemento del vector con indice: %d ES EL NUEVO MAXIMO",i);
            }
        }
    //printf("el maximo es:%f", (*pResultado).maximo);
}















///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




//ejercicio en clase
/*
#include<stdio.h>

int strlen(char*);
int main()
{
    char texto[20];
    char *p;
    int cant;

    p=texto;


    printf("Ingrese una palabra\n");
    scanf("%s",texto);

    cant=strlen(p);

    printf("La palabra tiene %d letras\n",cant);

return 0;
}

int strlen(char *q)
{
     int cont=0;
     while(*q!='\0')
    {

        cont++;
        q++;
    }
        return (cont);

}

*/

///////////////////////////////////////////////////////////////









