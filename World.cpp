//
// Created by Damian on 09.04.2022.
//
#include "World.h"
#include "Organism.h"
#include "Animal.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antylop.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "WolfBerries.h"
#include "PineBorscht.h"
#include "Human.h"
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;


int World::getCurrentSize() {
    return currentSize;
}
int World::getCoolDown() {
    return coolDown;
}
void World::setCoolDown(int x) {
    this->coolDown=x;
}
void World::setTurn(int x) {
    this->turn=x;
}
bool World::getHumanAbility() {
    return humanAbility;
}
void World::setHumanAbility(bool x) {
    this->humanAbility=x;
}
int World::getX() {
    return X;
}
int World::getY() {
    return Y;
}
Organism*** World::getBoard() {
    return board;
}
void World::add(Organism *neworg) {
    int i=0;
    while(currentSize!=i){
        if (livingOrganisms[i]->getInitiative()<neworg->getInitiative()){
            livingOrganisms.insert(livingOrganisms.begin()+i,neworg);
            break;
        }
        else if (livingOrganisms[i]->getInitiative()==neworg->getInitiative()){
            if (livingOrganisms[i]->getAge()<=neworg->getAge()){
                livingOrganisms.insert(livingOrganisms.begin()+i,neworg);
                break;
            }
        }

        i++;
    }
    if (currentSize==i) livingOrganisms.insert(livingOrganisms.begin()+i,neworg);
    currentSize++;
}
void World::remove(Organism *neworg) {
    int i=0;
    board[neworg->getYPosition()][neworg->getXPosition()]=nullptr;
    while(i!=currentSize){
        if (livingOrganisms[i]==neworg){
            livingOrganisms.erase(livingOrganisms.begin()+i);
            break;
        }
        i++;
    }
    currentSize--;
}

void World::randomPlace(Organism *newone) {
    int newXPosition,newYPosition;
    while(true){
        newXPosition=rand()%(X-1);
        newYPosition=rand()%(Y-1);
        if (board[newYPosition][newXPosition]== nullptr) {
            newone->setXPosition(newXPosition);
            newone->setYPosition(newYPosition);
            board[newYPosition][newXPosition] = newone;
            add(newone);

            break;
        }
    }
}

void World::place(Organism *newone,int xPosition,int yPosition) {
    newone->setXPosition(xPosition);
    newone->setYPosition(yPosition);
    board[yPosition][xPosition]=newone;
    add(newone);
}

World::World(int X, int Y):X(X),Y(Y){
    printf("Witaj w nowym swiecie o wymiarach %dx%d\n",X,Y);
    srand(time(NULL));
    board = new Organism** [Y];
    for (int i = 0; i < Y; i++) {
        board[i]=new Organism*[X];
    }
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            board[i][j] = nullptr;
        }
    }
    randomPlace(new Fox(this,-1,-1,1));
    randomPlace(new Fox(this,-1,-1,1));
    randomPlace(new Wolf(this,-1,-1,1));
    randomPlace(new Wolf(this,-1,-1,1));
    randomPlace(new Sheep(this,-1,-1,1));
    randomPlace(new Sheep(this,-1,-1,1));
    randomPlace(new Turtle(this,-1,-1,1));
    randomPlace(new Turtle(this,-1,-1,1));
    randomPlace(new Antylop(this,-1,-1,1));
    randomPlace(new Antylop(this,-1,-1,1));
    randomPlace(new Grass(this,-1,-1,1));
    randomPlace(new Dandelion(this,-1,-1,1));
    randomPlace(new Guarana(this,-1,-1,1));
    randomPlace(new WolfBerries(this,-1,-1,1));
    randomPlace(new PineBorscht(this,-1,-1,1));
    randomPlace(new Human(this,-1,-1,1));
}
World::World(int X, int Y, std::ifstream &loadFile):X(X),Y(Y) {
    srand(time(NULL));
    board = new Organism** [Y];
    for (int i = 0; i < Y; i++) {
        board[i]=new Organism*[X];
    }
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            board[i][j] = nullptr;
        }
    }
    string name;
    int age,xP,yP;
    while(loadFile>>name){
        loadFile>>xP>>yP>>age;
        if(name=="Antylop"){ place(new Antylop(this,-1,-1,age),xP,yP);
        }
        else if(name=="Fox"){
            place(new Fox(this,-1,-1,age),xP,yP);
        }
        else if(name=="Sheep"){
            place(new Sheep(this,-1,-1,age),xP,yP);
        }
        else if(name=="Wolf"){
            place(new Wolf(this,-1,-1,age),xP,yP);
        }
        else if(name=="Turtle"){
            place(new Turtle(this,-1,-1,age),xP,yP);
        }
        else if(name=="Dandelion"){
            place(new Dandelion(this,-1,-1,age),xP,yP);
        }
        else if(name=="Borscht"){
            place(new PineBorscht(this,-1,-1,age),xP,yP);
        }
        else if(name=="Berries"){
            place(new WolfBerries(this,-1,-1,age),xP,yP);
        }
        else if(name=="Grass"){
            place(new Grass(this,-1,-1,age),xP,yP);
        }
        else if(name=="Guarana"){
            place(new Guarana(this,-1,-1,age),xP,yP);
        }
        else if(name=="Human"){
            place(new Human(this,-1,-1,age),xP,yP);
        }

    }
}

void World::makeTurn() {
    for (int i = 0; i < currentSize; i++) {
        livingOrganisms[i]->setNewBorn(false);
        board[livingOrganisms[i]->getYPosition()][livingOrganisms[i]->getXPosition()]->setNewBorn(false);
    }
    for (int i = 0; i < currentSize; i++) {
        if (livingOrganisms[i]->getNewBorn()== false) {
            HANDLE hOut;
            hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            if (livingOrganisms[i]->getName() == "Human") {
                SetConsoleTextAttribute(hOut, 0x0F);
                if (humanAbility==false &&coolDown<5){
                    coolDown+=1;
                }
                else if(humanAbility== true&&coolDown>0){
                    coolDown-=1;
                }

            }
            else if(Animal* ani=dynamic_cast<Animal*>(livingOrganisms[i])){
                SetConsoleTextAttribute(hOut, 0x09);
            }
            else if(Plant* pla=dynamic_cast<Plant*>(livingOrganisms[i])){
                SetConsoleTextAttribute(hOut, 0x02);
            }
            livingOrganisms[i]->action();
        }
    }
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut, 0x0F);
    turn++;
}

void World::drawWorld() {
    printf("\nRunda: %d\n",turn);

    cout<<endl;
    for (int i = 0; i <= X+1; i++) {
        if (i<=1)cout<<" ";
        else cout<<"_"<<" ";
    }
    cout<<endl;
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            if (j==0)cout<<" |";
            if(board[i][j]== nullptr) cout<<"  ";
            else {
                HANDLE hOut;
                hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                if (board[i][j]->getName() == "Human") {
                    SetConsoleTextAttribute(hOut, 0x0F);
                }
                else if(Animal* ani=dynamic_cast<Animal*>(board[i][j])){
                    SetConsoleTextAttribute(hOut, 0x09);
                }
                else if(Plant* pla=dynamic_cast<Plant*>(board[i][j])){
                    SetConsoleTextAttribute(hOut, 0x02);
                }
                cout << board[i][j]->shortName() << ' ';
                SetConsoleTextAttribute(hOut, 0x0F);
            }
        }
        cout<<endl;
    }

}

void World::saveWorld() {
    std::ofstream file;
    file.open("saveWorld.txt",std::ios::out);
    if (!file){
        cout<<"Couldn't save the world"<<endl;
    }
    else{
        file<<turn<<" "<<humanAbility<<" "<<coolDown<<endl;
        file<<X<<" "<<Y<<" "<<endl;
        for (int i = 0; i < currentSize; i++) {
            file<<livingOrganisms[i]->getName()<<" "<<livingOrganisms[i]->getXPosition()<<" "<<livingOrganisms[i]->getYPosition()<<" "<<livingOrganisms[i]->getAge()<<endl;
        }
        file.close();
        cout<<"Success save"<<endl;
    }

}
World::~World() {

    for (int i = 0; i < Y; ++i) {
        delete board[i];
    }
    delete board;
    for (int i = 0; i < currentSize; ++i) {
        delete livingOrganisms[i];
    }
}