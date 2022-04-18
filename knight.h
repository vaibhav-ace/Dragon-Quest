#ifndef KNIGHT_H
#define KNIGHT_H
#include "enemy.h"
#include <string>

//Knight class
class knight: public enemy{

    //Private functions/variables
    private:
    int count=0;
    int limit=0;
    enemy** knights;

    //Public functions/variables
    public:
    knight();
    void prologue();

    knight(int curr_size, int max_size);
    int current_knight();
    enemy** get_knights();
    //bool add_knight(enemy* new_knight);
    void set_health(int Hp);
    int get_health();
    int random_number();
    int get_attack_health();
    void set_attack_health(int attack_hp);
    std::string get_attack_name();
    void set_attack_name(std::string move_name);
    ~knight();


    //Protected functions/variables
    protected:

};
#endif
