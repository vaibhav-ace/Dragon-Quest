#include "mage.h"
#include "player.h"
#include "hero.h"
#include "enemy.h"
#include "magearc.h"
#include "input.h"
#include "graphics.h"
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
    graphics g;
    cout << "Please enter attack: 1.Basic Attack 2.Fireball " << endl;
    int input=getting_input();//Going to the function above to check if the input is valid

    //Setting move
    system("clear");
    h1.setMove(input);
    string blank_key;

    //Setting attack values for input 1 and 2
    if(h1.getMove() == 1){
        g.player_basic_attack();
        h1.set_attack(100);
        h1.get_attack();
        h1.set_player_mana(h1.get_player_mana()-0);
        cout<< "Player Current Mana: " << h1.get_player_mana() << endl;
        //Continuing story
        getline(cin,blank_key);
    }
    else if (h1.getMove() == 2 && h1.get_player_mana() > 0){
        g.player_fireball();
        h1.setFirstSkill(200,200);
        h1.set_player_mana(h1.get_player_mana()-10); //uses mana for each skill usage
        cout<< "Player Current Mana: " << h1.get_player_mana() << endl;
        //Continuing story
        getline(cin,blank_key);
    }
    else {
        //Else case (when hero have no mana to input the required skill)
        cout << "Not Enough Mana..." << endl;
        heroAttack(); //loop back to repeat label for input
    }
}




vector<int> magearc(int health, int mana){

    //Declaring parameters
    graphics g;
    string blank_key; //blank key to continue storyline

    h1.set_player_mana(mana);
    h1.set_player_health(health);

    //Mage class
    enemy* m1=new mage(); //Prologue
    mage m2;//For random number
    mage m3;

    //Mage array objects
    mage m10;
    mage m11;
    mage m12;
    mage array_interface[]={m10,m11};

    //Mage attack interface: Defining attacks
    m10.set_attack_magic(45);
    m10.set_attack_name("Exterminate");
    m11.set_attack_magic(25);
    m11.set_attack_name("Ice Tornado");
    m12.set_attack_magic(55);
    m12.set_attack_name("Laplace's Cage");

    //Mage arc
    m1->prologue();//Prologue for mage class

    //Mage class arc starts: For loop to add new mages to the game
    for(int i=0;i<2;i++){

        //If statement to add new mages
        if (h1.get_player_health() > 0){
            g.mage();
            cout<<"Mage "<< i+1 << " entered the battlefield..."<<endl;
            cout << "Press any key to continue..." << endl;
            getline (cin, blank_key);
            system("clear");

            //While loop to ensure mage and player health is above 0
            while (array_interface[i].get_magic()>0 && h1.get_player_health() > 0){
                cout << "Player Attack..." << endl;
                g.player();
                heroAttack();//Inputting attack from user

                //Defining status
                cout << "Player Current HP:" << h1.get_player_health() << endl;
                array_interface[i].set_magic(array_interface[i].get_magic()-h1.get_health_dmg());
                cout << "Mage health: " << array_interface[i].get_magic() << endl;
                cout << "Press any key to continue..." << endl;
                getline (cin, blank_key);
                system("clear");

                //If statement to begin mage counter attack
                if (array_interface[i].get_magic()>0){
                    int random_2=m2.random_number();//Random attack definition

                    //Attack 1
                    if (random_2==1){
                        g.mage_attack1();
                        cout<<"You have been hit with "<<m10.get_attack_name()<<", -"<<m10.get_attack_magic()<<" magic..."<<endl;
                        h1.set_player_health(h1.get_player_health()-m10.get_attack_magic());
                        cout << "Player hp: " << h1.get_player_health() << endl;
                        h1.set_player_mana(h1.get_player_mana() - m10.get_attack_magic());
                        cout << "Player mana:" << h1.get_player_mana() << endl;
                    }

                    //Attack 2
                    if (random_2==2){
                        g.mage_attack2();
                        cout<<"You have been hit with "<<m11.get_attack_name()<<", -"<<m11.get_attack_magic()<<" magic..."<<endl;
                        h1.set_player_health(h1.get_player_health()-m11.get_attack_magic());
                        cout << "Player hp: " << h1.get_player_health() << endl;
                        h1.set_player_mana(h1.get_player_mana() - m11.get_attack_magic());
                        cout << "Player mana:" << h1.get_player_mana() << endl;
                    }

                    //Attack 3
                    if (random_2==3){
                        g.mage_attack3();
                        cout<<"You have been hit with "<<m12.get_attack_name()<<", -"<<m12.get_attack_magic()<<" magic..."<<endl;
                        h1.set_player_health(h1.get_player_health()-m12.get_attack_magic());
                        cout << "Player hp: " << h1.get_player_health() << endl;
                        h1.set_player_mana(h1.get_player_mana() - m12.get_attack_magic());
                        cout << "Player mana:" << h1.get_player_mana() << endl;
                    }
                }
                //Else case for unexpected outcomes (should not happen)
                else {
                    break;
                }
                cout << "Press any key to continue..." << endl;
                getline (cin, blank_key);
                system("clear");
            }//While loop ends

            //Player health check
            if(h1.get_player_health()<=0){
                //exit(EXIT_FAILURE);
                delete m1;
                return {0,0};
            }
            //If player beats mage
            else{
            cout<<"Beaten Mage " << i+1 << "..." << endl;
            }
        }//If statement ends
    }//For loop ends

    cout << "Successfully eradicated 2 mages..." << endl;
    cout << "----------------------------------------------------------------------------"<<endl;
    cout << "Press any key to continue..." << endl;
    getline (cin, blank_key);
    system("clear");
    //End of mage arc

    //mage variables
    delete m1;

    vector <int> result {h1.get_player_health(),h1.get_player_mana()};

    return result;
}
