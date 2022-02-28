#include "dragon.h"
#include "knight.h"
#include "mage.h"
#include "player.h"
#include "hero.h"
#include "enemy.h"
#include <climits>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;


//Function Names: (Defined after the end of main function)
void heroAttack();
int getting_input();


//Global variables
    //Player part
    hero h1;


//Main Function: Execution of the game
int main(){

//Creating objects
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


//Calling functionss
    //Knight arc

    //Introductory message to the game
    cout<<"Welcome to the game Dragon Quest! Your journey begins here..." << endl;
    cout<<"For a thousand years, a mystical dragon has ruled the world and spread evil over the entire planet." << endl;
    cout<<"As the legendary hero weilding an unwavering will to protect others, you set out on a journey to protect your loved ones..."<<endl;
    cout<<"After a long and tiresome war you have successfully infiltrated the dragon's lair in the palace of Elvshire. Your real battle against evil begins anew..." << endl;

    k1->prologue();//Prologue for knight class
    cout<<"Current knights: " << k13.current_knight()<<endl;

    //For loop iterating new knights to the game
    for(int i=0;i<3;i++){
        if (k13.add_knight(&arr[i]) && h1.get_player_health() > 0){
            cout<<"Knight "<< i+1 << " entered the battlefield..."<<endl;
            //While loop to repeat code if needed
            while (arr[i].get_health()>0 && h1.get_player_health() > 0){
                    heroAttack();//Attaining input from user for attack
                    cout << "player current hp:" << h1.get_player_health() << endl;
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
            exit(EXIT_FAILURE);
            }
            else{
            cout<<"Beaten knight " << i+1 << "..." << endl;
            }
        }//If loop ends
    }//For loop ends
    cout << "Successfully exterminated " << k13.current_knight()<< " knights..." << endl;
    //End of the Knight arc


    //Mage arc
    m1->prologue();//Prologue for mage class
    cout<<"Current mages: " << m13.current_mage()<<endl;

    //Mage class arc starts: For loop to add new mages to the game
    for(int i=0;i<2;i++){

        //If statement to add new mages
        if (m13.add_mage(&array_interface[i])&& h1.get_player_health() > 0){
            cout<<"Mage "<< i+1 << " entered the battlefield..."<<endl;

            //While loop to ensure mage and player health is above 0
            while (array_interface[i].get_magic()>0 && h1.get_player_health() > 0){
                heroAttack();//Inputting attack from user
                //Defining status
                cout << "player current hp:" << h1.get_player_health() << endl;
                array_interface[i].set_magic(array_interface[i].get_magic()-h1.get_health_dmg());
                cout << "Mage health: " << array_interface[i].get_magic() << endl;
                //If statement to begin mage counter attack
                if (array_interface[i].get_magic()>0){
                    int random_2=m2.random_number();//Random attack definition
                    //Attack 1
                    if (random_2==1){
                        cout<<"You have been hit with "<<m10.get_attack_name()<<", -"<<m10.get_attack_magic()<<" magic..."<<endl;
                        h1.set_player_health(h1.get_player_health()-m10.get_attack_magic());
                        cout << "Player hp: " << h1.get_player_health() << endl;
                        h1.set_player_mana(h1.get_player_mana() - m10.get_attack_magic());
                        cout << "Player mana:" << h1.get_player_mana() << endl;
                    }

                    //Attack 2
                    if (random_2==2){
                        cout<<"You have been hit with "<<m11.get_attack_name()<<", -"<<m11.get_attack_magic()<<" magic..."<<endl;
                        h1.set_player_health(h1.get_player_health()-m11.get_attack_magic());
                        cout << "Player hp: " << h1.get_player_health() << endl;
                        h1.set_player_mana(h1.get_player_mana() - m11.get_attack_magic());
                        cout << "Player mana:" << h1.get_player_mana() << endl;
                    }

                    //Attack 3
                    if (random_2==3){
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
            }//While loop ends

            //Player health check
            if(h1.get_player_health()<=0){
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



    //Dragon arc begins
    d1->prologue();//Prologue and status definition(below):
    cout << "Health: " << d2->get_health() << endl;
    cout << "Magic: " << d3->get_magic() << endl;
    cout << "++++++ 100 MANA +++++" << endl << "Player Mana now at 100" << endl << endl;
    h1.set_player_mana(100);

    //While loop to ensure player is alive while game continues
    while (d2->get_health()>0 && h1.get_player_health() > 0){

        heroAttack();//Obtaining input
        cout << "player current hp:" << h1.get_player_health() << endl;
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
        exit(EXIT_FAILURE);
    }
    cout << "Successfully slayed the dragon prince!" << endl;
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
    //knight variables
    delete k1;
    //mage variables
    delete m1;

    //Returning 0
    return 0;
}



//Defining functions used for input attacks

//Function: Used to get only valid input
int getting_input (){
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

//End of the game