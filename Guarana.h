//
// Created by Damian on 15.04.2022.
//

#ifndef PROJEKT1_GUARANA_H
#define PROJEKT1_GUARANA_H
#include "Plant.h"
class Guarana:public Plant{
public:
    Guarana(World *presentWorld,int xPosition,int yPosition,int age);
    string getName();
    char shortName();
    Organism* clone(int x,int y)override;
    ~Guarana();


};
#endif //PROJEKT1_GUARANA_H
