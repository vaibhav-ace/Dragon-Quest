#ifndef DRAGON_H
#define DRAGON_H
#include <string>
#include "enemy.h"

//Dragon class
class dragon: public enemy{

    //Private functions/variables
    private:


    //Public functions/variables
    public:
    dragon();
    void prologue();
    void set_health(int Hp);
    int get_health();
    void set_magic(int Mana);
    int get_magic();
    int random_number();
    int get_attack_health();
    void set_attack_health(int attack_hp);
    int get_attack_magic();
    void set_attack_magic(int attack_mp);
    std::string get_attack_name();
    void set_attack_name(std::string move_name);
    ~dragon();


    //Protected functions/variables
    protected:

};
#endif