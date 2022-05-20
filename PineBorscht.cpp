//
// Created by Damian on 16.04.2022.
//
#include "PineBorscht.h"
#include "Animal.h"
PineBorscht::PineBorscht(World *presentWorld, int xPosition, int yPosition, int age)
        :Plant(presentWorld,xPosition,yPosition,0,10,1,age,true){}

string PineBorscht::getName() {
    return "Borscht";
}

char PineBorscht::shortName() {
    return char(43);
}
Organism *PineBorscht::clone(int x, int y) {
    return new PineBorscht(presentWorld,x,y,1);
}

void PineBorscht::action() {
    for (int i = 0; i < 4; i++) {//bo 4 mozliwe miejsca
        int y=getYPosition();
        int x=getXPosition();
        if (y>0){//sprawdzanie czy nie jest na koncu planszy
            if (Animal* ani=dynamic_cast<Animal*>(presentWorld->getBoard()[y-1][x])){//sprawdzam czy dziedziczy po Animal
                cout<<"Pine Borscht kill "<<presentWorld->getBoard()[y-1][x]->getName()<<endl;
                presentWorld->remove(presentWorld->getBoard()[y-1][x]);
            }
        }
        if(y<presentWorld->getY()-1){
            if (Animal* ani=dynamic_cast<Animal*>(presentWorld->getBoard()[y+1][x])){//sprawdzam czy dziedziczy po Animal
                cout<<"Pine Borscht kill "<<presentWorld->getBoard()[y+1][getXPosition()]->getName()<<endl;
                presentWorld->remove(presentWorld->getBoard()[y+1][getXPosition()]);}
        }
        if (x>0){
            if (Animal* ani=dynamic_cast<Animal*>(presentWorld->getBoard()[y][x-1])){//sprawdzam czy dziedziczy po Animal
                cout<<"Pine Borscht kill "<<presentWorld->getBoard()[y][x-1]->getName()<<endl;
                presentWorld->remove(presentWorld->getBoard()[y][x-1]);}
        }
        if (x<presentWorld->getX()-1){
            if (Animal* ani=dynamic_cast<Animal*>(presentWorld->getBoard()[y][x+1])){//sprawdzam czy dziedziczy po Animal
                cout<<"Pine Borscht kill "<<presentWorld->getBoard()[y][x+1]->getName()<<endl;
                presentWorld->remove(presentWorld->getBoard()[y][x+1]);}
        }
    }
    Plant::action();
}
PineBorscht::~PineBorscht() {}
