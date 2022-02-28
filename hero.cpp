#include <iostream>
#include <string>
#include <stdlib.h>
#include "hero.h"
#include "player.h"
using namespace std;

//default constructer of hero object
hero::hero(){
    player_health = 2000;
    player_mana = 100;
    health_dmg = 0;
    magic_dmg = 0;
    move = 0;
}

//set players health
void hero::set_player_health(int hp){
    player_health = hp;

}

//return player's health
int hero::get_player_health(){
    if (player_health <= 0){
        player_health = 0;
    }
    return player_health;
}

//set player's mana
void hero::set_player_mana(int mana){
    player_mana = mana;
}
//get player's mana
int hero::get_player_mana(){
    if (player_mana > 100){
        player_mana = 100;
    }
    if (player_mana <= 0){
        player_mana = 0;
    }
    return player_mana;
}


//set player's basic attack
void hero::set_attack(int dmg){

    health_dmg = dmg;
    magic_dmg = 0;

    //in game chants
    cout << endl << "/// basic attack ///" << endl;
    cout<< "health damage: " << health_dmg << " magic damage: " << magic_dmg << endl << endl;


}
//basic attack damage
int hero::get_attack(){
    return health_dmg;
}

//first player's skill
void hero::setFirstSkill(int a, int b){


    health_dmg = a;
    magic_dmg = b;

    //in game chants
    cout << endl << ">>>Activate Fireball<<<" << endl;
    cout<< "health damage: " << health_dmg << " magic damage: " << magic_dmg << endl << endl;


}

//general health damage towards the enemy
int hero::get_health_dmg(){
    return health_dmg;
}

int hero::get_magic_dmg(){
    return magic_dmg;
}

//constructer initialize
hero::hero(int hero_health, int hero_mana){
    player_health = hero_health;
    player_mana = hero_mana;
}

//player's move
void hero::setMove(int inputMove){
    move = inputMove;

}

int hero::getMove(){
    return move;
}

//destructer
hero::~hero(){

}