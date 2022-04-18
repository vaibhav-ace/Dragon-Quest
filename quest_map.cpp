#include "quest_map.h"
#include <iostream>
using namespace std;

int quest_map(int &health, int &mana){
    //Options to choose a power up for the player
    cout << endl << endl << endl << endl<< "----------------------------------------------------------------------------" << endl;
    cout << "Welcome to the Quest Map!" << endl << "Please enter a stat number from: 1. hp     2. mana     3. life     4. esc" <<endl;

    string input;
    cin >> input;

    if (input == "1"){health+=1000; cout << "Health +++1000+++" << endl;}
    if (input == "2"){mana+=500; cout << "Mana +++500+++" <<endl;}
    if (input == "3"){cout << "Extra life obtained..."<<endl;}
    else{cout << "You have chosen nothing as your ally against the Dragon Prince... May the goddess of luck be with you brave warrior..." <<endl;}

    cout << "----------------------------------------------------------------------------" << endl << endl << endl <<endl <<endl <<"----------------------------------------------------------------------------"<<endl;
    if (input=="3"){return 1;}
    return 0;
}
