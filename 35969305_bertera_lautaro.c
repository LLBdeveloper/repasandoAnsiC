/////////////////////////////////////////////////////////////////////////////
// Archivo: 35969305_BERTERA_LAUTARO.c
// Materia: Estructura de Datos y Algoritmos I
// Trabajo: Punto de Control - Sistema de Gestion de Personajes
//
// Alumno: Lautaro BERTERA - 35969305
// Docentes: ING. Muriel CUCCETTI | TEC. Darío LALANNE | Delfina GÓMEZ
//
// Cuatrimestre: 2° Cuatrimestre 2025
// Comision: Jueves Noche
// Fecha de entrega: 01/10/2025
//
// DESCRIPCION: Sistema de gestion de personajes para juego de cartas.
//              Permite crear buscar y ver personajes, mejorar atributos y simular
//              combates utilizando memoria dinamica y validacion de datos.
/////////////////////////////////////////////////////////////////////////////




/////////////////////////
// Librerías
/////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/////////////////////////
// Declaracion de structs
/////////////////////////
struct Personaje {
    int id;
    char nombre[30];
    int nivel;
    int vida;
    int ataque;
    int defensa;
    int puntosMejora;
};


/////////////////////////
// Prototipos de funciones
/////////////////////////
void crearPersonaje(struct Personaje* listaPersonajes, int* cantidadTotal);
void mejorarPersonaje(struct Personaje* listaPersonajes, int cantidadTotal);
struct Personaje* buscarPorNombre(struct Personaje* personajes, int cantidadTotal, char* nombre);
struct Personaje* buscarPorId(struct Personaje* personajes, int cantidadTotal, int id);
void mostrarPersonaje(struct Personaje* personajes, int cantidadTotal);
void mostrarTodos(struct Personaje* personajes, int cantidadTotal);
void luchar(struct Personaje* personajes, int cantidadTotal);
void mostrarMasVivo(struct Personaje* personajes, int cantidadTotal);
struct Personaje* cargarDesdeBinario(struct Personaje* personajes, int *cantidadTotal, int *capacidadMax);
void guardarEnBinario(struct Personaje* personajes, int cantidadTotal);



/////////////////////////
// MAIN
/////////////////////////
int main() {
    //declaramos contador de personajes total y su puntero
    int contadorPersonajes = 0;
    int* pContadorPersonajes = &contadorPersonajes;

    //pedimos un maximo de personajes y lo almacenamos en el heap
    printf("Cuantos personajes como maximo se podran registrar???\n");
    int* maxCharacters = (int*)malloc(sizeof(int));
    if (maxCharacters == NULL) {
        printf("- Error - Memoria no disponible\n");
        return 1;
    }
    scanf("%d", maxCharacters);
    printf("El maximo de personajes para este juego es: %d\n", *maxCharacters);

    //reservamos espacio en el heap para el vector de estructuras Personaje
    struct Personaje* personajes = (struct Personaje*)malloc(*maxCharacters * sizeof(struct Personaje));
    if (personajes == NULL) {
        printf("Error: No se cargo a listado de personajes\n");
        return 1;
    }

    //menu
    int botonMenu;
    do {
        printf("\n\n\n\n--- MENU ---\n\n\n");
        printf("1 - Crear personaje\n");
        printf("2 - Mejorar personaje\n");
        printf("3 - Luchar\n");
        printf("4 - Buscar y ver personaje\n");
        printf("5 - Ver todos los personajes\n");
        printf("6 - Ver personaje/s con mas vida\n");
        printf("7 - Cargar personajes desde archivo binario\n");
        printf("8 - Guardar personajes en archivo binario\n");
        printf("0 - Salir\n");
        printf("\n Elige una opcion: ");
        scanf("%d", &botonMenu);

        switch (botonMenu) {
            case 1:
                if (*pContadorPersonajes < *maxCharacters) {
                    crearPersonaje(personajes, pContadorPersonajes);
                } else {
                    printf("No hay lugar para personajes");
                }
                break;

            case 2:
                mejorarPersonaje(personajes, *pContadorPersonajes);
                break;

            case 3:
                luchar(personajes, *pContadorPersonajes);
                break;

            case 4:
                mostrarPersonaje(personajes,*pContadorPersonajes);
                break;

            case 5:
                mostrarTodos(personajes,*pContadorPersonajes);
                break;

            case 6:
                mostrarMasVivo(personajes,*pContadorPersonajes);
                break;


            case 7:
                personajes = cargarDesdeBinario(personajes, pContadorPersonajes, maxCharacters);
                break;

            case 8:
                guardarEnBinario(personajes, *pContadorPersonajes);
                break;


            case 0:
                printf("EXIT\n");
                botonMenu = 0;
                break;


            default:
                printf("- ERROR - Ingreso invalido\n");
                break;
        }
    } while (botonMenu != 0);

    //liberamos memoria
    free(maxCharacters);
    free(personajes);

    return 0;
}






/////////////////////////
// Funciones
/////////////////////////




/////////////////////////
//funcion crearPersonaje
//crea un nuevo struct Personaje con atributos por defecto,id unico y nombre unico. Lo almacena directamente en el heap
void crearPersonaje(struct Personaje* listaPersonajes, int* cantidadTotal) {
    printf("\n\n\n\n\n\n");

    //declaraciones
    struct Personaje* nuevo = listaPersonajes + *cantidadTotal;
    char nombreIngresado[30];
    int valido = 0;

    //validar nombre unico
    while (!valido) {
        printf("Ingrese el nombre para su nuevo personaje: ");
        scanf("%s", nombreIngresado);

        valido = 1;
        for (int i = 0; i < *cantidadTotal; i++) {
            if (strcmp((listaPersonajes + i)->nombre, nombreIngresado) == 0) {
                printf("Ya existe un personaje con ese nombre. Usa otro.\n");
                valido = 0;
            }
        }
    }
    strcpy(nuevo->nombre, nombreIngresado);

    //asignar id unico y atributos por defecto
    nuevo->id = *cantidadTotal + 1;
    nuevo->nivel = 1;
    nuevo->vida = 10;
    nuevo->ataque = 1;
    nuevo->defensa = 1;
    nuevo->puntosMejora = 10;

    //distribuir los puntos de mejora iniciales
    int opcion;
    while (nuevo->puntosMejora > 0) {
        printf("\nDistribuir los puntos de mejora (%d restantes):\n", nuevo->puntosMejora);
        printf("1 - Agregar en Vida (actual: %d)\n", nuevo->vida);
        printf("2 - Agregar en ataque (actual: %d)\n", nuevo->ataque);
        printf("3 - Agregar en defensa (actual: %d)\n", nuevo->defensa);
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                nuevo->vida++;
                nuevo->puntosMejora--;
                break;
            case 2:
                nuevo->ataque++;
                nuevo->puntosMejora--;
                break;
            case 3:
                nuevo->defensa++;
                nuevo->puntosMejora--;
                break;
            default:
                printf("- ERROR - \nOpcion invalida, selecciona entre los numeros 1 / 2 / 3 \n");
                break;
        }
    }
    //actualizamos la cantidad
    (*cantidadTotal)++;

    //resultado
    printf("\n\n\nPersonaje '%s' creado con exito! (ID: %d)\n\n\n\n", nuevo->nombre, nuevo->id);
    printf("\n-Atributos del nuevo personaje- \nVida: %d, Ataque: %d, Defensa: %d, Nivel: %d\n",
           nuevo->vida, nuevo->ataque, nuevo->defensa, nuevo->nivel);
}


/////////////////////////
//funcion mejorarPersonaje
//el usuario puede asignaa lospuntos de mejora a un personaje buscado por nombre
void mejorarPersonaje(struct Personaje* listaPersonajes, int cantidadTotal) {

    //declaciones
    char buscado[30];
    int auxEleccion;

    //pedimos al usuario nombre para realizxar la busqueda
    printf("\n\n\n\n\n\n");
    printf("Ingrese el nombre del personaje a mejorar: ");
    scanf("%s", buscado);

    //asignacion
    struct Personaje* personajeActual = buscarPorNombre(listaPersonajes, cantidadTotal, buscado);

    //verificaciones
    if (personajeActual == NULL) {
        printf("\nNo existe un personaje con ese nombre.\n");
        return;
    }
    if (personajeActual->puntosMejora <= 0) {
        printf("\n%s No tiene puntos de mejora disponibles\n", personajeActual->nombre);
        return;
    }

    //bucle principal. su funcion es asignar puntos hasta agotarlos
    do {
        printf("\n%s tiene %d puntos de mejora disponibles\n", personajeActual->nombre, personajeActual->puntosMejora);
        printf("1 - Agregar en VIDA\n");
        printf("2 - Agregar en ATAQUE\n");
        printf("3 - Agregar en DEFENSA\n");
        printf("Elige una opcion: ");
        scanf("%d", &auxEleccion);

        switch (auxEleccion) {
            case 1:
                personajeActual->vida++;
                personajeActual->puntosMejora--;
                break;
            case 2:
                personajeActual->ataque++;
                personajeActual->puntosMejora--;
                break;
            case 3:
                personajeActual->defensa++;
                personajeActual->puntosMejora--;
                break;
            default:
                printf("Opcion invalida, elige 1, 2 o 3\n");
                break;
        }
    }while(personajeActual->puntosMejora > 0);

    //resultado
    printf("\nProceso de mejora finalizado para %s\n\n", personajeActual->nombre);
}


/////////////////////////
//funcion buscarPorNombre
//busca personaje por nombre con aritmetica de punteros y lo devuelve
struct Personaje* buscarPorNombre(struct Personaje* personajes, int cantidadTotal, char* nombre) {

    //declaraciones
    struct Personaje* pProcesado = personajes;
    struct Personaje* encontrado = NULL;

    //bucle que compara hasta encontrar coincidencia en nombre
    for (int i = 0; i < cantidadTotal; i++){
        if (strcmp((pProcesado + i)->nombre, nombre) ==0){
            encontrado = (pProcesado + i);
        }
    }
    return encontrado; //devuelve personaje encontrado
}



/////////////////////////
//funcion buscarPorId
//busca personaje por ID entre el total y lo devuelve
struct Personaje* buscarPorId(struct Personaje* personajes, int cantidadTotal, int id){

    //declaraciones
    struct Personaje* pProcesado = personajes;
    struct Personaje* encontrado = NULL;

    //bucle que compara hasta encontrar coincidencia en id
    for (int i = 0; i < cantidadTotal; i++){
        if ((pProcesado + i)->id == id){
            encontrado = (pProcesado + i);
        }
    }
    return encontrado; //devuelve personaje encontrado
}



/////////////////////////
//funcion mostrarPersonaje
//mostramos un personaje buscado por id
void mostrarPersonaje(struct Personaje* personajes, int cantidadTotal){
    printf("\n\n\n\n\n\n");

    //declaraciones
    int auxId;

    //pedimos id para buscar
    printf("Ingrese ID del personaje que quiere ver:");
    scanf("%d",&auxId);

    //asignamos puntero a lo que devuelve la funcion buscarPorId
    struct Personaje* encontrado = buscarPorId(personajes, cantidadTotal, auxId);

    //verificamos y mostramos personaje encontrado
    if (encontrado == NULL){
        printf("ERROR: Personaje con ID %d no encontrado\n", auxId);
    }else{
        printf("\n - PERSONAJE ENCONTRADO!! -\n");
        printf("ID: %d\n", encontrado->id);
        printf("Nombre: %s\n", encontrado->nombre);
        printf("Nivel: %d\n", encontrado->nivel);
        printf("Vida: %d\n", encontrado->vida);
        printf("Ataque: %d\n", encontrado->ataque);
        printf("Defensa: %d\n", encontrado->defensa);
        printf("Puntos de Mejora: %d\n", encontrado->puntosMejora);
    }
}



/////////////////////////
//funcion mostrar
//muestra todos los personajes con el detalle de sus atributos
void mostrarTodos(struct Personaje* personajes, int cantidadTotal){

    //verificamos que hay personajes
    if (cantidadTotal == 0) {
        printf("No hay personajes creados\n");
        return;
    }

    //mostarmos todos los personajes
    printf("\n\n- TODOS LOS PERSONAJES - \n\n");
    for(int i=0; i < cantidadTotal; i++){
        printf("ID: %d\n", (personajes + i)->id);
        printf("Nombre: %s\n", (personajes + i)->nombre);
        printf("Nivel: %d\n", (personajes + i)->nivel);
        printf("Vida: %d\n", (personajes + i)->vida);
        printf("Ataque: %d\n", (personajes + i)->ataque);
        printf("Defensa: %d\n", (personajes + i)->defensa);
        printf("Puntos de Mejora: %d\n\n\n", (personajes + i)->puntosMejora);
    }
}



/////////////////////////
//funcion luchar
//muestra todos los personajes, pide al usuario que seleccione dos personajes, ejecutar la pelea y muestra los resultados
void luchar(struct Personaje* personajes, int cantidadTotal){
    printf("\n\n\n\n\n\n");

    //verificamos que tengamos personajes creados
    if (cantidadTotal < 2) {
        printf("No hay un minimo de dos personajes creados\n");
        return;
    }
    //mostramos todos los existentes por medio de la funcion mostrarTodos
    mostrarTodos(personajes, cantidadTotal);

    //pedimos al usuario los id
    int auxIdAtacante;
    int auxIdDefensor;
    printf("\n\n\n Seleccione dos personajes para luchar: \n\n");
    printf("\nIngrese ID del personaje que sera asignado ATACANTE:\n");
    scanf("%d", &auxIdAtacante);
    printf("\nIngrese ID del personaje que sera asignado DEFENSOR:\n");
    scanf("%d", &auxIdDefensor);
    //verifiamos que no ingrese el mismo
    if (auxIdAtacante == auxIdDefensor) {
        printf("ERROR: No se puede elegir el mismo personaje dos veces\n");
        return;
    }
    //capturamos los dos personajes que el usuario selecciona y se presentan los luchadores
    struct Personaje* atacante = buscarPorId(personajes, cantidadTotal, auxIdAtacante);
    struct Personaje* defensor = buscarPorId(personajes, cantidadTotal, auxIdDefensor);

    //inicia la pelea con presentacion de luchadores
    printf("\n\n\n\n");
    printf("\n\n    - - - - - - - -  %s  vs %s  - - - - - - - - -\n\n\n",atacante->nombre,defensor->nombre);

    printf("\n\nATRIBUTOS DEL JUGADOR ATACANTE\n\n\n");
    printf("Nombre: %s\n", atacante->nombre);
    printf("Nivel: %d\n", atacante->nivel);
    printf("Vida: %d\n", atacante->vida);
    printf("Ataque: %d\n", atacante->ataque);
    printf("Defensa: %d\n", atacante->defensa);

    printf("\n\nATRIBUTOS DEL JUGADOR DEFENSOR\n\n\n");
    printf("Nombre: %s\n", defensor->nombre);
    printf("Nivel: %d\n", defensor->nivel);
    printf("Vida: %d\n", defensor->vida);
    printf("Ataque: %d\n", defensor->ataque);
    printf("Defensa: %d\n", defensor->defensa);



    //lee las reglas del juego
    printf("<<<<< LAS REGLAS DEL COMBATE >>>>>\ndanio = ataqueAtacante MENOS defensaDefensor\n");
    printf("     Si danio queda en 0 o menos: Gana el defensor y recibe +2 puntos de mejora       \n");
    printf("     Si es mayor a cero: Gana el atacante y se le resta el danio a la vida del defensor. El atacante recibe +1 punto de mejora o +3 y sube de nivel si el defensor muere.\n");


    printf("\n\n\n           !!!! ARRANCA LA PELEA !!!!  \n\n\n",atacante->nombre,defensor->nombre);

    //sacamos la cuenta del danio total
    int danio = (atacante->ataque - defensor->defensa);
    printf("\n           ----- DANIO TOTAL %d ------\n\n \n", danio);


    //estructuraa de control  principal
    //basada en el valor del danio calculado (danio = ataque - defensa)
    if(danio<=0){
        //GANA DEFENSOR
        printf("\n            Gana el defensor llamado %s!!!!!!!!!!!\n\n\n", defensor->nombre);
        printf("El defensor recibe +2 puntos de mejora\n\n");
        defensor->puntosMejora += 2;
    }else{
        if(defensor->vida > 0){

            //GANA ATACANTE

            printf("                Gana el atacante de nombre %s!!!!!!!!!!!\n\n\n",atacante->nombre);

            printf("El atacante recibe +1 punto demejora\n\n");
            atacante->puntosMejora += 1;

            printf("\n\n\n\nSe le resta el danio a la vida del defensor! \nVida actual del defensor: %d \n\n", defensor->vida);
            defensor->vida = defensor->vida - danio;
        }else{
            //GANA ATACANTE Y MUERE DEFENSOR
            printf("\n               Gana atacante de nombre %s y muere el defensor de nombre %s!!!!!!!!!!!\n\n\n",atacante->nombre, defensor->nombre);

            printf("El atacante de nombre %srecibe +3 puntos de mejora y sube de nivel\n\n",atacante->nombre); //cuando muere el def
            atacante->puntosMejora += 3;
            atacante->nivel += 1;

            printf("\n\n\n\nSe le resta el danio a la vida del defensor \nVida actual del defensor: %d \n\n", defensor->vida);
            defensor->vida = defensor->vida - danio;
        }
    }
}


/////////////////////////
//funcion mostrarMasVivo
//muestra el o los personaje/s con mas vida en sus atributos
void mostrarMasVivo(struct Personaje* personajes, int cantidadTotal){

    // verificamos
    if (cantidadTotal == 0) {
        printf("\nNo hay personajes creados\n");
        return;
    }

    // puntero aux
    struct Personaje* p = personajes;

    // encontrar la mayor vida
    int maxVida = (p)->vida;
    for (int i = 1; i < cantidadTotal; i++) {
        if ((p + i)->vida > maxVida) {
            maxVida = (p + i)->vida;
        }
    }

    // mostrar
    printf("\n--- Personaje/s con mayor VIDA (%d) ---\n\n", maxVida);
    int encontrados = 0;
    for (int i = 0; i < cantidadTotal; i++) {
        struct Personaje* actual = personajes + i;
        if (actual->vida == maxVida) {
            printf("ID: %d\n", actual->id);
            printf("Nombre: %s\n", actual->nombre);
            printf("Nivel: %d\n", actual->nivel);
            printf("Vida: %d\n", actual->vida);
            printf("Ataque: %d\n", actual->ataque);
            printf("Defensa: %d\n", actual->defensa);
            printf("Puntos de Mejora: %d\n\n", actual->puntosMejora);
            encontrados++;
        }
    }

    if(encontrados == 0){
        printf("no se encontraron personajes con vida \n");
    }
}


/////////////////////////
//funcion cargarDesdeBinario
// cargar todos los personajes desde un archivo binario
struct Personaje* cargarDesdeBinario(struct Personaje* personajes, int *cantidadTotal, int *capacidadMax){

    char nombre[50];
    printf("\n ingrese el nombre del archivo binario: ");
    scanf("%s", nombre);

    FILE *bin = fopen(nombre, "rb");
    if(bin == NULL){
        printf("\n error: no se pudo abrir el archivo\n");
        return personajes;
    }

    // cantidad total de bytes
    fseek(bin, 0, SEEK_END);
    int bytes = ftell(bin);
    fseek(bin, 0, SEEK_SET);

    // cantidad de personajes en el archivo
    int cantArchivo = bytes / sizeof(struct Personaje);
    printf("\n el archivo contiene %d personajes\n", cantArchivo);

    // si archivo tiene mas personajes que la capacidad actual ampliar
    if(cantArchivo > *capacidadMax){

        int nuevaCapacidad = cantArchivo;

        struct Personaje *tmp = realloc(personajes, nuevaCapacidad * sizeof(struct Personaje));
        if(tmp == NULL){
            printf("\n error: no se pudo ampliar con realloc\n");
            fclose(bin);
            return personajes;
        }

        personajes = tmp;
        *capacidadMax = nuevaCapacidad;

        printf("\n nueva capacidad ajustada a %d\n", *capacidadMax);
    }

    // leer todos los personajes del archivo
    int leidos = fread(personajes, sizeof(struct Personaje), cantArchivo, bin);
    fclose(bin);

    *cantidadTotal = leidos;

    printf("\n se cargaron %d personajes desde el archivo\n", leidos);

    return personajes;
}





/////////////////////////
//funcion guardarEnBinario
//  guarda todos los personajes actuales en un archivo binario
void guardarEnBinario(struct Personaje* personajes, int cantidadTotal){

    char nombre[50];
    printf("\n ingrese el nombre del archivo donde guardar: ");
    scanf("%s", nombre);

    // si existe pedir confirmacion
    FILE *test = fopen(nombre, "rb");
    if(test != NULL){
        fclose(test);

        char resp;
        printf("\n el archivo ya existe, desea sobreescribirlo? ( s / n ): ");
        scanf(" %c", &resp);

        if(resp != 's' && resp != 'S'){
            printf("\n no se guardo nada\n");
            return;
        }
    }

    // abrir archivo para escribir en modo binario
    FILE *bin = fopen(nombre, "wb");
    if(bin == NULL){
        printf("\n error: no se pudo abrir el archivo para guardar\n");
        return;
    }

    //guardar todos los personajes
    fwrite(personajes, sizeof(struct Personaje), cantidadTotal, bin);
    fclose(bin);

    printf("\n se guardaron %d personajes en el archivo\n", cantidadTotal);
}




































































/*

consigna

void crearPersonaje(Personaje* personajes, int* cantidad);

void mejorarPersonaje(Personaje* personajes, int cantidad);

void luchar(Personaje* personajes, int cantidad);

Personaje* buscarPorNombre(Personaje* personajes, int
cantidad,  char* nombre);

Personaje* buscarPorId(Personaje* personajes, int cantidad,
int id);

void mostrarPersonaje(Personaje p);

void mostrarTodos(Personaje* personajes, int cantidad);
//////

//memo din
int *arr = (int*)malloc(5 * sizeof(int));  array de 5 enteros en heap

int *arr = (int*)calloc(5, sizeof(int));  array de 5 enteros inicializados a 0

int *new_arr = (int*)realloc(arr, 5 * sizeof(int));

//archivos texto estructuras
int fgetc(FILE *stream); Lee un carácter del archivo. Devuelve el carácter leído o EOF si llega al final.
char *fgets(char *str, int n, FILE *stream); Lee una línea (hasta \n o máximo n-1 caracteres).Devuelve el puntero str o NULL si hay error
int fscanf(FILE *stream, const char *formato, ...); Lee texto formateado desde el archivo (como scanf pero desde archivo).Devuelve número de elementos leídos.
int fputc(int c, FILE *stream);Escribe un carácter en el archivo. Devuelve el carácter escrito o EOF si hay error.
int fputs(const char *str, FILE *stream);Escribe una cadena en el archivo.Devuelve un valor negativo si hay error.
int fprintf(FILE *stream, const char *formato, ...); .Devuelve número de caracteres escritos.Escribe texto formateado en el archivo (como printf pero hacia archivo)

//archivos bin estructuras
size_t fread(void *ptr, size_t size, size_t count, FILE *stream); // size=tamano cada elementro count=cant elementos
size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);


// &vec[2] es igual que poner (P+2)
//vec[2] es igual que poner *(p+2)

funcion(int vec[]) = funcion(int *vec) pasar vector por referencia a func


//STR
linea[strcspn(linea, "\n\r")] = '\0';  sacar SALTO de LINEA

char *strcpy(char *dest, const char *src); copiar

int strcmp(const char *str1, const char *str2); comparar
 -0 si son iguales. <0 si str1 < str2. >0 si str1 > str2

size_t strlen(const char *str); Devuelve la longitud de la cadena (sin contar el '\0').



//fgetc
    while((caracter_leido = fgetc(archivoTXT)) != EOF){
        printf("\n%c", caracter_leido);
        if(caracter_leido == 'a'){
            cantA++;
        }
    }

//fgets
    while(fgets(buffer, 100,archivoTXT) != NULL){
        printf("%s",buffer);
    }

//fscanf
    int nota1, nota2, nota3;
    while(fscanf(archivoTXT,"%d|%d|%d", &nota1, &nota2, &nota3) != EOF){
        printf("\n\n\nVAMOS A VISUALIZAR LAS NOTAS POR ALUMNO Y SACAR SU PROMEDIO:\n");

        printf("NOTA 1: %d\n", nota1);
        printf("NOTA 2: %d\n", nota2);
        printf("NOTA 3: %d\n", nota3);

        promedio = ((nota1 + nota2 + nota3)/3.0);
        printf("PROMEDIO: %.2f", promedio);
    }


    fprintf
        fprintf(archivoTXT2,"la pablabra1 es:%s\nLa palabra2 es:%s\nLa palabra3 es:%s\n ",palabra1, palabra2, palabra3);


*/













