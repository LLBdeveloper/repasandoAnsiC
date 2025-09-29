/* Convenciones de nombres en C



🔹 Tipos y structs

PascalCase (mayúscula al inicio, cada palabra con mayúscula).

Ejemplo:

typedef struct {
    int id;
    char nombre[30];
} Personaje;






🔹 Variables

snake_case (todo minúscula, palabras separadas por _).

Ejemplo:

int cantidad_personajes;
Personaje mario;







🔹 Funciones

También snake_case, verbos que indiquen acción.

Ejemplo:

void crear_personaje(Personaje* personajes, int* cantidad);






🔹 Constantes y macros

MAYÚSCULAS con guiones bajos.

Ejemplo:

#define MAX_PERSONAJES 100
const int VIDA_INICIAL = 10;   // (si usás const)







🔹 Punteros

Se acostumbra a poner p_ o algo que indique que es puntero.

Ejemplo:

Personaje* p_personajes;






🔹 Archivos

todo en minúscula, palabras separadas con _.

Ejemplo: main.c, personajes.h, combate.c.



///////////////////////////////////////////
///////////////////////////////////////////



📌 Resumen rápido (para el parcial)

struct y typedef → PascalCase

Variables → snake_case

Funciones → snake_case, verbos claros

Constantes/macros → MAYÚSCULAS

Archivos → minúsculas (y snake_case)



*/
