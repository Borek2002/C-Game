//
// Created by Damian on 10.04.2022.
//
#include "Wolf.h"
Wolf::Wolf(World *presentWorld, int xPosition, int yPosition, int age):
        Animal(presentWorld,xPosition,yPosition,5,9,1,age,true){};

string Wolf::getName() {
    return "Wolf";
}

char Wolf::shortName() {
    return 'W';
}
Organism *Wolf::clone(int x, int y) {
    return new Wolf(presentWorld,x,y,1);
}

Wolf::~Wolf(){};

