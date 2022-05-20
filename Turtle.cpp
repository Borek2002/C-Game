//
// Created by Damian on 13.04.2022.
//
#include "Turtle.h"
Turtle::Turtle(World *presentWorld, int xPosiiton, int yPosition, int age)
: Animal(presentWorld,xPosiiton,yPosition,1,2,1,age, true){}

string Turtle::getName() {
    return"Turtle";
}
char Turtle::shortName() {
    return'T';
}
Organism* Turtle::clone(int x, int y) {
    return new Turtle(presentWorld,x,y,1);
}
void Turtle::action(){
    int chance;
    chance=rand()%4;
    if (chance==3)Animal::action();
}

Turtle::~Turtle() {}