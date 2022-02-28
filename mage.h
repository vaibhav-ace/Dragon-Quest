#ifndef MAGE_H
#define MAGE_H
#include "enemy.h"

//Mage class
class mage: public enemy{

    //Private functions/variables
    private:
    int count;
    int limit;
    enemy** mages;

    //Public functions/variables
    public:
    mage();
    void prologue();

    mage(int curr_size, int max_size);
    int current_mage();
    enemy** get_mages();
    bool add_mage(enemy* new_mage);
    void set_magic(int Mana);
    int get_magic();
    int random_number();
    int get_attack_magic();
    void set_attack_magic(int attack_mp);
    std::string get_attack_name();
    void set_attack_name(std::string move_name);
    ~mage();


    //Protected functions/variables
    protected:

};
#endif