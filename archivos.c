//ARCHIVOS  read-white-aniadir


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    FILE * archivoTXT;

    archivoTXT = fopen("miarchivo.txt","r");

    if(archivoTXT == NULL){

        printf("No se pudo abrir el archivo");
    } else{
        printf("El archivo se abrio con exito");
    }

}
