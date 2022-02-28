//Test file for mage functions
#include <iostream>
#include "mage.h"
using namespace std;

//Main Function
int main(){

    int tests_run=0;
    int tests_passed=0;

    //Test1: Set magic and get health
    {
        mage a;
        mage b;
        tests_run++;
        a.set_magic(-100);
        b.set_magic(0);

        if (a.get_magic()==0 && b.get_magic()==0){
            tests_passed++;
            cout << "Test 1 successful!" << endl;
        }
        else {
            cout << "Test 1 failed..." << endl;
        }
    }

    //Test 2: Random number generator
    {
        mage a;
        tests_run++;
        int random;
        int random_pass=0;
        for (int i=0; i<100; i++){
            random=a.random_number();
            if (random<=3 && random>=1){
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
//Test 3: Set and get magic health
    {
        mage a;
        mage b;
        tests_run++;
        a.set_attack_magic(0);
        b.set_attack_magic(100000000);

        if (a.get_attack_magic()==0 && b.get_attack_magic()==100000000){
            tests_passed++;
            cout << "Test 3 successful!" << endl;
        }
        else {
            cout << "Test 3 failed..." << endl;
        }
    }

    //Test 4: Set and get attack name
    {
        mage a;
        mage b;
        tests_run++;
        a.set_attack_name("0");
        b.set_attack_name("mage_name_for_this_object");

        if (a.get_attack_name()=="0" && b.get_attack_name()=="mage_name_for_this_object"){
            tests_passed++;
            cout << "Test 4 successful!" << endl;
        }
        else {
            cout << "Test 4 failed..." << endl;
        }
    }

    //Test 5: Get mage count
    {
        mage a;
        tests_run++;

        if (a.current_mage()==0){
            tests_passed++;
            cout << "Test 5 successful!" << endl;
        }
        else {
            cout << "Test 5 failed..." << endl;
        }
    }

    //Test 6: Mage array addition
    {
        mage a(0,2);
        mage b;
        mage arr[]={a,b};

        tests_run++;

        if (a.current_mage()==0){
            a.add_mage(& arr[1]);
            if (a.current_mage()==1){
                cout << "Test 6 part 1 successful!" << endl;
                a.add_mage(& arr[2]);
                if (a.current_mage()==2){
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
//End of unit testing for mage class