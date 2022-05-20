//
// Created by Damian on 09.04.2022.
//
#include "Organism.h"
#include "World.h"

Organism::Organism(World *presentWorld, int xPosition, int yPosition, int initiative, int strenght,int range,int age,bool newBorn):presentWorld(presentWorld),
xPosition(xPosition),yPosition(yPosition),initiative(initiative),strenght(strenght),range(range),age(age),newBorn(newBorn) {}

int Organism::getXPosition() {return xPosition;}
int Organism::getYPosition() {return yPosition;}
int Organism::getInitiative() {return initiative;}
int Organism::getStrenght() {return strenght;}
int Organism::getAge() {return age;}
int Organism::getRange() {return range;}
bool Organism::getNewBorn() {return newBorn;}
void Organism::setXPosition(int x) { this->xPosition=x;}
void Organism::setStrengh(int s) { this->strenght=s;}
void Organism::setYPosition(int y) {this->yPosition=y;}
void Organism::setNewBorn(bool z) {this->newBorn=z;}
void Organism::makeMove(int x, int y) {
    int newX=x;
    int newY=y;
    presentWorld->getBoard()[this->getYPosition()][this->getXPosition()]= nullptr;
    presentWorld->getBoard()[newY][newX]=this;
    this->setYPosition(newY);
    this->setXPosition(newX);
}
int Organism::drawXPosition() {
    int x= this->getXPosition();
    int draw;
    bool left=true,right=true;
    if (x==0)left=false;
    if (presentWorld->getX()-1==x)right=false;
    while(true) {
        draw = rand() % 2;
        if (draw == 0&&left==true)return x - 1;
        else if (draw == 1&&right==true)return x + 1;
    }
}
int Organism::drawYPosition() {
    int y= this->getYPosition();
    int draw;
    bool up=true,down=true;
    if (y==0)up=false;
    if (presentWorld->getY()-1==y)down=false;
    while(true) {
        draw = rand() % 2;
        if (draw == 0&&up== true)return y - 1;
        else if (draw == 1&&down==true)return y + 1;
    }
}
int Organism::findFreeField(Organism *org) {
    int x= org->getXPosition();
    int y= org->getYPosition();
    bool left=true,right=true,up=true,down=true;
    if (x==0)left=false;
    if (presentWorld->getX()-1==x)right=false;
    if (y==0)up=false;
    if (presentWorld->getY()-1==y)down=false;
    int chance=-1;
    while(chance!=3) {
        chance=rand()%4;
        if (chance>=3&&left == true && presentWorld->getBoard()[y][x - 1] == nullptr) {
            return -1;
        } else if (chance>=2&&right == true && presentWorld->getBoard()[y][x + 1] == nullptr) {
            return 1;
        } else if (chance>=1&&up == true && presentWorld->getBoard()[y - 1][x] == nullptr) {
            return -2;
        } else if (chance>=0&&down == true && presentWorld->getBoard()[y + 1][x] == nullptr) {
            return 2;
        }
    }
    return 0;
}

Organism::~Organism() {}


