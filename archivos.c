//ARCHIVOS  read-write-add
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
    return 0;
}

*/



// ***************************************************************************



////////////////////////////////////////////////////////////
/////////           LECTURA DE ARCHIVOS             ///////
//////////////////////////////////////////////////////////


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
//
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

    //Paso 3 - LEER

    while((caracter_leido = fgetc(archivoTXT)) != EOF){

        printf("\n%c", caracter_leido);

        if(caracter_leido == 'a'){
            cantA++;
        }

    }

    printf("\nLa cantidad de espacios es:%d", cantA);

    //Paso 4 - cerrar archivo
    fclose(archivoTXT);


    return 0;

}

*/



  /////////////////
 //    FGETS    //
/////////////////
//  fgets(char* destino, cant, FILE*archivo);
//
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

    //Paso 3 - LEER
    while(fgets(buffer, 100,archivoTXT) != NULL){
        printf("%s",buffer);
    }



    //Paso 4 - cerrar archivo
    fclose(archivoTXT);
    return 0;

}

*/


  /////////////////
 //    FSCANF   //
/////////////////
//      fscanf(archivo,"%d-%d-%d",&nota1,&nota2,&nota3);
//
//Agarra una cadena de caracteres y la formatea a valores numericos y lo guarda en una variable
//
//Indica el formato que tiene el registro a leer.
//En este caso son 3 numeros enteros separados por un guion medio.
//
//      Cada uno de los tres valores se lee como un entero
//      y se almacena en la variable nota1, nota2 nota3 respectivamente.

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    //Declaraciones
    char buffer[100];
    int cantA = 0;
    char caracter_leido;
    float promedio;


    //Paso 1 -  Inicializamos
    FILE * archivoTXT;


    //Paso 2 - Abrimos el archivo
    archivoTXT = fopen("textoPrueba.txt","r");
    if(archivoTXT == NULL){  //validacion

        printf("No se pudo abrir el archivo\n");
        return 1;

    } else{
        printf("El archivo se abrio con exito\n\n");
    }

    //Paso 3 - LEER
    int nota1, nota2, nota3;
    while(fscanf(archivoTXT,"%d|%d|%d", &nota1, &nota2, &nota3) != EOF){
        printf("\n\n\nVAMOS A VISUALIZAR LAS NOTAS POR ALUMNO Y SACAR SU PROMEDIO:\n");

        printf("NOTA 1: %d\n", nota1);
        printf("NOTA 2: %d\n", nota2);
        printf("NOTA 3: %d\n", nota3);

        promedio = ((nota1 + nota2 + nota3)/3.0);
        printf("PROMEDIO: %.2f", promedio);
    }



    //Paso 4 - cerrar archivo
    fclose(archivoTXT);

    return 0;
}
*/







//********************************************************************

////////////////////////////////////////////////////////////
/////////          ESCRITURA DE ARCHIVOS            ///////
//////////////////////////////////////////////////////////


//////////////////////////////////
//para escribir un archivo se utilizan una de estas 3 funciones
//de la biblioteca stdio.h

//      fputc()  ESCRIBE CARACTER POR CARACTER
//      fputs()  ESCRIBE UN REGISTRO ( STRING )
//      fprintf() ESCRIBE FORMATEADA






  /////////////////
 //    FPUTC    //
/////////////////
//      fputc(caracter,archivo);
//Escribe caracter por caracter

//(EN ESCRITURA CON PUTC) "R+" sobrescribe desde el princio del archivo,
//y no desde el ultimo como A.


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    //Declaraciones
    char caracter[100];

    //Paso 1 -  Inicializamos
    FILE * archivoTXT2;


    //Paso 2 - Abrimos el archivo y elegimos el modo
    archivoTXT2 = fopen("textoPrueba2.txt","w");
    if(archivoTXT2 == NULL){  //validacion

        printf("No se pudo abrir el archivo\n");
        return 1;

    } else{
        printf("El archivo se abrio con exito\n\n");
    }


    //Paso 3 - ESCRIBIR
    for( int i = 'a'; i<'z'; i++){
        fputc(i,archivoTXT2);
    }


    //Paso 4 - cerrar archivo
    fclose(archivoTXT2);.
    return 0;
}


*/




  /////////////////
 //    FPUTS    //
/////////////////
//      fputs(string,archivo);
//
//      ESCRIBE STRING

/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    //Declaraciones
    char buffer[100];

    //Paso 1 -  Inicializamos
    FILE * archivoTXT2;


    //Paso 2 - Abrimos el archivo y elegimos el modo
    archivoTXT2 = fopen("textoPrueba2.txt","w");
    if(archivoTXT2 == NULL){  //validacion

        printf("No se pudo abrir el archivo\n");
        return 1;

    } else{
        printf("El archivo se abrio con exito\n\n");
    }


    //Paso 3 - ESCRIBIR
    char palabra[50];

    do{
        fflush(stdin);
        printf("\nIngrese una palabra:");
        scanf("%s", palabra);

        if(strcmp(palabra, "FIN") != 0){
            fputs(palabra,archivoTXT2);
        }

    }while(strcmp(palabra,"FIN") != 0);





    //Paso 4 - cerrar archivo
    fclose(archivoTXT2);

    return 0;
}

*/




  /////////////////
 //   FPRINTF   //
/////////////////
//      fprintf(archivo,"texto", variables);
//

//Es como un printf para mostrar en pantalla, pero en un archivo.
//Lo unico que cambia es que al principio pide el archivo donde se va a guardar.

/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    //Declaraciones
    char buffer[100];

    //Paso 1 -  Inicializamos
    FILE * archivoTXT2;


    //Paso 2 - Abrimos el archivo y elegimos el modo
    archivoTXT2 = fopen("textoPrueba2.txt","w");
    if(archivoTXT2 == NULL){  //validacion

        printf("No se pudo abrir el archivo\n");
        return 1;

    } else{
        printf("El archivo se abrio con exito\n\n");
    }


    //Paso 3 - ESCRIBIR
    char palabra1[20];
    fflush(stdin);
        printf("\nIngrese una palabra:");
        scanf("%s", palabra1);

    char palabra2[20];
    fflush(stdin);
        printf("\nIngrese una palabra:");
        scanf("%s", palabra2);

    char palabra3[20];
    fflush(stdin);
        printf("\nIngrese una palabra:");
        scanf("%s", palabra3);


    fprintf(archivoTXT2,"la pablabra1 es:%s\nLa palabra2 es:%s\nLa palabra3 es:%s\n ",palabra1, palabra2, palabra3);



    //Paso 4 - cerrar archivo
    fclose(archivoTXT2);

    return 0;
}

*/





//******************************************************************************
//PRACTICANDO
//******************************************************************************
/*
/////////////////
//    fgetc();



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    FILE * archivinTxt;

    archivinTxt = fopen("practicandoFGETC.txt", "r");
    if(archivinTxt == NULL)
    {
        printf("Error al leer el archivo\n");
    }
    else
    {
        printf("Se abrio el archivo con exito\n");
    }

    int cantidadEspacios = 0;
    char caracterLeido;
    while((caracterLeido = fgetc(archivinTxt)) != EOF)
    {
        if(caracterLeido == ' ')
        {
            cantidadEspacios++;
        }
        printf("%c", caracterLeido);
    }


    printf("La cantidad de espacios es %d\n",cantidadEspacios);


    fclose(archivinTxt);

    return 0;
}
*/

/*
///////////////////
//      fgets();

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char buffer[100];

    FILE * archivinTxt;
    archivinTxt = fopen("practicandoFGETS.txt","r");
    if(archivinTxt == NULL){
        printf("no se pudo abrir el archivo\n");
    }else{
        printf("archivo abierto con exito\n");
    }

    while((fgets(buffer, 100, archivinTxt)) != NULL){
        if(strcmp(buffer,"hola") == 0){
           printf("la palabra hola esta en el archivo");
        }
    }

    fclose(archivinTxt);

    return 0;
}
*/

/*
////////////////////
//      fscanf();

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    FILE * archivexTxt;
    archivexTxt = fopen("practicandoFSCANF.txt", "r");

    if(archivexTxt == NULL){

        printf("no se pudo abrir el archivo\n");
    }else {
        printf("archivo abierto con exito\n");
    }



    int nota1, nota2, nota3;
    float promedio;

    while((fscanf(archivexTxt,"%d-%d-%d",&nota1,&nota2,&nota3)) != EOF){

        printf("nota 1 es :%d \n", nota1);
        printf("nota 2 es :%d \n", nota2);
        printf("nota 3 es :%d \n\n", nota3);

        promedio=(nota1+nota2+nota3)/3.0;

        printf("el promedio es: %.2f \n", promedio);

    }



    fclose(archivexTxt);
    return 0;
}
*/



/*
////////////////////////////////////////
//      fputc();

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    FILE * archivexTxt;
    archivexTxt = fopen("practicandoFPUTC.txt", "a+");

    if(archivexTxt == NULL){
        printf("no se pudo abrir el archivo\n");
    }else {
        printf("archivo abierto con exito\n");
    }

    for(int i = 'a'; i < 150; i++){
        fputc(i, archivexTxt);
        printf("escribiendo el codigo ascii %i \n", i);
    }

    fclose(archivexTxt);

    return 0;
}

*/



/*
////////////////////////////////////////
//      fputs();

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    char palabra[50];

    FILE * archivexTxt;
    archivexTxt = fopen("practicandoFPUTS.txt", "a+");

    if(archivexTxt == NULL){
        printf("no se pudo abrir el archivo\n");
    }else {
        printf("archivo abierto con exito\n");
    }

    do{
        fflush(stdin);
        printf("Ingrese palabra\n\n");
        scanf("%s", palabra);

        if((strcmp(palabra,"FIN")) != 0){
            fputs(palabra,archivexTxt);
        }
    }while((strcmp(palabra,"FIN")) != 0);


    fclose(archivexTxt);

    return 0;
}

*/

/*

////////////////////////////////////////
//      fprintf();

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    char stringgg[20];
    strcpy(stringgg,"soy el string bro");
    FILE * archivinTxt;
    archivinTxt = fopen("practicandoFPRINTF.txt", "w");

    if(archivinTxt == NULL){
        printf("no se pudo abrir el archivo\n");
    }else {
        printf("archivo abierto con exito\n");
    }


    fprintf(archivinTxt,"aca escribimos el string: %s", stringgg);

    fclose(archivinTxt);

    return 0;
}


*/

//-------------------------------------------------------------

///////////////////////////////////////////
//////////  EJERCICIOS clase  ////////////
/////////////////////////////////////////




/*
//EJERCICIO 1


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Palabras{

    char palabra[29];
    int cantVocales;
    int cantConsonantes;
    int cantLetras;
};


struct Palabras procesarPalabra(char palabra[], FILE * archivo);

int main(){


    FILE * readingFile = fopen("palabras.txt", "r");
    if (readingFile == NULL){
        printf("no se pudo abrir el archivo palabras.txt \n");
    }else{
        printf("el archivo palabras.txt fue abierto con exito\n");
    }

    FILE * writingFile = fopen("estadisticas.txt", "w");
    if (writingFile == NULL){
        printf("no se pudo abrir el archivo estadisticas.txt \n");
        fclose(readingFile);
    }else{
        printf("el archivo estadisticas.txt fue abierto con exito\n");
    }


//  leer palabras y almacenarlas en struct
    char buffer[49];
    while((fgets(buffer,49,readingFile)) != NULL){

        buffer[strcspn(buffer, "\n")] = '\0';


        printf("\nLa palabra leida es:%s \n", buffer);

        //printf("Vamos a registrarla en un struct y procesarla\n");


        printf("La palabra %s fue registrada con exito en un struct\n",buffer);


        struct Palabras palabraEnProceso = procesarPalabra(buffer, writingFile);


        printf("Procedemos a escribir el archivo de registro con la informacion de cada palabra. . . \n");
        fprintf(writingFile, "%s>>>CANT LETRAS:%d|CONSONANTES:%d|VOCALES:%d\n", palabraEnProceso.palabra, palabraEnProceso.cantLetras, palabraEnProceso.cantConsonantes, palabraEnProceso.cantVocales);

    }




    fclose(readingFile);
    fclose(writingFile);

    return 0;
}


struct Palabras procesarPalabra(char palabra[], FILE * archivo){

    struct Palabras palabraProcesada;

    printf("Ahora vamos a procesar la palabra para encontrar cuantas vocales, consonantes y letras tiene. . .  \n");

    int consonantes = 0;
    int vocales = 0;
    char letras = 0;

    for(int i = 0; palabra[i] != '\0'; i++){

        letras++;

        //char caracterLeido;
        //caracterLeido = palabra[i];

        if(palabra[i] >= 'a' && palabra[i] <= 'z' ){
            palabra[i] = palabra[i] - 32;
        }


        if(palabra[i] == 'A' || palabra[i] == 'E' || palabra[i] == 'I' || palabra[i] == 'O' || palabra[i] == 'U' ){
            printf("Vocal detectada en el caracter leido.\n");
           // printf("Se procede a registrarla en el archivo -Estadisticas-\n");
            vocales++;
        }else{
            printf("Consonante detectada en el caracter leido.\n");
           // printf("Se procede a registrarla en el archivo -Estadisticas-\n");
            consonantes++;
        }
    }

    palabraProcesada.cantConsonantes = consonantes;
    palabraProcesada.cantVocales = vocales;
    palabraProcesada.cantLetras = letras;
    strcpy(palabraProcesada.palabra, palabra);

    printf("La palabra %s tiene %d vocales, %d consonantes y %d letras\n", palabra, vocales, consonantes, letras);

    return palabraProcesada;
}

*/



//EJERCICIO 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){





    return 0;
}












//-------------------------------------------------------------

///////////////////////////////////////////
//////////   EJERCICIOS PDF   ////////////
/////////////////////////////////////////



/////////////////
// EJERCICIO 1
//
//Basado en el siguiente formato de un archivo de texto:
//      campo1|campo2|campo3|campo4
//      campo1|campo2|campo3|campo4
//      campo1|campo2|campo3|campo4

//Donde el carácter „|‟ es usado como separador de campo,
//y cada línea representa un registro.
//Realizar una función que permita leer de un archivo con ese formato
//y extraer todos los datos para poder almacenarlo en un struct que represente
//cada registro leído y mostrarlo por pantalla.
//Por ejemplo: 21|99888777|Jorge Perez|28 sea almacenado
//en un struct que contenga los campos: legajo, dni, nombre_apellido y edad.
//Para la resolución de este ejercicio
//se recomienda utilizar funciones de string y punteros a char.



/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct persona {

    int legajo;
    char nombre[30];
    int dni;
    int edad;
};

int main(){

    //creamos puntero la archivo
    FILE * archivoTEXTO;

    //abirmos archivo
    archivoTEXTO = fopen("textoEjercicio1.txt", "r");
    if(archivoTEXTO == NULL){
        printf("No se pudo leer el archivo\n");
    }else{
        printf("archivo leido con exito\n");
    }


    //leer

    struct persona nuevo;

    while(fscanf(archivoTEXTO, "%d|%d|%s|%d", &nuevo.legajo, &nuevo.dni, nuevo.nombre, &nuevo.edad) != EOF){

        printf("Legajo:%d\n",nuevo.legajo);
        printf("Dni:%d\n",nuevo.dni);
        printf("Nombre:%s\n",nuevo.nombre);
        printf("Edad:%d\n",nuevo.edad);
    }

    //cerramos
    fclose(archivoTEXTO);

    return 0;
}
*/
