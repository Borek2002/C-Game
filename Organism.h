//
// Created by Damian on 09.04.2022.
//

#ifndef PROJEKT1_ORGANISM_H
#define PROJEKT1_ORGANISM_H
#include <iostream>
#include "World.h"
#include <string>

using namespace std;
class Organism{
protected:
    World *presentWorld;
    int xPosition;
    int yPosition;
    int strenght;
    int initiative;
    int age;
    int range;
    bool newBorn;
public:
    Organism(World *presentWorld,int xPosition,int yPosition,int initiative,int strenght,int range,int age,bool newBorn);
    int getXPosition();
    int getYPosition();
    int getStrenght();
    int getAge();
    int getRange();
    int getInitiative();
    int drawXPosition();
    int drawYPosition();
    int findFreeField(Organism *org);
    bool getNewBorn();
    void setXPosition(int x);
    void setYPosition(int y);
    void setStrengh(int s);
    void setNewBorn(bool z);
    void makeMove(int x,int y);
    virtual void action()=0;
    virtual void collision(Organism* occupied)=0;
    virtual Organism* clone(int x,int y)=0;
    virtual char shortName()=0;
    virtual string getName()=0;
    virtual ~Organism();
};
#endif //PROJEKT1_ORGANISM_H
