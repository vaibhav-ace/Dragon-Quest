#include "dragon.h"
#include "knight.h"
#include <iostream>
#include <string>
using namespace std;

#include "player.h"
#include "hero.h"



int main(){


int hp = 100;
int magic = 100;
 //player part
 hero h1;
 int input;

//while (hp > 0 && magic > 0){
 cout << "Please enter attack: 1.Basic Attack 2.Fireball" << endl;

 cin >> input;
 h1.setMove(input);

if(h1.getMove() == 1){
     h1.set_attack(50);
     h1.get_attack();

    }
    else if (h1.getMove() == 2){
      h1.setFirstSkill(200,200);
    }
    else {

    }


//}



}
