#include <stdio.h>


/*
//pasaje de struct en funciones

struct personaje{
    int hp;
    int mana;
    int fuerza;
};

 struct personaje crearPj();
 void show(struct personaje);

void main(){
    struct personaje buffer;
    buffer=crearPj();
    show(buffer);
}

struct personaje crearPj(){
    struct personaje pj;
    pj.hp=10;
    pj.mana=5;
    pj.fuerza=9;

    return pj;
}

void show(struct personaje pj){
    printf("Los atributos del pj son: hp=%d mana=%d fuerza=%d", pj.hp, pj.mana, pj.fuerza);
}


*/



//struct en vectores

struct personaje{
    int hp;
    int mana;
    int fuerza;
};


struct personaje crearPj();
void show(struct personaje);


void main(){
    struct personaje personajes[5];


}


struct personaje crearPj(){

    personajes[0].hp=100;
    personajes[0].mana=70;
    personajes[0].fuerza=20;





    return personajes[0];
};

void show(personajes[0]){
    printf("datos: hp=%d mana=%d fuerza=%d", personajes[0].hp, personajes[0].mana, personajes[0].fuerza);
}
















