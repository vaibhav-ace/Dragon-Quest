#ifndef ENEMY_H
#define ENEMY_H
#include <string>

//Enemy class
class enemy{

    //Private functions/variables
    private:


    //Public functions/variables
    public:
    enemy();
    virtual void prologue()=0;
    virtual ~enemy();

    //Protected functions/variables
    protected:
    int health;
    int magic;
    std::string name;
    int show_hp;
    int show_mp;
    std::string alias;

};
#endif