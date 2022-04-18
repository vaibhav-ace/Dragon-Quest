#include <iostream>
#include <vector>
#include "knightarc.h"
#include "magearc.h"
#include "dragonarc.h"
#include "quest_map.h"
using namespace std;

//Main Function: Execution of the game
int main(){

    //Game variables
    int health=0;int mana=0;
    vector <int> new_arc {health, mana};
    int power=0;

    //Knight arc begins!
    new_arc=knightarc(new_arc[0], new_arc[1]);

    if (new_arc[0]!=0){
        //Mage arc begins!
        new_arc=magearc(new_arc[0], new_arc[1]);
    }

    if (new_arc[0]!=0){
        //Dragon arc begins!
        power=quest_map(new_arc[0], new_arc[1]);
        new_arc=dragonarc(new_arc[0], new_arc[1]);
        if (power==1 && new_arc[0]==0){dragonarc(2000,100);}//new life obtained
    }

    //Returning 0
    return 0;

    //Note: The add knight/mage functionality is commented out in header and cpp files. Only kept for future changes and functionality uses.
    //Run Code: make test OR make main
}

//End of the game
