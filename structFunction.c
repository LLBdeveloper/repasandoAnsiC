#include <stdio.h>

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
