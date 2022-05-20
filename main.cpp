#include <conio.h>
#include <iostream>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include "World.h"

using namespace std;
int main() {
    int N,M;
    char option,playorquite;
    cout<<"Welcome in game. Choose the option below:"<<endl;
    cout<<"Play new game - 't'"<<endl;
    cout<<"Load previous game - 'l'"<<endl;
    cout<<"Author - 'a'"<<endl;
    cout<<"Exit - 'q'"<<endl;
    cout<<"Enter what you chose: ";
    cin>>option;
    while(option!='q') {
        system("cls");
        if (option == 't') {
            cout << "Board size: " << endl;
            cout << "x: ";
            cin >> N;
            cout << "y: ";
            cin >> M;
            cout << "Klick 'p' to play new or next round ";
            cin >> playorquite;
            World world(N, M);
            while (playorquite == 'p') {
                system("cls");
                world.drawWorld();
                world.makeTurn();
                world.drawWorld();
                cout << "\n";
                cout << "Klick 'p' to play next round \n";
                cout << "If you want to save it klick 's'" << endl;
                cin >> playorquite;
            }
            if (playorquite == 's') {
                world.saveWorld();
            }

            cout << "Play new game - 't'" << endl;
            cout << "Load previous game - 'l'" << endl;
            cout << "Author - 'a'" << endl;
            cout << "Exit - 'q'" << endl;
            cout << "Enter what you chose: ";
            cin >> option;
            system("pause");
        }
        if (option == 'l') {
            std::ifstream loadFile;
            loadFile.open("saveWorld.txt", std::ios::in);
            if (!loadFile) {
                printf("There is no saved world.\n");
                exit(1);
            }
            int turn, cooldown, X, Y;
            bool humanAbility;
            loadFile >> turn >> humanAbility >> cooldown;
            loadFile >> X >> Y;
            World sworld(X, Y, loadFile);
            sworld.setHumanAbility(humanAbility);
            sworld.setCoolDown(cooldown);
            sworld.setTurn(turn);
            system("cls");

            cout << "Klick 'p' to play new or next round ";
            cin >> playorquite;
            while (playorquite == 'p') {
                system("cls");
                sworld.drawWorld();
                sworld.makeTurn();
                sworld.drawWorld();
                cout << "\n";
                cout << "Klick 'p' to play next round \n";
                cout << "If you want to save it klick 's'" << endl;
                cin >> playorquite;
            }
            if (playorquite == 's') {
                sworld.saveWorld();
            }

            cout << "Play new game - 't'" << endl;
            cout << "Load previous game - 'l'" << endl;
            cout << "Author - 'a'" << endl;
            cout << "Exit - 'q'" << endl;
            cout << "Enter what you chose: ";
            cin >> option;
            system("pause");
        }
    }
    system("pause");
    return 0;

}
