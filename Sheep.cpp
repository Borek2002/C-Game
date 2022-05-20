//
// Created by Damian on 12.04.2022.
//
#include "Sheep.h"
Sheep::Sheep(World *presentWorld, int xPosition, int yPosition, int age)
: Animal(presentWorld,xPosition,yPosition,4,4,1,age,true ){}

string Sheep::getName() {
    return"Sheep";
}
char Sheep::shortName() {
    return 'S';
}
Organism* Sheep::clone(int x, int y) {
    return new Sheep(presentWorld,x,y,1);
}
Sheep::~Sheep(){};