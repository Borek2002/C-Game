//
// Created by Damian on 12.04.2022.
//
#include "Fox.h"

Fox::Fox(World *presentWorld, int xPosition, int yPosition, int age)
: Animal(presentWorld,xPosition,yPosition,7,3,1,age,true){}

string Fox::getName() {
    return "Fox";
}
char Fox::shortName() {
    return 'F';
}
Organism* Fox::clone(int x, int y) {
    return new Fox(presentWorld,x,y,1);
}
void Fox::action() {
    int verorhor,newX,newY;
    age++;
    while(true) {
        verorhor = rand() % 2;
        if (verorhor == 0) {

            newX = drawXPosition();
            if (presentWorld->getBoard()[this->getYPosition()][newX] == nullptr ||
                presentWorld->getBoard()[this->getYPosition()][newX] ==
                presentWorld->getBoard()[this->getYPosition()][this->getXPosition()]) {
                makeMove(newX, this->getYPosition());
                cout<<this->getName()<<" move to ("<<this->getXPosition()<<", "<<this->getYPosition()<<")"<<endl;
                break;
            }
            else if (presentWorld->getBoard()[this->getYPosition()][newX]->getStrenght() <= this->getStrenght()) {
                collision(presentWorld->getBoard()[this->getYPosition()][newX]);
                break;
            }

        } else if (verorhor == 1) {
            newY = drawYPosition();
            if (presentWorld->getBoard()[newY][this->getXPosition()] == nullptr ||
                presentWorld->getBoard()[newY][this->getXPosition()] ==
                presentWorld->getBoard()[this->getYPosition()][this->getXPosition()]) {
                makeMove(this->getXPosition(), newY);
                cout<<this->getName()<<" move to ("<<this->getXPosition()<<", "<<this->getYPosition()<<")"<<endl;
                break;
            }//sprawdzam czy organizm nie jest silnieszy od lisa
            else if(presentWorld->getBoard()[newY][this->getXPosition()]->getStrenght() <= this->getStrenght()) {
                collision(presentWorld->getBoard()[newY][this->getXPosition()]);
                break;
            }
        }
    }

}
Fox::~Fox() {}