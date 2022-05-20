//
// Created by Damian on 14.04.2022.
//
#include "Plant.h"
Plant::Plant(World *presentWorld, int xPosition, int yPosition, int initiative, int strenght,int range, int age,bool newBorn)
:Organism(presentWorld,xPosition,yPosition,initiative,strenght,range,age,newBorn){}

void Plant::action() {
    int verorhor,newX,newY;
    age++;
    for (int i = 0; i < this->getRange(); i++) {
        int chance;
        chance=rand()%3;
        if (chance==1) {
            verorhor = rand() % 2;//bo x y
            if (verorhor == 0) {
                newX = drawXPosition();
                if (presentWorld->getBoard()[this->getYPosition()][newX] == nullptr) {
                    presentWorld->place(clone(newX, this->getYPosition()), newX, this->getYPosition());
                    cout << "A new " << this->getName() << " is born" << endl;
                }
            } else if (verorhor == 1) {
                newY = drawYPosition();
                if (presentWorld->getBoard()[newY][this->getXPosition()] == nullptr) {
                    presentWorld->place(clone(this->getXPosition(), newY), this->getXPosition(), newY);
                    cout << "A new " << this->getName() << " is born" << endl;
                }
            }
        }
    }
}
void Plant::collision(Organism *occupied) {

}
Plant::~Plant() {}