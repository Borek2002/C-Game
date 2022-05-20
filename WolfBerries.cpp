//
// Created by Damian on 15.04.2022.
//
#include "WolfBerries.h"
WolfBerries::WolfBerries(World *presentWorld, int xPosition, int yPosition, int age)
        :Plant(presentWorld,xPosition,yPosition,0,99,1,age,true){}

string WolfBerries::getName() {
    return "Berries";
}

char WolfBerries::shortName() {
    return char(29);
}
Organism *WolfBerries::clone(int x, int y) {
    return new WolfBerries(presentWorld,x,y,1);
}
WolfBerries::~WolfBerries() {}
