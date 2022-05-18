#include <iostream>
#include <vector>
#include "knightarc.h"
#include "magearc.h"
#include "dragonarc.h"
#include "quest_map.h"
#include "welcome.h"
using namespace std;

//Main Function: Execution of the game
int main(){

    //Game variables
    int health=0;int mana=0;
    vector <int> new_arc {health, mana};
    int power=0;
    string key="";

    //Game starts
    welcome();//welcome message
    cin >> key;


    //Knight arc begins!
    if (key!="esc"){
        new_arc=knightarc(new_arc[0], new_arc[1]);
    }

    if (new_arc[0]!=0 && key!="dragon" && key!="esc"){
        //Mage arc begins!
        new_arc=magearc(new_arc[0], new_arc[1]);
    }

    if (new_arc[0]!=0 && key!="esc"){
        //Dragon arc begins!
        power=quest_map(new_arc[0], new_arc[1]);
        if (power==2){new_arc=dragonarc(new_arc[0], new_arc[1], 1);}//dragon arc with archer support
        else{new_arc=dragonarc(new_arc[0], new_arc[1], 0);}
        if (power==1 && new_arc[0]==0){dragonarc(2000,100,0);}//new life obtained
    }

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
