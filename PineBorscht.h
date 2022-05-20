//
// Created by Damian on 16.04.2022.
//

#ifndef PROJEKT1_PINEBORSCHT_H
#define PROJEKT1_PINEBORSCHT_H
#include "Plant.h"
class PineBorscht:public Plant{
public:
    PineBorscht(World *presentWorld,int xPosition,int yPosition,int age);
    string getName();
    char shortName();
    Organism* clone(int x,int y)override;
    void action()override;
    ~PineBorscht();


};
#endif //PROJEKT1_PINEBORSCHT_H
