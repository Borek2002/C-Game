//
// Created by Damian on 12.04.2022.
//

#ifndef PROJEKT1_SHEEP_H
#define PROJEKT1_SHEEP_H
#include "Animal.h"
class Sheep:public Animal{
public:
    Sheep(World *presentWorld,int xPosition,int yPosiiton,int age);
    string getName()override;
    char shortName()override;
    Organism* clone(int x,int y)override;
    ~Sheep()override;
};
#endif //PROJEKT1_SHEEP_H
