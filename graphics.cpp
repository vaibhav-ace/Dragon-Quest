#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "graphics.h"
using namespace std;

//Drawing the art line by line from text files
void draw(string input){
    fstream newfile;
    newfile.open("ASCII_Art/"+input,ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        string tp;
        while(getline(newfile, tp)){ //read data from file object and put it into string.
            cout << tp << "\n"; //print the data of the string
        }
      newfile.close(); //close the file object.
    }
}


//Welcome message with basic terminal graphics
void graphics::prologue(){
    draw("prologue.txt");
    cout << "Press any key to start... esc to Escape..." << endl;
    return;
}

//Player Art
void graphics::player(){
    draw("player.txt");
    return;
}

//Archer Art
void graphics::archer(){
    draw("archer.txt");
    return;
}

//Mage Art
void graphics::mage(){
    draw("mage.txt");
    return;
}

//Health Art
void graphics::health(){
    draw("health.txt");
    return;
}

//Mana Art
void graphics::mana(){
    draw("mana.txt");
    return;
}

//Life Art
void graphics::life(){
    draw("life.txt");
    return;
}

//Honor Art
void graphics::honor(){
    draw("honor.txt");
    return;
}

//Player won the game
void graphics::won(){
    draw("won.txt");
    return;
}

//World Text Art
void graphics::world_art(){
    draw("world_art.txt");
    return;
}

//Knight Art
void graphics::knight(){
    draw("knight.txt");
    return;
}

//Knight Attack 1
void graphics::knight_attack1(){
    draw("knight_attack1.txt");
    return;
}

//Knight Attack 2
void graphics::knight_attack2(){
    draw("knight_attack2.txt");
    return;
}

//Knight Attack 3
void graphics::knight_attack3(){
    draw("knight_attack3.txt");
    return;
}

//Knight Attack 4
void graphics::knight_attack4(){
    draw("knight_attack4.txt");
    return;
}

//Player lost the game
void graphics::defeated(){
    draw("defeated.txt");
    return;
}

//Player attack (basic)
void graphics::player_basic_attack(){
    draw("player_basic_attack.txt");
    return;
}

//Player attack (fireball)
void graphics::player_fireball(){
    draw("player_fireball.txt");
    return;
}

//Mage attack 1
void graphics::mage_attack1(){
    draw("mage_attack1.txt");
    return;
}

//Mage attack 2
void graphics::mage_attack2(){
    draw("mage_attack2.txt");
    return;
}

//Mage attack 3
void graphics::mage_attack3(){
    draw("mage_attack3.txt");
    return;
}

//Dragon Art
void graphics::dragon(){
    draw("dragon.txt");
    return;
}

//Dragon attack 1
void graphics::dragon_attack1(){
    draw("dragon_attack1.txt");
    return;
}

//Dragon attack 2
void graphics::dragon_attack2(){
    draw("dragon_attack2.txt");
    return;
}

//Dragon attack 3
void graphics::dragon_attack3(){
    draw("dragon_attack3.txt");
    return;
}

//Dragon attack 4
void graphics::dragon_attack4(){
    draw("dragon_attack4.txt");
    return;
}

//Dragon attack 5
void graphics::dragon_attack5(){
    draw("dragon_attack5.txt");
    return;
}

//Epilogue
void graphics::epilogue(){
    draw("epilogue.txt");
    return;
}