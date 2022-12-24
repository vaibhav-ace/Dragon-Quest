#include "mage.h"
#include <iostream>
#include <string>
#include "enemy.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

//Constructor
mage::mage(){
    //Initialising variables
    magic=400;
    count=0;
    limit=0;
    mages=nullptr;
    show_mp=0;
    alias="default";
}
//Prologue
void mage::prologue(){
    //Displaying the message setting the battle
    cout << "The souls of mortals collected over a millenia plunge towards the hero..." << endl;
    cout << "Get Ready... Battle begins...\a" << endl;
}
//Equating variables
mage::mage(int curr_size, int max_size){
    limit=max_size;//Equating variables
    count=curr_size;//Equating variables
    mages=new enemy*[limit];
}

//Getting mages
enemy** mage::get_mages(){
    return mages;
}

//Setting magic
void mage::set_magic(int Mana){
    magic=Mana;//Equating variables
    //Ensuring mage mp is above or equal to 0
    if (magic<0){
        magic=0;
    }
}
//Getting magic
int mage::get_magic(){
    return magic;
}
//Random number generator
int mage::random_number(){
    srand (time(0));
    int random= 1+(rand()%3);
    return random;
}
//Getting attack magic
int mage::get_attack_magic(){
    return show_mp;
}
//Setting attack magic
void mage::set_attack_magic(int attack_mp){
    show_mp=attack_mp;//Equating variables
}
//Getting attack name
string mage::get_attack_name(){
    return alias;
}
//Setting attack name
void mage::set_attack_name(string move_name){
    alias=move_name;//Equating variables
}
//Destructor
mage::~mage(){
    //free dynamic memory
    for (int i = 0; i < limit; i++) {
        delete mages[i];
    }
    delete[] mages;
}
