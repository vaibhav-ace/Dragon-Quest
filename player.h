#ifndef PLAYER_H
#define PLAYER_H

class player{

private:


protected:
     int move; //player's move
     int moveOutcome; //move outcome either damage or stun
     int player_health;
     int player_mana;
     int health_dmg;
     int magic_dmg;

public:




    virtual void setMove(int inputMove)=0;
    virtual int getMove()=0;
    virtual void set_player_health(int hp)=0;
    virtual int get_player_health()=0;

    //skill methods
    virtual void set_attack(int dmg)=0;
    virtual int get_attack()=0;
    virtual void setFirstSkill(int health_dmg,int magic_dmg)=0;
    virtual int get_health_dmg()=0;
    virtual int get_magic_dmg()=0;







};
#endif