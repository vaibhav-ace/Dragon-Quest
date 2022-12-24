#include <iostream>
#include <vector>
#include "knightarc.h"
#include "magearc.h"
#include "dragonarc.h"
#include "quest_map.h"
#include "graphics.h"
using namespace std;

//Main Function: Execution of the game
int main(){

    //Game variables
    int health=10000;int mana=10000;
    vector <int> new_arc {health, mana};
    int power=0;
    string key="";

    //Game starts
    system("clear");
    graphics g;
    g.prologue(); //welcome message
    getline(cin,key);
    system("clear");

    //Esc key
    if (key=="esc"){
        g.defeated();
        return 0;
    }

    //Knight arc begins!
    new_arc=knightarc(new_arc[0], new_arc[1]);
    system("clear");

    //Player lost
    if (new_arc[0]==0){
        g.defeated();
        return 0;
    }

    if (key!="dragon"){
        //Mage arc begins!
        new_arc=magearc(new_arc[0], new_arc[1]);
        system("clear");
    }

    //Player lost
    if (new_arc[0]==0){
        g.defeated();
        return 0;
    }

    //Quest Map
    power=quest_map(new_arc[0], new_arc[1]);
    cout << "Press any key to continue..." << endl;
    getline(cin,key);
    system("clear");

    //Dragon arc begins!
    if (power==2){new_arc=dragonarc(new_arc[0], new_arc[1], 1);}//dragon arc with archer support
    else{new_arc=dragonarc(new_arc[0], new_arc[1], 0);}
    if (power==1 && new_arc[0]==0){dragonarc(2000,100,0);}//new life obtained
    if (new_arc[0]==0){
        g.defeated();
        return 0;
    }

    system("clear");

    //Player won the game
    g.won();
    cout << "Press any key to continue..." << endl;
    getline(cin,key);
    system("clear");

    //Final epilogue and developer's note
    g.epilogue();
    return 0;
}


/*
    Note: The add knight/mage functionality is commented out in header and cpp files. Only kept for future changes and functionality uses.

    Cheat codes:
    - "dragon" in key skips mage arc
    - "mana" maybe less than 10 and greater than 0 but the player will be able to still use the attack 'fireball'

    Run Code: make test OR make main
*/

//End of the game