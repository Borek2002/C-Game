//
// Created by Damian on 14.04.2022.
//
#include "Dandelion.h"
Dandelion::Dandelion(World *presentWorld, int xPosition, int yPosition, int age)
:Plant(presentWorld,xPosition,yPosition,0,0,3,age,true){}

string Dandelion::getName() {
    return "Dandelion";
}

char Dandelion::shortName() {
    return char(176);
}
Organism *Dandelion::clone(int x, int y) {
    return new Dandelion(presentWorld,x,y,1);
}
Dandelion::~Dandelion() {}