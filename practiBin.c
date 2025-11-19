#include <stdio.h>
#include <stdlib.h>


struct Account {
        char user[30]; //30 bytes
        char pass[30]; //30 bytes
};

int main(){

    struct Account accounts[5];


    FILE * test = fopen("cuentasBin", "rb");
    if(test == NULL){
        printf("el archivo cuentasBin no existe, creamos uno nuevo");
        }else{printf("archivo cuentasBin encontrado, accediendo...");
    }


    FILE * archivoBin = fopen("cuentasBin","wb+");
    if(archivoBin == NULL) {printf("no se pudo abrir archivo cuentasBin");return 1;}


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










