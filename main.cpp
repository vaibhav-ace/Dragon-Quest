#include <iostream>
#include <vector>
#include "knightarc.h"
#include "magearc.h"
#include "dragonarc.h"
using namespace std;

//Main Function: Execution of the game
int main(){

    //Game variables
    int health=0;int mana=0;
    vector <int> new_arc {health, mana};


    //Knight arc begins!
    new_arc=knightarc(new_arc[0], new_arc[1]);

    if (new_arc[0]!=0){
        //Mage arc begins!
        new_arc=magearc(new_arc[0], new_arc[1]);
    }

    if (new_arc[0]!=0){
        //Dragon arc begins!
        new_arc=dragonarc(new_arc[0], new_arc[1]);
    }

    //Returning 0
    return 0;

    //Note: The add knight/mage functionality is commented out in header and cpp files. Only kept for future changes and functionality uses.
    //Run Code: make test OR make main
}

//End of the game
