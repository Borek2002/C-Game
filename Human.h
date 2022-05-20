//
// Created by Damian on 22.04.2022.
//

#ifndef PROJEKT1_HUMAN_H
#define PROJEKT1_HUMAN_H
#include "Animal.h"
#include <conio.h>
class Human:public Animal{

public:
    Human(World *presentWorld,int xPosition,int yPosition,int age);
    string getName()override;
    bool getAbility();
    void setAbility(bool ability);
    char shortName()override;
    void specialAbility();
    void action()override;
    Organism* clone(int x,int y)override;
    void collision(Organism* occupied)override;
    ~Human();
};
#endif //PROJEKT1_HUMAN_H
