//
// Created by Damian on 14.04.2022.
//

#ifndef PROJEKT1_PLANT_H
#define PROJEKT1_PLANT_H
#include "Organism.h"
class Plant:public Organism{
public:
    Plant(World *presentWorld,int xPosition,int yPosition,int initiative,int strenght,int range,int age,bool newBorn);
    string getName()override=0;
    char shortName()override=0;
    void action()override;
    void collision(Organism* occupied)override;
    ~Plant();
};
#endif //PROJEKT1_PLANT_H
