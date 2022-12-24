#include "quest_map.h"
#include "graphics.h"
#include <iostream>
using namespace std;

int quest_map(int &health, int &mana){
    //Options to choose a power up for the player
    cout << endl << endl << endl << endl<< "----------------------------------------------------------------------------" << endl;
    cout << "Welcome to the Quest Map!" << endl << "Please enter a stat number from: 1. hp     2. mana     3. life     4. support   5. esc" <<endl;

    graphics g;
    string input;
    getline(cin,input);

    if (input == "1"){
        g.health();
        health+=1000; cout << "Health +++1000+++" << endl;
        }
    else if (input == "2"){
        g.mana();
        mana+=500; cout << "Mana +++500+++" <<endl;
        }
    else if (input == "3"){
        g.life();
        cout << "Extra life obtained..."<<endl;
        }
    else if (input == "4"){
        g.archer();
        cout << "Party member, 'Archer' obtained..."<<endl <<"Archer will constantly deal 50 physical damage to the enemy..."<<endl;
        }
    else{
        g.honor();
        cout << "You have chosen nothing as your ally against the Dragon Prince... May the goddess of luck be with you brave warrior..." <<endl;
    }

    cout << "----------------------------------------------------------------------------" << endl << endl << endl <<endl <<endl <<"----------------------------------------------------------------------------"<<endl;
    if (input=="3"){return 1;}
    if (input=="4"){return 2;}
    return 0;
}