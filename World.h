//
// Created by Damian on 09.04.2022.
//

#ifndef PROJEKT1_WORLD_H
#define PROJEKT1_WORLD_H
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <vector>

using namespace std;
class Organism;

class World{
private:
    int X,Y;
    int turn=1;
    int currentSize=0;
    int maxSize=X*Y;
    int coolDown=0;
    bool humanAbility=false;
public:

    World(int X,int Y);
    World(int X, int Y, std::ifstream &loadFile);
    void add(Organism *neworg);
    void remove(Organism *neworg);
    int getCurrentSize();
    void setCoolDown(int x);
    void setTurn(int x);
    int getCoolDown();
    void setHumanAbility(bool x);
    bool getHumanAbility();
    int getX();
    int getY();
    void drawWorld();
    void makeTurn();
    void randomPlace(Organism *newone);
    void place(Organism *newone,int xPosition,int yPosition);
    void saveWorld();
    Organism ***board;
    vector<Organism*> livingOrganisms;
    Organism ***getBoard();
    ~World();
};


#endif //PROJEKT1_WORLD_H
