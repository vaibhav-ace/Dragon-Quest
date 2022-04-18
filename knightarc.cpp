#include "knight.h"
#include "player.h"
#include "hero.h"
#include "enemy.h"
#include "input.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include "knightarc.h"
#include "magearc.h"
using namespace std;

//Hero global variable
static hero h1;

//Function Names: (Defined after the end of knightarc function)
void heroAttack();

void knightarc(){
    //Knight class
    enemy* k1=new knight(); //Prologue
    knight k9;//For random number

    //Knight array objects
    knight k10;
    knight k11;
    knight k12;
    knight arr[]={k10,k11,k12};
    knight k13(0,3);

    //Knight attack interface: Defining attacks
    k10.set_attack_health(10);
    k10.set_attack_name("Zakere");
    k11.set_attack_health(50);
    k11.set_attack_name("Rashield");
    k12.set_attack_health(90);
    k12.set_attack_name("Bao Zakerga");
    k13.set_attack_name("Phoenix");
    k13.set_attack_health(0);//Unused


    //Knight arc

    //Introductory message to the game
    cout<<"Welcome to the game Dragon Quest! Your journey begins here..." << endl;
    cout<<"For a thousand years, a mystical dragon has ruled the world and spread evil over the entire planet." << endl;
    cout<<"As the legendary hero weilding an unwavering will to protect others, you set out on a journey to protect your loved ones..."<<endl;
    cout<<"After a long and tiresome war you have successfully infiltrated the dragon's lair in the palace of Elvshire. Your real battle against evil begins anew..." << endl;

    k1->prologue();//Prologue for knight class
    cout<<endl<<"Current knights: " << k13.current_knight()<<endl;

    //For loop iterating new knights to the game
    for(int i=0;i<3;i++){
        if (k13.add_knight(&arr[i]) && h1.get_player_health() > 0){
            cout<<"Knight "<< i+1 << " entered the battlefield..."<<endl;
            //While loop to repeat code if needed
            while (arr[i].get_health()>0 && h1.get_player_health() > 0){
                    heroAttack();//Attaining input from user for attack
                    cout << "Player current hp:" << h1.get_player_health() << endl;
                    arr[i].set_health(arr[i].get_health()-h1.get_health_dmg());

                    cout << "Knight health: " << arr[i].get_health() << endl;
                //Knight attacks on the player
                if (arr[i].get_health()>0){
                    int random_1=k9.random_number();//Random attack definition

                    //Attack 1
                    if (random_1==1){
                        cout<<"You have been hit with "<<k10.get_attack_name()<<", -"<<k10.get_attack_health()<<" health..."<<endl;
                        h1.set_player_health(h1.get_player_health()-k10.get_attack_health());
                        cout << "Player hp: " << h1.get_player_health() << endl;
                    }

                    //Attack 2
                    if (random_1==2){
                        cout<<"You have been hit with "<<k11.get_attack_name()<<", -"<<k11.get_attack_health()<<" health..."<<endl;
                        h1.set_player_health(h1.get_player_health()-k11.get_attack_health());
                        cout << "Player hp: " << h1.get_player_health() << endl;
                    }

                    //Attack 3
                    if (random_1==3){
                        cout<<"You have been hit with "<<k12.get_attack_name()<<", -"<<k12.get_attack_health()<<" health..."<<endl;
                        h1.set_player_health(h1.get_player_health()-k12.get_attack_health());
                        cout << "Player hp: " << h1.get_player_health() << endl;
                    }

                    //Attack 4: Reflection damage
                    if (random_1==4){
                        cout<<"The knight has reflected and recovered from your damage with "<<k13.get_attack_name()<<", -"<<h1.get_health_dmg()<<" health..."<<endl;
                        h1.set_player_health(h1.get_player_health()-h1.get_health_dmg());
                        arr[i].set_health(arr[i].get_health()+h1.get_health_dmg());
                        cout << "Knight health: " << arr[i].get_health() << endl;
                        cout << "Player hp: " << h1.get_player_health() << endl;
                    }
                }
                //Else case for unexpected cases (should not happen)
                else {
                    break;
                }
            }//While loop ends

            //Player health check
            if(h1.get_player_health()<=0){
                cout << "Defeated" << endl;
                //exit(EXIT_FAILURE);
                return;
            }
            else{
            cout<<"Beaten knight " << i+1 << "..." << endl;
            }
        }//If loop ends
    }//For loop ends
    cout << "Successfully exterminated " << k13.current_knight()<< " knights..." << endl;
    cout << "----------------------------------------------------------------------------"<<endl;
    //End of the Knight arc

    //knight variables
    delete k1;

    //Mage arc begins!
    magearc(h1.get_player_health(),h1.get_player_mana());

    return;
}



//Defining functions used for input attacks

//Function used to get input
void heroAttack(){
    repeat:
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
        goto repeat; //loop back to repeat label for input
    }
}
