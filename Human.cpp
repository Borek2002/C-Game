//
// Created by Damian on 22.04.2022.
//
#include "Human.h"
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
Human::Human(World *presentWorld, int xPosition, int yPosition, int age)
: Animal(presentWorld,xPosition,yPosition,4,5,1,age,true ) {}

string Human::getName() {
    return "Human";
}

char Human::shortName() {
    return char(2);
}

void Human::action() {
    int move;
    specialAbility();
    if(presentWorld->getHumanAbility()== true&&presentWorld->getCoolDown()<=2&&presentWorld->getCoolDown()!=0){
        int chance;
        chance=rand()%2;
        if (chance==1){
            range=1;
        }
    }

    if(presentWorld->getHumanAbility()== true&&presentWorld->getCoolDown()==0){
        presentWorld->setHumanAbility(false);
        range=1;
    }

    for (int i = 0; i < range; i++) {
        int newX = this->getXPosition(), newY = this->getYPosition();
        cout << "Press one arrow to move Human: " << endl;
        getch();
        move = getch();
        if (move == UP&&this->getYPosition()>0) {//gora        zbezpieczyc przed uciekaniem z planszy
            newY -= 1;
        } else if (move == DOWN&&this->getYPosition()<presentWorld->getY()-1) {//dol
            newY += 1;
        } else if (move == LEFT&&this->getXPosition()>0) {//lewo
            newX -= 1;
        } else if (move == RIGHT&&this->getXPosition()<presentWorld->getX()-1) {//prawo
            newX += 1;
        }
        else{
            cout<<"You can't move here. Your turn is over"<<endl;
            break;
        }
        if (move==UP||move==DOWN||move==LEFT||move==RIGHT) {

            if (presentWorld->getBoard()[newY][newX] == nullptr) {
                makeMove(newX, newY);
                cout << this->getName() << " move to (" << this->getXPosition() << ", " << this->getYPosition() << ")"
                     << endl;
            }
            else {
                Animal::collision(presentWorld->getBoard()[newY][newX]);
            }
        }
        if (presentWorld->getBoard()[newY][newX]!=this)
            break;
    }
    if(presentWorld->getHumanAbility()== true&&presentWorld->getCoolDown()>0){
        range=2;
    }
}

void Human::specialAbility() {
    if (presentWorld->getHumanAbility()==false&&presentWorld->getCoolDown()==5){
        char command;
        cout<<"Special human skill ready. To turn it on, click x. To not turn it on, click another button ";
        cin>>command;
        if (command=='x'){
            presentWorld->setHumanAbility(true);
            range=2;
            cout<<"Round with special skills: "<<presentWorld->getCoolDown()<<endl;
        }

    }
    else if(presentWorld->getHumanAbility()== true){
        cout<<"Round with special skills: "<<presentWorld->getCoolDown()<<endl;
        range=2;
    }
    else if(presentWorld->getHumanAbility()== false&&presentWorld->getCoolDown()<5){
        cout<<"Too low cool down to turn on special skill. Your cooldown is "<<presentWorld->getCoolDown()<<endl;
    }
}

void Human::collision(Organism *occupied) {

}
Organism* Human::clone(int x, int y) {
    return new Human(presentWorld,x,y,1);
}
Human::~Human() {};