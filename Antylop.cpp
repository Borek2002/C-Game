//
// Created by Damian on 13.04.2022.
//
#include "Antylop.h"
Antylop::Antylop(World *presentWorld, int xPosition, int yPosition, int age)
: Animal(presentWorld,xPosition,yPosition,4,4,2,age,true){}

string Antylop::getName() {
    return "Antylop";
}
char Antylop::shortName() {
    return 'A';
}
Organism* Antylop::clone(int x, int y) {
    return new Antylop(presentWorld,x,y,1);
}
void Antylop::collision(Organism* occupied){
    int chance,verorhor,newX,newY;
    chance=rand()%2;
    if (chance==0){
        while(true) {
            verorhor = rand() % 2;
            if (verorhor == 0) {
                newX = drawXPosition();
                if (presentWorld->getBoard()[this->getYPosition()][newX] == nullptr ||
                    presentWorld->getBoard()[this->getYPosition()][newX] ==
                    presentWorld->getBoard()[this->getYPosition()][this->getXPosition()]) {
                    makeMove(newX, this->getYPosition());
                    cout<<"Antylop ran away from "<<occupied->getName()<<endl;

                    break;
                }
                else if(presentWorld->getBoard()[this->getYPosition()][newX] !=
                        presentWorld->getBoard()[this->getYPosition()][this->getXPosition()]) {
                    Animal::collision(presentWorld->getBoard()[this->getYPosition()][newX]);
                    break;
                }
            }

             else if (verorhor == 1) {
                newY = drawYPosition();
                if (presentWorld->getBoard()[newY][this->getXPosition()] == nullptr ||
                    presentWorld->getBoard()[newY][this->getXPosition()] ==
                    presentWorld->getBoard()[this->getYPosition()][this->getXPosition()]) {
                    makeMove(this->getXPosition(), newY);
                    cout<<"Antylop ran away from "<<occupied->getName()<<endl;
                    break;}
                else if(presentWorld->getBoard()[newY][this->getXPosition()] !=
                        presentWorld->getBoard()[this->getYPosition()][this->getXPosition()]){
                        Animal::collision(presentWorld->getBoard()[newY][this->getXPosition()]);
                        break;
                }
            }
        }
    }
}
Antylop::~Antylop()  {}
