//Test file for knight functions
#include <iostream>
#include "knight.h"
using namespace std;

//Main function
int main(){

    int tests_run=0;
    int tests_passed=0;

    //Test1: Set health and get health
    {
        knight a;
        knight b;
        tests_run++;
        a.set_health(-100);
        b.set_health(0);

        if (a.get_health()==0 && b.get_health()==0){
            tests_passed++;
            cout << "Test 1 successful!" << endl;
        }
        else {
            cout << "Test 1 failed..." << endl;
        }
    }

    //Test 2: Random number generator
    {
        knight a;
        tests_run++;
        int random;
        int random_pass=0;
        for (int i=0; i<100; i++){
            random=a.random_number();
            if (random<=4 && random>=1){
                random_pass++;
            }
        }
        if (random_pass==100){
            tests_passed++;
            cout << "Test 2 successful!" << endl;
        }
        else {
            cout << "Test 2 failed..." << endl;
        }

    }

    //Test 3: Set and get attack health
    {
        knight a;
        knight b;
        tests_run++;
        a.set_attack_health(0);
        b.set_attack_health(100000000);

        if (a.get_attack_health()==0 && b.get_attack_health()==100000000){
            tests_passed++;
            cout << "Test 3 successful!" << endl;
        }
        else {
            cout << "Test 3 failed..." << endl;
        }
    }

    //Test 4: Set and get attack name
    {
        knight a;
        knight b;
        tests_run++;
        a.set_attack_name("0");
        b.set_attack_name("knight_name_for_this_object");

        if (a.get_attack_name()=="0" && b.get_attack_name()=="knight_name_for_this_object"){
            tests_passed++;
            cout << "Test 4 successful!" << endl;
        }
        else {
            cout << "Test 4 failed..." << endl;
        }
    }

    //Test 5: Get knight count
    {
        knight a;
        tests_run++;

        if (a.current_knight()==0){
            tests_passed++;
            cout << "Test 5 successful!" << endl;
        }
        else {
            cout << "Test 5 failed..." << endl;
        }
    }

    //Test 6: Knight array addition
    {
        knight a(0,2);
        knight b;
        knight arr[]={a,b};

        tests_run++;

        if (a.current_knight()==0){
            a.add_knight(& arr[1]);
            if (a.current_knight()==1){
                cout << "Test 6 part 1 successful!" << endl;
                a.add_knight(& arr[2]);
                if (a.current_knight()==2){
                    tests_passed++;
                    cout << "Test 6 part 2 successful!" << endl;

                    //Defining status
                    cout << "Tests run: " << tests_run << endl;
                    cout << "Tests passed: " << tests_passed << endl;
                }
            }
            else{
                cout << "Test 6 failed..." << endl;
            }
        }
        else {
            cout << "Test 6 failed..." << endl;
        }
    }


    return 0;
}
//End of unit testing for knight class