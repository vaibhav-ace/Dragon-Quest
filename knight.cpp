#include "knight.h"
#include <iostream>
#include <string>
#include "enemy.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

//Constructor
knight::knight(){
    //Initialising variables
    health=200;
    count=0;
    limit=0;
    knights=nullptr;
    show_hp=0;
    alias="default";
}
//Prologue
void knight::prologue(){
    //Displaying the message setting the battle
    cout << "The royal bloodline of knights rush towards the intruder to capture him and his teammates..." << endl;
    cout << "Get Ready... Battle begins...\a" << endl;
}
//Equating variables
knight::knight(int curr_size, int max_size){
    limit=max_size;//Equating variables
    count=curr_size;//Equating variables
    knights=new enemy*[limit];
}
//Getting knights
enemy** knight::get_knights(){
    return knights;
}
//Set health
void knight::set_health(int Hp){
    health=Hp;
    //Ensuring hp says above or equal to 0
    if (health<0){
        health=0;
    }
}
//Get health
int knight::get_health(){
    return health;
}
//Random number generator
int knight::random_number(){
    srand (time(0));
    int random= 1+(rand()%4);
    return random;
}
//Getting attack health
int knight::get_attack_health(){
    return show_hp;
}
//Setting attack health
void knight::set_attack_health(int attack_hp){
    show_hp=attack_hp;//Equating variables
}
//Getting attack name
string knight::get_attack_name(){
    return alias;
}
//Setting attack name
void knight::set_attack_name(string move_name){
    alias=move_name;//Equating variables
}
//Destructor
knight::~knight(){
    //free dynamic memory
    for (int i = 0; i < limit; i++) {
        delete knights[i];
    }
    delete[] knights;
}
