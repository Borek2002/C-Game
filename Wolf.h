//
// Created by Damian on 10.04.2022.
//

#ifndef PROJEKT1_WOLF_H
#define PROJEKT1_WOLF_H
#include "Animal.h"
class Wolf:public Animal{
public:
    Wolf(World *presentWorld,int xPosition,int yPosition,int age);
    string getName()override;
    char shortName()override;
    Organism* clone(int x,int y)override;
    ~Wolf()override;
};

#endif //PROJEKT1_WOLF_H
