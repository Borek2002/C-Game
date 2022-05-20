//
// Created by Damian on 14.04.2022.
//
#include "Grass.h"
Grass::Grass(World *presentWorld, int xPosiiton, int yPosiiton, int age)
:Plant(presentWorld,xPosition,yPosition,0,0,1,age,true){}

string Grass::getName() {
    return "Grass";
}

char Grass::shortName() {
    return char(22);
}
Organism *Grass::clone(int x, int y) {
    return new Grass(presentWorld,x,y,1);
}
Grass::~Grass(){}