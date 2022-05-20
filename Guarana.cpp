//
// Created by Damian on 15.04.2022.
//
#include "Guarana.h"
Guarana::Guarana(World *presentWorld, int xPosition, int yPosition, int age)
        :Plant(presentWorld,xPosition,yPosition,0,0,1,age,true){}

string Guarana::getName() {
    return "Guarana";
}

char Guarana::shortName() {
    return char(250);
}
Organism *Guarana::clone(int x, int y) {
    return new Guarana(presentWorld,x,y,1);
}
Guarana::~Guarana() {}
