//
// Created by Damian on 10.04.2022.
//
#include "Animal.h"

Animal::Animal(World *presentWorld, int xPosition, int yPosition, int initiative, int strenght,int range, int age,bool newBorn):
Organism(presentWorld,xPosition,yPosition,initiative,strenght,range,age,newBorn) {};

void Animal::breed(Organism *org) {
    int newPosition=findFreeField(org);
    if (newPosition==1){
        presentWorld->place(clone(org->getXPosition()+newPosition,org->getYPosition()),org->getXPosition()+newPosition,org->getYPosition());
        cout<<"New "<<org->getName()<<" born on ("<<org->getXPosition()+newPosition<<", "<<org->getYPosition()<<")"<<endl;
    }
    if (newPosition==-1){
        presentWorld->place(clone(org->getXPosition()+newPosition,org->getYPosition()),org->getXPosition()+newPosition,org->getYPosition());
        cout<<"New "<<org->getName()<<" born on ("<<org->getXPosition()+newPosition<<", "<<org->getYPosition()<<")"<<endl;
    }
    if (newPosition==2){
        presentWorld->place(clone(org->getXPosition(),org->getYPosition()+newPosition-1),org->getXPosition(),org->getYPosition()+newPosition-1);
        cout<<"New "<<org->getName()<<" born on ("<<org->getXPosition()<<", "<<org->getYPosition()+newPosition-1<<")"<<endl;
    }
    if (newPosition==-2){
        presentWorld->place(clone(org->getXPosition(),org->getYPosition()+newPosition+1),org->getXPosition(),org->getYPosition()+newPosition+1);
        cout<<"New "<<org->getName()<<" born on ("<<org->getXPosition()<<", "<<org->getYPosition()+newPosition+1<<")"<<endl;
    }
}

void Animal::action() {
    int verorhor,newX=this->getXPosition(),newY=this->getYPosition();
    age++;
    for (int i = 0; i < this->getRange(); i++) {
        verorhor = rand() % 2;
        if (verorhor == 0) {
            newX = drawXPosition();
            if (presentWorld->getBoard()[this->getYPosition()][newX] == nullptr){
                makeMove(newX, this->getYPosition());
                cout<<this->getName()<<" move to ("<<this->getXPosition()<<", "<<this->getYPosition()<<")"<<endl;}
            else {
                collision(presentWorld->getBoard()[this->getYPosition()][newX]);
            }
        }
        else if (verorhor == 1) {
            newY = drawYPosition();
            if (presentWorld->getBoard()[newY][this->getXPosition()] == nullptr ){
                makeMove(this->getXPosition(), newY);
                cout<<this->getName()<<" move to ("<<this->getXPosition()<<", "<<this->getYPosition()<<")"<<endl;}
            else {
                collision(presentWorld->getBoard()[newY][this->getXPosition()]);
            }
        }
        if (presentWorld->getBoard()[newY][newX]!=this)
            break;
    }
}

void Animal::collision(Organism *occupied) {
    Organism *oc=occupied;
    if (oc->getName()=="Turtle"&&this->getStrenght()<5){
        cout<<oc->getName()<<" fight off the "<<this->getName()<<" atack"<<endl;
    }
    else if (oc->getName()==this->getName()&&oc!=this){
        if (findFreeField(this)!=0){
            breed(this);
        }
        else if(findFreeField(oc)!=0){
            breed(oc);
        }
        else{
            cout<<"There's no open field to give birth "<<this->getName()<<endl;
        }
    }
    else if(oc->getName()=="Guarana"){
        this->setStrengh((this->getStrenght()+3));
        presentWorld->remove(occupied);
        makeMove(oc->getXPosition(), oc->getYPosition());
        cout<<this->getName()<<" move to ("<<oc->getXPosition()<<", "<<oc->getYPosition()<<")"<<endl;
        cout<< this->getName()<<" eat guarana, new strengh "<<this->getStrenght()<<endl;
        free(oc);
    }
    else if(oc->getName()=="Pine Borscht"||oc->getName()=="Wolf Berries"){
        cout << occupied->getName() << " kill3 " << this->getName() << endl;
        presentWorld->remove(this);
    }
    else{
        if (occupied->getStrenght() > this->getStrenght()) {
            cout<<this->getName()<<" move to ("<<oc->getXPosition()<<", "<<oc->getYPosition()<<")"<<endl;
            cout << occupied->getName() << " kill0 " << this->getName() << endl;
            presentWorld->remove(this);}
        else if (occupied->getStrenght() <= this->getStrenght()) {
            cout<<this->getName()<<" move to ("<<oc->getXPosition()<<", "<<oc->getYPosition()<<")"<<endl;
            cout << this->getName() << " kill1 " << occupied->getName() << endl;
            presentWorld->remove(occupied);
            makeMove(oc->getXPosition(), oc->getYPosition());
            free(oc);
        }
    }
}
Animal::~Animal(){
};