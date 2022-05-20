//
// Created by Damian on 15.04.2022.
//

#ifndef PROJEKT1_WOLFBERRIES_H
#define PROJEKT1_WOLFBERRIES_H
#include "Plant.h"
class WolfBerries:public Plant{
public:
    WolfBerries(World *presentWorld,int xPosition,int yPosition,int age);
    string getName();
    char shortName();
    Organism* clone(int x,int y)override;
    ~WolfBerries();


};
#endif //PROJEKT1_WOLFBERRIES_H
