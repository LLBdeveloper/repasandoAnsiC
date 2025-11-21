/*
CONSIGNA:
programa que escribe en un archi bin un vector de
5 struct de 2 elementos: passs y user en string

mostrar menu con 2 opciones


-function ver usuarios.
-function que te deje modificar una constrasena
		que seleccione  el usuario.
*/



//librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//constantes
#define MAX 5



//structs
struct Account {        // 60bytes total
        char user[30]; //30 bytes
        char pass[30]; //30 bytes
};


//prototipo de funciones
void verUsuarios(int cantMax, FILE * archivoBin, struct Account vector[]);
void modificarPass(int cantidad, FILE * archivo, struct Account vector[]);



//MAIN
int main(){
    int cantMax = MAX;
    struct Account accounts[cantMax];

    //verificamos que el archivo exista
    FILE * test = fopen("cuentasBin", "rb");
    if(test != NULL){
        fclose(test);
        printf("archivo cuentasBin encontrado, sobrescribir? ( S / N )\n");
        char resp;
        scanf("%c",&resp);
        if(resp != 's' && resp != 'S'){
            printf("no se puede seguir, saliendo del programa...\n");
            return 1;
        }
    }


    //abrimos el archivo binario de cuentas
    FILE * archivoBin = fopen("cuentasBin","wb+");
    if(archivoBin == NULL) {printf("no se pudo abrir archivo cuentasBin\n");return 1;}


    //pedimos los usuarios
    getchar();
    for(int i = 0; i < cantMax; i++) {
        printf("Ingrese usuario:\n");
        fgets(accounts[i].user, sizeof(accounts[i].user), stdin);
        accounts[i].user[strcspn(accounts[i].user, "\n")] = '\0'; //eliminar espacio

        printf("Ingrese pass:\n");
        fgets(accounts[i].pass, sizeof(accounts[i].pass), stdin);
        accounts[i].pass[strcspn(accounts[i].pass, "\n")] = '\0';//eliminar espacio
    }



    //escribimos el vector de usuarios en el archivo binario
    fwrite(accounts,sizeof(struct Account),cantMax,archivoBin);

    fseek(archivoBin,0,SEEK_SET);


    //MENU
    int boton;
    do{
        printf("MENU\n");
        printf("1 - ver usuarios\n");
        printf("2 - modificar usuario\n");
        printf("0 - SALIR\n");


        scanf("%d",&boton);

        switch(boton){
            case 1:
                verUsuarios(cantMax,archivoBin,accounts);
                break;
            case 2:
                modificarPass(cantMax,archivoBin,accounts);
                break;
            case 0:
                boton=9;
                break;

            default:
                printf("error - ingrese opcion 1 o 2 \n");
                break;
        }

    }while(boton != 9);


    fclose(archivoBin);

    return 0;
}




////////////////////
//FUNCIONES

void verUsuarios(int cantidad, FILE * archivo, struct Account vector[]){
    struct Account auxVec[30];
    fread(auxVec,sizeof(struct Account),cantidad,archivo);

    for(int i = 0; i<cantidad; i++){
        printf("cuenta numero%d \nusuario:%s\npass:%s \n",(i+1),vector[i].user, vector[i].pass);
    }
}










void modificarPass(int cantidad, FILE * archivo, struct Account vector[]){
    printf("ingrese el nombre del usuario de la cuenta que quiere modificar el pass:\n");


    //declaraciones
    int indexEncontrado;
    char aux[15];
    scanf("%s",aux);


    //bucle busqueda
    for(int i = 0; i<cantidad; i++){

        if(strcmp(aux,vector[i].user) == 0){
            indexEncontrado = i;
            printf("usuario %s encontrado, su numero de usuario es 000%d\n", aux, (indexEncontrado+1));
        }
    }


    //leer pass actual
    fseek(archivo,(indexEncontrado * sizeof(struct Account)),SEEK_SET);
    struct Account passViejo;
    fread(&passViejo,sizeof(struct Account),1,archivo);
    printf("pass actual: %s\n", passViejo.pass);

    //usuario ingresa el pass nuevo
    char passNuevo[15];
    printf("ingrese el nuevo pass:\n");
    scanf("%s",passNuevo);
    printf("el pass nuevo sera %s\nguardando cambios...\n", passNuevo);



    //actualizamos el vector
    strcpy(vector[indexEncontrado].pass, passNuevo);

    //escribimos la pass nueva al archivo bin
    fseek(archivo,(indexEncontrado * sizeof(struct Account)),SEEK_SET);
    fwrite(&vector[indexEncontrado],sizeof(struct Account),1,archivo);




    //confirmamos con lectura de archivo que se cambio pass
    fseek(archivo,(indexEncontrado * sizeof(struct Account)),SEEK_SET);
    struct Account auxPassNew;
    fread(&auxPassNew,sizeof(struct Account),1,archivo);
    printf("cambio de pass con exito en el proceso!!\nsu nuevo pass es: %s\n",auxPassNew.pass);

}











/*
int main(){

    int vector[3] = {2,10,70};


    FILE * binFile = fopen("archivillo","wb+");
    if(binFile == NULL) printf("nose pudo abrir el archivo che");


    fwrite(&vector,sizeof(int),3,binFile);

    int papelEnBlanco[3];

    fseek(binFile,0,SEEK_SET);

    fread(&papelEnBlanco,sizeof(int),3,binFile);

    for(int i=0;i<3;i++){
        printf(" registro de indice numero %d que escribiste recien en el archivo binario es: %d \n", i,papelEnBlanco[i]);
    }

    fclose(binFile);

    return 0;
}
*/










