//
// Created by Damian on 13.04.2022.
//

#ifndef PROJEKT1_ANTYLOP_H
#define PROJEKT1_ANTYLOP_H
#include "Animal.h"
class Antylop:public Animal{
public:
    Antylop(World *presentWorld,int xPosition,int yPosition,int age);
    string getName()override;
    char shortName()override;
    void collision(Organism *occupied)override;
    Organism* clone(int x,int y)override;
    ~Antylop()override;
};
#endif //PROJEKT1_ANTYLOP_H
