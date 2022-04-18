#include <iostream>
#include <climits>
#include "input.h"
using namespace std;

//Function: Used to get only valid input
int getting_input(){
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