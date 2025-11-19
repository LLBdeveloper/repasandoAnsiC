
//ARCHIVOS de texto

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



// ****************************************************************************

//      RESUMEN


/*

| **Función**                              | **Qué hace**                                             | **Qué devuelve**                                                      | **Cómo se compara correctamente** | **Ejemplo típico**                        |
| ---------------------------------------- | -------------------------------------------------------- | --------------------------------------------------------------------- | --------------------------------- | ----------------------------------------- |
| `fscanf(FILE*, const char*, …)`          | Lee datos con formato (como `scanf`, pero desde archivo) | Número de elementos leídos con éxito, o `EOF` si hay error/fin        | `== cantidadEsperada` o `!= EOF`  | `while (fscanf(f, "%d", &x) == 1)`        |
| `fgetc(FILE*)`                           | Lee un carácter del archivo                              | El carácter leído (como `int`), o `EOF` si termina el archivo         | `!= EOF`                          | `while ((c = fgetc(f)) != EOF)`           |
| `fgets(char*, int, FILE*)`               | Lee una línea de texto (hasta `\n` o fin de archivo)     | El puntero al buffer si tuvo éxito, o `NULL` si no                    | `!= NULL`                         | `while (fgets(buf, 100, f) != NULL)`      |
| `fputs(const char*, FILE*)`              | Escribe una cadena de texto completa en el archivo       | Valor positivo si tuvo éxito, o `EOF` si error                        | `!= EOF`                          | `if (fputs("Hola\n", f) != EOF)`          |
| `fprintf(FILE*, const char*, …)`         | Escribe datos con formato en el archivo (como `printf`)  | Cantidad de caracteres escritos, o valor negativo si hay error        | `>= 0`                            | `if (fprintf(f, "Edad: %d\n", edad) < 0)` |
| `putc(int, FILE*)` o `fputc(int, FILE*)` | Escribe **un solo carácter** en el archivo               | El carácter escrito (como `unsigned char`) si éxito, o `EOF` si error | `!= EOF`                          | `if (fputc('A', f) == EOF)`               |


*/

// ***************************************************************************

////////////////////////////////////////////////////////////
/////////           LECTURA DE ARCHIVOS             ///////
//////////////////////////////////////////////////////////


//////////////////////////////////
//para leer un archivo de texto se utilizan una de estas 3 funciones
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

/*Que devuelve fscanf()
Cuando usás una función como fscanf(), su valor de retorno (lo que devuelve)
te dice cuántos elementos logró leer correctamente.
Por ejemplo:
    int resultado = fscanf(archivo, "%f", &numero);
- Si logró leer un número flotante correctamente, resultado vale 1.

- Si llegó al final del archivo, o no pudo leer más datos, devuelve EOF (que vale -1).

- Si el formato del dato en el archivo no coincide (por ejemplo,
  hay letras en lugar de un número), devuelve 0.
*/



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
//Desarrollar un programa que permita leer palabras del archivo “palabras.txt”.
//Pasar cada palabra a mayúscula y obtener la cantidad de letras,vocales y consonantes.
/Por cada palabra procesada escribir el siguiente registro en el archivo
//“estadisticas.txt” PALABRA >>>CANT LETRAS: X | CONSONANTES: X | VOCALES: X




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

//A ESTE CODIGO LE FALTA PODER REGISTAR TODOS LOS MOVIMIENTOS EN UN ARCHIVO, lo demas esta OK


/*
Desarrollar un sistema que obtenga los montos (valores float)
de hasta 10 cajas de dinero desde un
archivo “cajas.txt” y los cargue en un vector.
Una vez que se cargaron los valores en el vector se mostrará
un menú con las siguiente funcionalidades:
1- Ingresar dinero.
Selecciona la caja y el monto a ingresar.
Actualiza el archivo “cajas.txt” con los nuevos montos.
Registra el movimiento agregando el registro
INGRESO>>>CAJA X>>>MONTO al archivo “movimientos.txt”

2- Extraer dinero.
Selecciona la caja y el monto a retirar
validando que haya dinero suficiente.
Si se pudo retirar el monto se actualiza el archivo “cajas.txt”
con los nuevos montos y agrega el
registro EGRESO>>>CAJA X>>>MONTO, en el archivo ‘movimientos.txt’
de lo contrario se agrega el registro ERROR_EGRESO>>>CAJA X>>>MONTO
en el archivo ‘movimientos.txt’
3- Listar cajas
0- Salir.
*/



/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movimiento{

    char tipo[20];
    int caja;
    float monto;

};


int cargarCajas(float* vec);
void ingresarDinero(float* vec, int cantCajas);
void listarCajas(float* vec, int cantCajas);
void extraerDinero(float* vec, int cantCajas);
void sobreEscribirCajas(float* vec, int cantCajas);





int main(){

    float cajas[10] = {0};
    int totalCantCajas;


    FILE * movFile = fopen("movimientos.txt","a");
    if (movFile == NULL){
        printf("no se pudo abrir el archivo movimientos.txt \n");
        return 1;
    }else{
        printf("el archivo movimientos.txt fue abierto con exito\n");
    }


    totalCantCajas = cargarCajas(cajas);


    int botonMenu;
    while(botonMenu != 999){
        printf("\n\nMENU:\n\n");
        printf("1 - INGRESAR DINERO\n");
        printf("2 - EXTRAER DINERO\n");
        printf("3 - LISTAR CAJAS\n");
        printf("\n0 - SALIR\n\n");

        fflush(stdin);
        printf("\nIngrese el numero de la opcion deseada:\n");
        scanf("%d",&botonMenu);

            switch(botonMenu){

                case 1:
                    printf("F1 - INGRESAR DINERO\n");
                    ingresarDinero(cajas, totalCantCajas);
                    sobreEscribirCajas(cajas, totalCantCajas);
                    break;

                case 2:
                    printf("F2 - EXTRAER DINERO\n");
                    extraerDinero(cajas, totalCantCajas);
                    sobreEscribirCajas(cajas, totalCantCajas);
                    break;

                case 3:
                    printf("F3 - LISTAR CAJAS\n");
                    listarCajas(cajas,totalCantCajas);
                    break;

                case 4:
                    sobreEscribirCajas(cajas, totalCantCajas);
                    break;

                case 0:
                    printf("Saliendo del programa . . .  \n");
                    botonMenu = 999;
                    break;

                default:
                    printf("Error - Ingrese una opcion valida\n");
                    break;
            }
    }





    fclose(movFile);

    return 0;
}


int cargarCajas(float * vec){

    int cantCajas = 0;
    float montoLeido;


    FILE * cajasFile = fopen("cajas.txt", "a+");
    if (cajasFile == NULL){
        printf("No se pudo abrir el archivo cajas.txt \n");
        return 1;
    }else{
        printf("El archivo cajas.txt fue abierto con exito\n");
    }


    while( (fscanf(cajasFile,"%f",&montoLeido)) != EOF){
        vec[cantCajas] = montoLeido;
        cantCajas++;
    }

    printf("cantidad de cajas: %d\n",cantCajas);


    fclose(cajasFile);

    return cantCajas;
}


void ingresarDinero(float* vec, int cantCajas){

    int cajaSolicitada;
    float montoIngreso;

    printf("Ingrese el numero de la caja que quiere usar:\n");
    scanf("%d", &cajaSolicitada);

    if( cajaSolicitada < 1 || cajaSolicitada > cantCajas){
        printf("La caja solicitada no existe\n");
    }else{
        printf("Ingreso con exito a la caja solicitada.\nSu saldo es de %.2f\n",vec[cajaSolicitada-1]);
        printf("Escriba el monto en $ a ingresar:\n");
        scanf("%f", &montoIngreso);
        vec[cajaSolicitada-1] += montoIngreso;
    }

}


void extraerDinero(float* vec, int cantCajas){

    int cajaSolicitada;
    float montoIngreso;

    printf("Ingrese el numero de la caja con la que necesita operar:\n");
    scanf("%d", &cajaSolicitada);

    if( cajaSolicitada < 1 || cajaSolicitada > cantCajas){
        printf("La caja solicitada no existe\n");
    }else{
        printf("Ingreso con exito a la caja solicitada.\nSu saldo es de %.2f\n",vec[cajaSolicitada-1]);
        printf("Escriba el monto en $ a extraer:\n");
        scanf("%f", &montoIngreso);
        vec[cajaSolicitada-1] -= montoIngreso;
    }
}




void listarCajas(float* vec, int cantCajas){
    printf("La cantidad total de cajas es de %d\n",cantCajas);
    for(int i = 0; i < cantCajas; i++){
        printf("La caja numero %d tiene un saldo de $%.2f\n", i+1, vec[i]);
    }
}




void sobreEscribirCajas(float* vec, int cantCajas){

    printf("Permisos obtenidos para modificar achivo cajas.txt  - SobreEscribir\n");

    FILE * cajasFile = fopen("cajas.txt","w");

    for(int i = 0; i<cantCajas; i++){
            fprintf(cajasFile,"%.2f\n", vec[i]);
            printf("escribimos la linea numero %d\n", i+1);
        }
    printf("Actualizamos los saldos de las cajas en el archivo cajas.txt\n");

    listarCajas(vec,cantCajas);

}



int agregarMovimientos(float* vec, int cantCajas){

    printf("Registramos movimiento");






    return 1;
}



*/










/*
123.12
321.21
456.65
654.45
*/





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
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


/*

/////////////////////////////////////////////////////////
// Manejo de archivos BINARIOS//////////////////////////
///////////////////////////////////////////////////////




    BINARIOS VS TEXTO


Archivos de texto:
    -Cada byte representa un caracter
    codificado en ascii

    -Registros de longitud variable
    Cada registro es leído como un string que
    finaliza con un salto de línea \n


    -El acceso es secuencial
    Para acceder a un registro particular se
    deben recorrer todos los registros anteriores.
    Para modificar un registro se debe
    sobreescribir todo el archivo



Archivos binarios:
    -Cada byte puede representar parte de
    un entero, un float, una estructura, etc.
    según el formato en el que se haya
    codificado.
    Contenido no legible para humanos.

    -Registros de longitud fija
    Cada registro es un conjunto de bytes de
    tamaño fijo.
    Por ejemplo registros de 2 bytes que
    representan un número entero short.


    -El acceso es aleatorio
    Permite acceder a un registro de forma
    directa sin necesidad de recorrer todos los
    anteriores.
    Se puede modificar un registro sin
    necesidad de sobreescribir todo el archivo



//////////////////////////////////////////////////

    PASOS A SEGUIR



    -Paso 1: Declarar el puntero FILE *  //  FILE * archivo;

    -Paso 2: Apertura de archivo //  archivo = fopen(ruta_archivo,modo);
    if(archivo == NULL)
    {
    return 1;
    }

    -Paso 3: Lectura o escritura
    size_t fwrite(void *puntero, size_t cant_bytes, size_t cant_reg, FILE * archivo)
        Puntero: Dirección del espacio de memoria con los datos que se van a escribir

        cant_bytes: Es la cantidad de bytes que ocupa un registro en el archivo.

        cant_reg: Es la cantidad de registros que se van a escribir el archivo

        archivo: Es el puntero FILE* que contiene la información del archivo que se abrió para escribir

        fwrite devuelve la cantidad de registros (bloques de N bytes) que se escribieron correctamente

    -Paso 4: Cierre




///////////////////////////

    ESCRITURA CON FWRITE (devuelve size_t con  la cantidad de registros escritos)



    formato/estructura:
    size_t fwrite(void *puntero, size_t cant_bytes, size_t cant_reg, FILE * archivo)

        void *puntero
        un puntero, direccion de memoria donde estan los datos que quiero escribir

        size_t cant_bytes
        cantidad de bytes que ocupa un registro ( struct va con sizeof()

        size_t cant_reg
        cantidad registros que queremos escribir

        FILE * archivo
        donde vamos a escribir


    NOTAS:
            -puede escribir todos los elementos de un vector con un solo llamado a la funcion fwrite
            -cada regitro va a tener un tamano fijo. Ej: un registro de 3 enteros de 4 bytes cada uno lo que da un total de 12 bytes cada registro

    //////////////////////////


    LECTURA CON FREAD (devuelve size_t con  la cantidad de registros leidos)



    formato/estructura:
    size_t fread(void *puntero, size_t cant_bytes, size_t cant_reg, FILE * archivo)

        void *puntero
        un puntero, direccion de memoria donde se almacenaran los registros leidos

        size_t cant_bytes
        cantidad de bytes que ocupa un registro ( struct va con sizeof() )

        size_t cant_reg
        cantidad registros que queremos leer

        FILE * archivo
        de donde vamos a leer


    NOTAS:
            -el espacio apuntado por 'puntero' debe tener el espacio suficiente para almacenar todos los registros leidos
            -debe ser del mismo tipo de dato
            Ej: si leen 10 registros de short debe ser 'short * puntero' y apuntar a un espacio que tenga 20 bytes.




///////////////////////////




    FSEEK

    formato/estructura:
    int fseek(FILE * archivo, long int desplazamiento, int origen)

    NOTAS:
            -nos permite un desplazamiento del puntero de lectura/escritura.
            -sirve para poder tener un acceso aleatorio a los registros del archivo.






///////////////////////////

EJEMPLO ESCRITURA:

///////////////////////////



Ejemplo: Escribir 5 números enteros short


    Apertura:“wb” Abre el archivo enmodo escritura binaria.
    Si no existe lo crea.Si existe lo trunca.

    FILE * archivoBIN;
    archivoBIN = fopen(“numeros.bin”, “wb”); //apertura
    if(archivoBIN == NULL) //validación
    {
    return 1;
    }

 ///////// opcion1

    Escritura de a un registro:
    Se escribe un registro en el archivo binario utilizando fwrite.

    short numero_ingresado;
    for(int i = 0; i < 5; i++)
    {
    printf(“Ingrese un número entero:\n”);
    scanf(“%hi”,&numero_ingresado);
    fwrite(&numero_ingresado,sizeof(short),1,archivoBIN);
    }

/////////// opcion2

    Escritura de todos los
    valores en un solo llamado:
    Primero se cargan todos los
    números en el vector y luego
    se escriben todos los valores
    en un solo llamado a fwrite


    short numeros[5]; //vector de 5 shorts de 2 bytes c/u
    for(int i = 0; i < 5; i++)
    {
    printf(“Ingrese un número entero:\n”);
    scanf(“%hi”,&numeros[i]);
    }
    fwrite(numeros,sizeof(short),5,archivoBIN);




FREAD devuelve la cantidad de archivos leidos con exito.

*/
