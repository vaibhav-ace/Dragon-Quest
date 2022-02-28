#ifndef HERO_H
#define HERO_H

#include "player.h"

class hero: public player{

private:


protected:


public:

    hero();

//other methods
    hero(int hero_health,int hero_mana);
    void setMove(int inputMove);
    int getMove();
    void set_player_health(int hp);
    int get_player_health();
    void set_player_mana(int mana);
    int get_player_mana();

//skills methods
    void set_attack(int dmg);
    int get_attack();
    void setFirstSkill(int a, int b);
    int get_health_dmg();
    int get_magic_dmg();



    ~hero();



};
#endif