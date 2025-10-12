//ARCHIVOS  read-white-aniadir
/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    //Paso 1 -  Inicializamos
    FILE * archivoTXT;

    //Paso 2 - Abrimos el archivo
    archivoTXT = fopen("textoPrueba.txt","w");
    if(archivoTXT == NULL){  //validacion

        printf("No se pudo abrir el archivo");
        return 1;

    } else{
        printf("El archivo se abrio con exito");
    }

    //Paso 3 - LEER / ESCRIBIR


    //Paso 4 - cerrar archivo
    fclose(archivoTXT);

}

*/




//////////////////////////////////
//para leer un archivo se utilizan una de estas 3 funciones
//de la biblioteca stdio.h

//      fgetc()  LECTURA CARACTER POR CARACTER
//      fgets()  LECTURA DE UN REGISTRO ( STRING )
//      fscanf() LECTURA FORMATEADA






  /////////////////
 //    FGETC    //
/////////////////
//  La funcion fgetc(FILE*archivo);
//Lee el caracter al cual esta apuntando
//actualmente el puntero de lectura / escritura y avanza al siguiente
//
//      Recibe el puntero FILE* del archivo
//      Devuelve el caracter leido o EOF si se llego al final del archivo




/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int cantA = 0;
    char caracter_leido;
    //Paso 1 -  Inicializamos
    FILE * archivoTXT;

    //Paso 2 - Abrimos el archivo
    archivoTXT = fopen("textoPrueba.txt","r");
    if(archivoTXT == NULL){  //validacion

        printf("No se pudo abrir el archivo");
        return 1;

    } else{
        printf("El archivo se abrio con exito");
    }

    //Paso 3 - LEER / ESCRIBIR

    while((caracter_leido = fgetc(archivoTXT)) != EOF){

        printf("\n%c", caracter_leido);

        if(caracter_leido == 'a'){
            cantA++;
        }

    }

    printf("\nLa cantidad de espacios es:%d", cantA);

    //Paso 4 - cerrar archivo
    fclose(archivoTXT);

}

*/



  /////////////////
 //    FGETS    //
/////////////////
//  fgets(char* destino, cant, FILE*archivo);
//Lee una cadena de caracteres del archivo a partir de la posicion en
//donde se encuentra el puntero de lectura/escritura
//y hasta encontrar un salto de linea /n
//o hasta la cantidad de caracteres que indica "cant".
//El string leido se almacena en 'destino'


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    //Declaraciones
    char buffer[100];
    int cantA = 0;
    char caracter_leido;


    //Paso 1 -  Inicializamos
    FILE * archivoTXT;


    //Paso 2 - Abrimos el archivo
    archivoTXT = fopen("textoPrueba.txt","r");
    if(archivoTXT == NULL){  //validacion

        printf("No se pudo abrir el archivo");
        return 1;

    } else{
        printf("El archivo se abrio con exito");
    }

    //Paso 3 - LEER / ESCRIBIR
    while(fgets(buffer, 100,archivoTXT) != NULL){
        printf("%s",buffer);
    }



    //Paso 4 - cerrar archivo
    fclose(archivoTXT);

}

*/


  /////////////////
 //    FSCANF   //
/////////////////
//      fscanf(archivo,"%d-%d-%d",&nota1,&nota2,&nota3);
//Agarra una cadena de caracteres y la formatea a valores numericos y lo guarda en una variable
//
//Indica el formato que tiene el registro a leer.
//En este caso son 3 numeros enteros separados por un guion medio.
//
//      Cada uno de los tres valores se lee como un entero
//      y se almacena en la variable nota1, nota2 nota3 respectivamente.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    //Declaraciones
    char buffer[100];
    int cantA = 0;
    char caracter_leido;


    //Paso 1 -  Inicializamos
    FILE * archivoTXT;


    //Paso 2 - Abrimos el archivo
    archivoTXT = fopen("textoPrueba.txt","r");
    if(archivoTXT == NULL){  //validacion

        printf("No se pudo abrir el archivo");
        return 1;

    } else{
        printf("El archivo se abrio con exito");
    }

    //Paso 3 - LEER / ESCRIBIR
    while(fgets(buffer, 100,archivoTXT) != NULL){
        printf("%s",buffer);
    }



    //Paso 4 - cerrar archivo
    fclose(archivoTXT);

}




