#include "mage.h"
#include "player.h"
#include "hero.h"
#include "enemy.h"
#include <climits>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "magearc.h"
#include "dragonarc.h"
using namespace std;

//Hero global variable
hero h2;

//Function Names: (Defined after the end of magearc function)
void heroAttack2();
int getting_input2();

void magearc(int health, int mana){

    h2.set_player_mana(mana);
    h2.set_player_health(health);

    //Mage class
    enemy* m1=new mage(); //Prologue
    mage m2;//For random number
    mage m3;

    //Mage array objects
    mage m10;
    mage m11;
    mage m12;
    mage array_interface[]={m10,m11};
    mage m13(0,2);

    //Mage attack interface: Defining attacks
    m10.set_attack_magic(45);
    m10.set_attack_name("Exterminate");
    m11.set_attack_magic(25);
    m11.set_attack_name("Ice Tornado");
    m12.set_attack_magic(55);
    m12.set_attack_name("Laplace's Cage");

    //Mage arc
    m1->prologue();//Prologue for mage class
    cout<<"Current mages: " << m13.current_mage()<<endl;

    //Mage class arc starts: For loop to add new mages to the game
    for(int i=0;i<2;i++){

        //If statement to add new mages
        if (m13.add_mage(&array_interface[i])&& h2.get_player_health() > 0){
            cout<<"Mage "<< i+1 << " entered the battlefield..."<<endl;

            //While loop to ensure mage and player health is above 0
            while (array_interface[i].get_magic()>0 && h2.get_player_health() > 0){
                heroAttack2();//Inputting attack from user
                //Defining status
                cout << "Player current hp:" << h2.get_player_health() << endl;
                array_interface[i].set_magic(array_interface[i].get_magic()-h2.get_health_dmg());
                cout << "Mage health: " << array_interface[i].get_magic() << endl;
                //If statement to begin mage counter attack
                if (array_interface[i].get_magic()>0){
                    int random_2=m2.random_number();//Random attack definition
                    //Attack 1
                    if (random_2==1){
                        cout<<"You have been hit with "<<m10.get_attack_name()<<", -"<<m10.get_attack_magic()<<" magic..."<<endl;
                        h2.set_player_health(h2.get_player_health()-m10.get_attack_magic());
                        cout << "Player hp: " << h2.get_player_health() << endl;
                        h2.set_player_mana(h2.get_player_mana() - m10.get_attack_magic());
                        cout << "Player mana:" << h2.get_player_mana() << endl;
                    }

                    //Attack 2
                    if (random_2==2){
                        cout<<"You have been hit with "<<m11.get_attack_name()<<", -"<<m11.get_attack_magic()<<" magic..."<<endl;
                        h2.set_player_health(h2.get_player_health()-m11.get_attack_magic());
                        cout << "Player hp: " << h2.get_player_health() << endl;
                        h2.set_player_mana(h2.get_player_mana() - m11.get_attack_magic());
                        cout << "Player mana:" << h2.get_player_mana() << endl;
                    }

                    //Attack 3
                    if (random_2==3){
                        cout<<"You have been hit with "<<m12.get_attack_name()<<", -"<<m12.get_attack_magic()<<" magic..."<<endl;
                        h2.set_player_health(h2.get_player_health()-m12.get_attack_magic());
                        cout << "Player hp: " << h2.get_player_health() << endl;
                        h2.set_player_mana(h2.get_player_mana() - m12.get_attack_magic());
                        cout << "Player mana:" << h2.get_player_mana() << endl;
                    }
                }
                //Else case for unexpected outcomes (should not happen)
                else {
                    break;
                }
            }//While loop ends

            //Player health check
            if(h2.get_player_health()<=0){
            cout << "Defeated" << endl;
            exit(EXIT_FAILURE);
            }
            //If player beats mage
            else{
            cout<<"Beaten Mage " << i+1 << "..." << endl;
            }
        }//If statement ends
    }//For loop ends

    cout << "Successfully eradicated " << m13.current_mage()<< " mages..." << endl;
    //End of mage arc

    //mage variables
    delete m1;

    //Dragon arc begins!
    dragonarc(h2.get_player_health(),h2.get_player_mana());
    return;
}


//Defining functions used for input attacks

//Function: Used to get only valid input
int getting_input2 (){
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
void heroAttack2(){
    repeat:
    cout << "Please enter attack: 1.Basic Attack 2.Fireball " << endl;
    int input=getting_input2();//Going to the function above to check if the input is valid

    //Setting move
    h2.setMove(input);

    //Setting attack values for input 1 and 2
    if(h2.getMove() == 1){
     h2.set_attack(100);
     h2.get_attack();
     h2.set_player_mana(h2.get_player_mana()-0);
     cout<< "Player Current Mana: " << h2.get_player_mana() << endl;

    }
    else if (h2.getMove() == 2 && h2.get_player_mana() > 0){
        h2.setFirstSkill(200,200);
        h2.set_player_mana(h2.get_player_mana()-10); //uses mana for each skill usage
        cout<< "Player Current Mana: " << h2.get_player_mana() << endl;
    }
    else {
        //Else case (when hero have no mana to input the required skill)
        cout << "Not Enough Mana :( " << endl;
        goto repeat; //loop back to repeat label for input
    }
}