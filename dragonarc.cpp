#include "dragon.h"
#include "player.h"
#include "hero.h"
#include "enemy.h"
#include "input.h"
#include "dragonarc.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

//Hero global variable
static hero h1;

//Defining functions used for input attacks
//Function used to get input
static void heroAttack(){
    cout << "Please enter attack: 1.Basic Attack 2.Fireball " << endl;
    int input=getting_input();//Going to the function above to check if the input is valid

    //Setting move
    h1.setMove(input);

    //Setting attack values for input 1 and 2
    if(h1.getMove() == 1){
     h1.set_attack(100);
     h1.get_attack();
     h1.set_player_mana(h1.get_player_mana()-0);
     cout<< "Player Current Mana: " << h1.get_player_mana() << endl;

    }
    else if (h1.getMove() == 2 && h1.get_player_mana() > 0){
        h1.setFirstSkill(200,200);
        h1.set_player_mana(h1.get_player_mana()-10); //uses mana for each skill usage
        cout<< "Player Current Mana: " << h1.get_player_mana() << endl;
    }
    else {
        //Else case (when hero have no mana to input the required skill)
        cout << "Not Enough Mana :( " << endl;
        heroAttack(); //loop back to repeat label for input
    }
}



vector<int> dragonarc(int health, int mana){
    h1.set_player_mana(mana);
    h1.set_player_health(health);

    //Dragon class
    dragon* d1=new dragon(); //Prologue
    dragon* d2=new dragon(); //Health
    dragon* d3=new dragon();//Magic

    //Dragon attack interface
    dragon* d4=new dragon();//For random number
    dragon* d5=new dragon();
    dragon* d6=new dragon();
    dragon* d7=new dragon();
    dragon* d8=new dragon();
    dragon* d9=new dragon();
    //Defining Attacks
    d5->set_attack_health(100);
    d5->set_attack_magic(100);
    d5->set_attack_name("Aspiro");
    d6->set_attack_health(50);
    d6->set_attack_magic(200);
    d6->set_attack_name("Fulminis");
    d7->set_attack_health(150);
    d7->set_attack_magic(300);
    d7->set_attack_name("Ventus Spiralis");
    d8->set_attack_health(1000);
    d8->set_attack_magic(0);
    d8->set_attack_name("Echoz Thunderiz");
    d9->set_attack_health(0);
    d9->set_attack_magic(1000);
    d9->set_attack_name("Manus Pluma Volantus");

    //Dragon arc begins
    d1->prologue();//Prologue and status definition(below):
    cout << "Dragon Prince health: " << d2->get_health() << endl;
    cout << "Dragon Prince magic: " << d3->get_magic() << endl;
    cout << "++++++ 100 MANA +++++" << endl << "Player Mana now at " << mana+100<< endl << endl;
    h1.set_player_mana(mana+100);

    //While loop to ensure player is alive while game continues
    while (d2->get_health()>0 && h1.get_player_health() > 0){

        heroAttack();//Obtaining input
        cout << "Player current hp:" << h1.get_player_health() << endl;
        //Status redefinition
        d2->set_health(d2->get_health()-h1.get_health_dmg());
        d3->set_magic(d3->get_magic()-h1.get_magic_dmg());
        cout << "Dragon Prince health: " << d2->get_health() << endl;
        cout << "Dragon Prince magic: " << d3->get_magic() << endl;

        //Dragon's counterattack begins
        if (d2->get_health()>0){
            int random_3=d4->random_number();//Random attack selection
            //Attack 1
            if (random_3==1){
                cout<<"You have been hit with "<<d5->get_attack_name()<<", -"<<d5->get_attack_health()<<" health and -"<<d5->get_attack_magic()<<" magic..."<<endl;
                h1.set_player_health(h1.get_player_health()-d5->get_attack_health());
                cout << "Player hp: " << h1.get_player_health() << endl;
                h1.set_player_mana(h1.get_player_mana() - d5->get_attack_magic());
                cout << "Player mana:" << h1.get_player_mana() << endl;
            }

            //Attack 2
            if (random_3==2){
                cout<<"You have been hit with "<<d6->get_attack_name()<<", -"<<d6->get_attack_health()<<" health and -"<<d6->get_attack_magic()<<" magic..."<<endl;
                h1.set_player_health(h1.get_player_health()-d6->get_attack_health());
                cout << "Player hp: " << h1.get_player_health() << endl;
                h1.set_player_mana(h1.get_player_mana() - d6->get_attack_magic());
                cout << "Player mana:" << h1.get_player_mana() << endl;
            }

            //Attack 3
            if (random_3==3){
                cout<<"You have been hit with "<<d7->get_attack_name()<<", -"<<d7->get_attack_health()<<" health and -"<<d7->get_attack_magic()<<" magic..."<<endl;
                h1.set_player_health(h1.get_player_health()-d7->get_attack_health());
                cout << "Player hp: " << h1.get_player_health() << endl;
                h1.set_player_mana(h1.get_player_mana() - d7->get_attack_magic());
                cout << "Player mana:" << h1.get_player_mana() << endl;
            }

            //Attack 4
            if (random_3==4){
                cout<<"You have been hit with "<<d8->get_attack_name()<<", -"<<d8->get_attack_health()<<" health and -"<<d8->get_attack_magic()<<" magic..."<<endl;
                h1.set_player_health(h1.get_player_health()-d8->get_attack_health());
                cout << "Player hp: " << h1.get_player_health() << endl;
                h1.set_player_mana(h1.get_player_mana() - d8->get_attack_magic());
                cout << "Player mana:" << h1.get_player_mana() << endl;
            }

            //Attack 5
            if (random_3==5){
                cout<<"You have been hit with "<<d9->get_attack_name()<<", -"<<d9->get_attack_health()<<" health and -"<<d9->get_attack_magic()<<" magic..."<<endl;
                h1.set_player_health(h1.get_player_health()-d9->get_attack_health());
                h1.set_player_mana(h1.get_player_mana() - d9->get_attack_magic());
                cout << "Player hp: " << h1.get_player_health() << endl;
                cout << "Player mana:" << h1.get_player_mana() << endl;
            }
        }
    }
    //Player health check
    if(h1.get_player_health()<=0){
        cout << "Defeated" << endl;
        cout << "----------------------------------------------------------------------------"<<endl;
        //exit(EXIT_FAILURE);
        return {0,0};
    }
    cout << "Successfully slayed the dragon prince!" << endl;
    cout << "----------------------------------------------------------------------------"<<endl;
    //End of dragon arc


    //Freeing memory
    //dragon variables
    delete d1;
    delete d2;
    delete d3;
    delete d4;
    delete d5;
    delete d6;
    delete d7;
    delete d8;
    delete d9;

    vector <int> result {h1.get_player_health(),h1.get_player_mana()};

    return result;
}
