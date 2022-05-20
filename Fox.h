//
// Created by Damian on 12.04.2022.
//

#ifndef PROJEKT1_FOX_H
#define PROJEKT1_FOX_H
#include "Animal.h"
class Fox:public Animal{
public:
    Fox(World *presentWorld,int xPosition,int yPosition,int age);
    string getName()override;
    char shortName()override;
    void action()override;
    Organism* clone(int x,int y)override;
    ~Fox()override;
};
#endif //PROJEKT1_FOX_H
