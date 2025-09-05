////////////////////////
//REPASO DE LENGUAJE C//
////////////////////////


//si el codeblock se pone en sobrescribir  tocar tecla INS ;)


//identificadores
//
//son validos: letras, digitos y el caracter _ (guion bajo)
//siempre deben comenzar con una letra
//distingue entre mayuscula y minuscula







//operadores relacionales


// ==
// !=
// <
// >
// <=
// >=


//operadores logicos

//and
//&&

//or
//||

// not
// !




//caracteres de control

// \n permite pasar a una linea nueva
// \t tabular horizontalmente
// \v permite tabular vertical
// \a indica sonido de alerta
// \' escribe un apostrofe
// \" escribe comilas
// \\ escribe diagonal invertida


#include <stdio.h> // importar libreria basica

    //estructura   - agrupa datos de distinto tipo bajo un mismo nombre
struct Persona {
    char nombre[20];
    int edad ;
    int altura ;
};




void funcioncita() {

printf("\n hola soy la funcioncita vro");

}




int main() {

    // tipos de datos
    //////////////////

    //caracter
    char letra = 'z'; // va con comillas simples, es el unico

    //cadena de caracteres
    char cadena [] = "soy una cadena";

    //numeros enteros
    int enteros = 2;

    //numeros decimel y reales
    float decimal = 0.45;

    //constante
    const int constante = 14;


    //sizeof()    devuelve el tamano en BYTES de un dato o variable
    printf("el tamanio de por ejemplo constante es: %zu bytes\n", sizeof(constante));


    //array (vector) lista ?
    int array_num [5] = {1, 2, 3, 4, 5};

    //listas de string poner el *
    int *animales [2] = {"perro","gato"};



    // declarar persona1 con struct persona
    struct Persona persona1 = { "juan perez", 25, 180};
    //imprimir en pantalla datos de struct persona
    printf("\n Nombre: %s\n Edad: %d \n Altura: %d cm \n", persona1.nombre, persona1.edad, persona1.altura);




    //input numero
    int entrada_num ;
    scanf("%d", &entrada_num);
    //imprimir en pantalla mensaje:  tipo de dato, nombre
    printf("Usted ingreso: %d", entrada_num);


    // Limpiar el buffer de entrada: Cuando usas scanf() para leer enteros o caracteres || Cuando hay entradas mixtas (scanf() y fgets())
    while (getchar() != '\n');  // Descarta todos los caracteres hasta el '\n'


    //input string
    printf("\n ingrese una frase: ");
    char texto [20]; // Buffer para 19 caracteres + '\0'
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0'; // Elimina el salto de línea del fgets
    printf("\n Usted ingreso:  %s\n", texto);






    //condicionales y bucles//



    //estructuras selectivas

    //if
    int g=0;
    if(g==0){
      printf("\nel condicional dio verdadero en el IF\n");
    };

    //if en una linea sin else
    if(g==0) printf("soy el if de una linea\n");

    //if else operador TERNARIO
    g==0 ? printf("soy el if operador ternario en verdadero\n") : printf("soy el if operador ternario en verdadero\n");

    //if else comun
    if(g==0){
        printf("soy el if comun en verdadero\n");
    } else {
        printf("soy el if comun en falso\n");
    };

    // else if con doble condicional
    if(g==0){
        printf("soy el if comun en verdadero\n");
    } else if (g==1) {
        printf("soy el if else verdadero\n");
    } else {
        printf("soy el else\n");
    };




    //switch

    int valor = 2; //variable de prueba
    switch (valor){
        case 1:
            printf("\nsoy el caso 1 del switch\n");
            break;
        case 2:
            printf("\nsoy el caso 2 del switch\n");
            break;
        case 3:
            printf("\nsoy el caso 3 del switch\n");
            break;
        default:
            printf("\nno es un caso valido");
    };



    //estructuras repetitivas

    //for
    int a;
    for(a=0; a<4; a++){ //mientras a sea menor  a 4
        printf("hola soy el for %d jeje\n", a);
    };





    //while
    int i = 0;
    while (i <= 5) {  //mientras i sea menor o igual a 5
        printf("numero del while: %d\n", i);
        i++;
    }

   //do while es como el while pero se ejecuta al menos una vez antes de ver la condicion
    int z=0;
     do {
        if (z == 0) {
            printf("\nhola vamos a contar ! ! !\n");
        } else {
            printf("contador es %d\n", z);
        }
        z++;
    } while (z < 5);


 // la condicion con OPERADOR TERNARIO(?: manera resumida de expresar lo mismo, mas elegante, funcionamiento igual)
 // quedaria asi:
    do{
        z==0 ? printf("\nhola vamos a contar ! ! !\n") : printf("contador es %d\n", z);
        z++;
    } while(z<5);






    //FUNCIONES


    //poner al final de las funciones return 0;

    //funciones con parametro o argumento
    int funcioncita (num1, num2) {
       return num1 + num2;
    };
    //imprimir el resultado
    printf("\n la funcion retorna: %d\n" ,funcioncita(2,3));


    void funcion_void (){
        printf("soy la funcion VOID que no devuelve nada jeje ");

    };


    funcion_void();









    return 0;
}
