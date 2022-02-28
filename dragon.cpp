#include "dragon.h"
#include "enemy.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Constructor
dragon::dragon(){
    //Initialising variables
    health = 1000;
    magic = 1000;
    show_hp=0;
    show_mp=0;
    alias="default";
}
//Prologue
void dragon::prologue(){
    //Displaying the message setting the final battle
    cout << "The Dragon Prince awakens from its deep slumber..." << endl;
    cout << "Dragon King: Rooooaaaaaawwwwrrrrr! Which mortal dares to wake me from my sleep and cause unrest among my disciples?\nYou shall pay for your crimes with your life. I shall not let your soul rest in peace and torture it for a 1000 years in the deepest level of hell!" << endl;
    cout << "Get Ready... Battle begins...\a" << endl;
}
//Set health
void dragon::set_health(int Hp){
    health=Hp;//Equating variables
    //Ensuring health stays above or equal to 0
    if (health<0){
        health=0;
    }
}
//Get health
int dragon::get_health(){
    return health;
}
//Set magic
void dragon::set_magic(int Mana){
    magic=Mana;//Equating variables
    if (magic<0){
        magic=0;
    }
}
//Get magic
int dragon::get_magic(){
    return magic;
}
//Random number generator
int dragon::random_number(){
    srand (time(0));
    int random= 1+(rand()%5);
    return random;
}
//Getting attack health
int dragon::get_attack_health(){
    return show_hp;
}
//Setting attack health
void dragon::set_attack_health(int attack_hp){
    show_hp=attack_hp;//Equating variables
}
//Getting attack magic
int dragon::get_attack_magic(){
    return show_mp;
}
//Setting attack magic
void dragon::set_attack_magic(int attack_mp){
    show_mp=attack_mp;//Equating variables
}
//Getting attack name
string dragon::get_attack_name(){
    return alias;
}
//Setting attack name
void dragon::set_attack_name(string move_name){
    alias=move_name;//Equating variables
}
//Destructor
dragon::~dragon(){
    //free dynamic memory

}