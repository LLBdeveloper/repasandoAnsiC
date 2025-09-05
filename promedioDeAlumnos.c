#include <stdio.h>
#include <string.h>


struct alumno{

    int id;
    char nombre[20];
    char apellido[20];
    int dni;
    int nota1;
    int nota2;
    int promedio;

};

int main (void) {
    printf("---------------------------------------------------");
    printf("\nBienvenido, ingrese los datos de 3 alumnos. Al terminar de ingresarlos podra ver por pantalla los datos del alumno con mejor promedio");
    printf("\n---------------------------------------------------");

    struct alumno alumnos[3];
    int indiceMejor = 1;
    int i;

    for(i=0; i<3; i++){
        alumnos[i].id = i + 1;

        printf("\n \n Alumno: %d \n", alumnos[i].id);
        printf("\nIngrese su nombre: ");
        fflush(stdout);
        fgets(alumnos[i].nombre, sizeof(alumnos[i].nombre), stdin);
        alumnos[i].nombre[strcspn(alumnos[i].nombre, "\n")] = '\0';

        printf("\nIngrese su apellido: ");
        fflush(stdout);
        fgets(alumnos[i].apellido,sizeof(alumnos[i].apellido), stdin);
        alumnos[i].apellido[strcspn(alumnos[i].apellido, "\n")] = '\0';

        printf("\nIngrese su dni: ");
        scanf("%d", &alumnos[i].dni);

        printf("\nIngrese su nota1: ");
        scanf("%d", &alumnos[i].nota1);

        printf("\nIngrese su nota2: ");
        scanf("%d", &alumnos[i].nota2);

        alumnos[i].promedio = (alumnos[i].nota1 + alumnos[i].nota2) / 2;

        getchar(); // Limpia el salto de línea después de scanf
        printf("\n --- \n");

    }

        //encontramos el mayor promedio

    for(i=1; i<3; i++){
        if(alumnos[i].promedio> alumnos[indiceMejor].promedio){
            alumnos[i].promedio> alumnos[indiceMejor].promedio;
        }
    }

     // Mostrar datos del alumno con mejor promedio
    printf("\n=== Alumno con mejor promedio ===\n");
    printf("ID: %d\n", alumnos[indiceMejor].id);
    printf("Nombre: %s\n", alumnos[indiceMejor].nombre);
    printf("Apellido: %s\n", alumnos[indiceMejor].apellido);
    printf("DNI: %d\n", alumnos[indiceMejor].dni);
    printf("Nota 1: %d\n", alumnos[indiceMejor].nota1);
    printf("Nota 2: %d\n", alumnos[indiceMejor].nota2);
    printf("Promedio: %d\n", alumnos[indiceMejor].promedio);

    return 0;
}
