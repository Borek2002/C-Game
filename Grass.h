//
// Created by Damian on 14.04.2022.
//

#ifndef PROJEKT1_GRASS_H
#define PROJEKT1_GRASS_H
#include "Plant.h"
class Grass:public Plant{
public:
    Grass(World *presentWorld,int xPosiiton,int yPosiiton,int age);
    string getName();
    char shortName();
    Organism* clone(int x, int y) override;
    ~Grass();
};
#endif //PROJEKT1_GRASS_H
