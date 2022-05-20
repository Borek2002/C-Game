//
// Created by Damian on 13.04.2022.
//

#ifndef PROJEKT1_TURTLE_H
#define PROJEKT1_TURTLE_H
#include "Animal.h"
class Turtle:public Animal{
public:
    Turtle(World *presentWorld, int xPosiiton,int yPosition,int age);
    string getName()override;
    char shortName()override;
    void action()override;
    Organism* clone(int x,int y)override;
    ~Turtle()override;
};
#endif //PROJEKT1_TURTLE_H
