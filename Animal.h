//
// Created by Damian on 10.04.2022.
//

#ifndef PROJEKT1_ANIMAL_H
#define PROJEKT1_ANIMAL_H
#include "Organism.h"
class Animal:public Organism{
public:
    Animal(World *presentWorld,int xPosition,int yPosition,int initiative,int strenght,int range,int age,bool newBorn);
    string getName()override=0;
    char shortName()override=0;
    void breed(Organism *org);
    void action()override;
    void collision(Organism* occupied)override;

    ~Animal();
};
#endif //PROJEKT1_ANIMAL_H
