#include "dragon.h"
#include "player.h"
#include "hero.h"
#include "enemy.h"
#include <climits>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "dragonarc.h"
using namespace std;

//Hero global variable
hero h3;

//Function Names: (Defined after the end of dragonarc function)
void heroAttack3();
int getting_input3();

void dragonarc(int health, int mana){
    h3.set_player_mana(mana);
    h3.set_player_health(health);

    //Dragon class
    dragon* d1=new dragon(); //Prologueg
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
    cout << "Health: " << d2->get_health() << endl;
    cout << "Magic: " << d3->get_magic() << endl;
    cout << "++++++ 100 MANA +++++" << endl << "Player Mana now at 100" << endl << endl;
    h3.set_player_mana(100);

    //While loop to ensure player is alive while game continues
    while (d2->get_health()>0 && h3.get_player_health() > 0){

        heroAttack3();//Obtaining input
        cout << "Player current hp:" << h3.get_player_health() << endl;
        //Status redefinition
        d2->set_health(d2->get_health()-h3.get_health_dmg());
        d3->set_magic(d3->get_magic()-h3.get_magic_dmg());
        cout << "Dragon Prince health: " << d2->get_health() << endl;
        cout << "Dragon Prince magic: " << d3->get_magic() << endl;

        //Dragon's counterattack begins
        if (d2->get_health()>0){
            int random_3=d4->random_number();//Random attack selection
            //Attack 1
            if (random_3==1){
                cout<<"You have been hit with "<<d5->get_attack_name()<<", -"<<d5->get_attack_health()<<" health and -"<<d5->get_attack_magic()<<" magic..."<<endl;
                h3.set_player_health(h3.get_player_health()-d5->get_attack_health());
                cout << "Player hp: " << h3.get_player_health() << endl;
                h3.set_player_mana(h3.get_player_mana() - d5->get_attack_magic());
                cout << "Player mana:" << h3.get_player_mana() << endl;
            }

            //Attack 2
            if (random_3==2){
                cout<<"You have been hit with "<<d6->get_attack_name()<<", -"<<d6->get_attack_health()<<" health and -"<<d6->get_attack_magic()<<" magic..."<<endl;
                h3.set_player_health(h3.get_player_health()-d6->get_attack_health());
                cout << "Player hp: " << h3.get_player_health() << endl;
                h3.set_player_mana(h3.get_player_mana() - d6->get_attack_magic());
                cout << "Player mana:" << h3.get_player_mana() << endl;
            }

            //Attack 3
            if (random_3==3){
                cout<<"You have been hit with "<<d7->get_attack_name()<<", -"<<d7->get_attack_health()<<" health and -"<<d7->get_attack_magic()<<" magic..."<<endl;
                h3.set_player_health(h3.get_player_health()-d7->get_attack_health());
                cout << "Player hp: " << h3.get_player_health() << endl;
                h3.set_player_mana(h3.get_player_mana() - d7->get_attack_magic());
                cout << "Player mana:" << h3.get_player_mana() << endl;
            }

            //Attack 4
            if (random_3==4){
                cout<<"You have been hit with "<<d8->get_attack_name()<<", -"<<d8->get_attack_health()<<" health and -"<<d8->get_attack_magic()<<" magic..."<<endl;
                h3.set_player_health(h3.get_player_health()-d8->get_attack_health());
                cout << "Player hp: " << h3.get_player_health() << endl;
                h3.set_player_mana(h3.get_player_mana() - d8->get_attack_magic());
                cout << "Player mana:" << h3.get_player_mana() << endl;
            }

            //Attack 5
            if (random_3==5){
                cout<<"You have been hit with "<<d9->get_attack_name()<<", -"<<d9->get_attack_health()<<" health and -"<<d9->get_attack_magic()<<" magic..."<<endl;
                h3.set_player_health(h3.get_player_health()-d9->get_attack_health());
                h3.set_player_mana(h3.get_player_mana() - d9->get_attack_magic());
                cout << "Player hp: " << h3.get_player_health() << endl;
                cout << "Player mana:" << h3.get_player_mana() << endl;
            }
        }
    }
    //Player health check
    if(h3.get_player_health()<=0){
        cout << "Defeated" << endl;
        cout << "----------------------------------------------------------------------------"<<endl;
        exit(EXIT_FAILURE);
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


    return;
}

//Defining functions used for input attacks

//Function: Used to get only valid input
int getting_input3(){
    int input;

    while (1){
        cin >> input;
        //If value is not an integer
        if (!cin){
            cout << "Please enter a valid attack..." << endl;
            cin.clear();
            cin.ignore (INT_MAX, '\n');
            continue;
        }
        //If value is not 1 or 2 for the defined attacks
        if (input!=1 && input!=2){
            cout << "Please enter a valid attack..." << endl;
            continue;
        }
        //If obtained value is suitable
        if (input==1 || input==2){
            return input; //Exit function
        }
    }//End of while loop
}


//Function used to get input
void heroAttack3(){
    repeat:
    cout << "Please enter attack: 1.Basic Attack 2.Fireball " << endl;
    int input=getting_input3();//Going to the function above to check if the input is valid

    //Setting move
    h3.setMove(input);

    //Setting attack values for input 1 and 2
    if(h3.getMove() == 1){
     h3.set_attack(100);
     h3.get_attack();
     h3.set_player_mana(h3.get_player_mana()-0);
     cout<< "Player Current Mana: " << h3.get_player_mana() << endl;

    }
    else if (h3.getMove() == 2 && h3.get_player_mana() > 0){
        h3.setFirstSkill(200,200);
        h3.set_player_mana(h3.get_player_mana()-10); //uses mana for each skill usage
        cout<< "Player Current Mana: " << h3.get_player_mana() << endl;
    }
    else {
        //Else case (when hero have no mana to input the required skill)
        cout << "Not Enough Mana :( " << endl;
        goto repeat; //loop back to repeat label for input
    }
}
