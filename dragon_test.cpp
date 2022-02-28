//Test file for dragon functions
#include <iostream>
#include "dragon.h"
using namespace std;


//Main function
int main(){

    int tests_run=0;
    int tests_passed=0;

    //Test1: Set health and get health
    {
        dragon a;
        dragon b;
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

    //Test 2: Set magic and get magic
    {
        dragon a;
        dragon b;
        tests_run++;
        a.set_magic(-100);
        b.set_magic(0);

        if (a.get_magic()==0 && b.get_magic()==0){
            tests_passed++;
            cout << "Test 2 successful!" << endl;
        }
        else {
            cout << "Test 2 failed..." << endl;
        }
    }

    //Test 3: Random number generator
    {
        dragon a;
        tests_run++;
        int random;
        int random_pass=0;
        for (int i=0; i<100; i++){
            random=a.random_number();
            if (random<=5 && random>=1){
                random_pass++;
            }
        }
        if (random_pass==100){
            tests_passed++;
            cout << "Test 3 successful!" << endl;
        }
        else {
            cout << "Test 3 failed..." << endl;
        }

    }

    //Test 4: Set and get attack health
    {
        dragon a;
        dragon b;
        tests_run++;
        a.set_attack_health(0);
        b.set_attack_health(100000000);

        if (a.get_attack_health()==0 && b.get_attack_health()==100000000){
            tests_passed++;
            cout << "Test 4 successful!" << endl;
        }
        else {
            cout << "Test 4 failed..." << endl;
        }
    }

    //Test 5: Set and get attack magic
    {
        dragon a;
        dragon b;
        dragon c;
        tests_run++;
        a.set_attack_magic(0);
        b.set_attack_magic(100000000);
        c.set_attack_magic(-100);

        if (a.get_attack_magic()==0 && b.get_attack_magic()==100000000 && c.get_attack_magic()==-100){
            tests_passed++;
            cout << "Test 5 successful!" << endl;
        }
        else {
            cout << "Test 5 failed..." << endl;
        }
    }

    //Test 6: Set and get attack name
    {
        dragon a;
        dragon b;
        tests_run++;
        a.set_attack_name("0");
        b.set_attack_name("dragon_name_for_this_object");

        if (a.get_attack_name()=="0" && b.get_attack_name()=="dragon_name_for_this_object"){
            tests_passed++;
            cout << "Test 6 successful!" << endl;
        }
        else {
            cout << "Test 6 failed..." << endl;
        }
    }

    //Defining status for tests
    cout << "Tests run: " << tests_run << endl;
    cout << "Tests passed: " << tests_passed << endl;

    return 0;
}
//End of unit testing for dragon class