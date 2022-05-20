//
// Created by Damian on 14.04.2022.
//

#ifndef PROJEKT1_DANDELION_H
#define PROJEKT1_DANDELION_H
#include "Plant.h"
class Dandelion:public Plant{
public:
    Dandelion(World *presentWorld,int xPosition,int yPosition,int age);
    string getName();
    char shortName();
    Organism* clone(int x,int y)override;
    ~Dandelion();
};
#endif //PROJEKT1_DANDELION_H
