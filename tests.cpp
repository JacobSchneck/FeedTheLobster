// Jacob Schneck
// CS 120
// Module-2: Open Ended Project

#include "Family.h"
#include "Lobster.h"
#include "Pet.h"
#include <iostream>
using namespace std;

bool testingStomache();
bool testingLobster();
bool testingFamily();

int main() {
    cout << "Testing Stomache Class" << endl;
    testingStomache();
    cout << "Tests Finished" << endl << endl;

    cout << "Testing Lobster Class" << endl;
    testingLobster();
    cout << "Tests Finished" << endl << endl;

    cout << "Testing Family Class" << endl;
    testingFamily();
    cout << "Tests Finished" << endl << endl;

    return 0;
}

bool testingStomache() {
    bool passed = true;
    Stomache tumtum = Stomache();

    if (tumtum.getHungerLevel() != 0) {
        cout << "Test one failed" << endl;
    }

    tumtum.addContents("broccoli");
    if(tumtum.getContents()[0] != "broccoli") {
        cout << "Test two failed" << endl;
        passed = false;
    }

    tumtum.setHungerLevel(50);
    if (tumtum.getHungerLevel() != 50) {
        cout << "Test three failed" << endl;
        passed = false;
    }

    tumtum.setHungerLevel(51);
    if (tumtum.getHungerLevel() != 0 && tumtum.getContents().size() != 0) { 
        cout << "Test four failed" << endl;
        passed = false;
    }
    
    tumtum.addContents("Cheese");
    tumtum.addContents("Crisps");
    if (tumtum.getContents().size() != 2) {
        cout << "Test five failed" << endl;
        passed = false;
    }
    
    return passed;
}

bool testingLobster() {
    bool passed = true;
    Lobster pet; 
    vector<string> larry_foods = {"pizza", "flesh", "ketchup"};
    Lobster larry = Lobster("Larry", "Jacob Schneck", larry_foods, "Gary the Snail");

    // Testing Default Constructor 
    if (pet.getName() != "Pet" && pet.getOwner() != "John Doe", pet.getFoods().size() != 1 && pet.getFavoriteFood() != "flesh") {
        cout << "Test One failed" << endl;
        passed = false;
    }

    if (larry.getName() != "Larry" && larry.getOwner() != "John Doe" && larry.getFoods().size() != 4 && larry.getFavoriteFood() != "Gary the Snail") {
        cout << "Test two failed" << endl;
        passed = false;
    }

    larry.feed("Gary the Snail");
    if (larry.getStomache().getHungerLevel() != 50) {
        cout << "Test three failed" << endl;
        passed = false;
    }
    
    pet.addFood("Johnny");
    pet.feed("Johnny");
    if (pet.getStomache().getHungerLevel() != 10) {
        cout << "Test four failed" << endl;
        passed = false;
    }

    if (pet.feed("Kyle") != false) {
        cout << "Test five failed" << endl;
        passed = false;
    }

    return passed;
}

bool testingFamily() {
    bool passed = true;

    Family f;
    f.addMember("kyle");     
    f.addMember("Sasha");
    if (f.getMembers().size() != 2) {
        cout << "Test one failed" << endl;
        passed = false;
    }

    f.addMember("Bernie");
    f.addMember("Killroy");
    f.addMember("Amadeus");
    f.printMembers(cout);

    f.removeMember(cout);
    f.removeMember(cout);
    f.removeMember(cout);
    f.removeMember(cout);
    if (f.getMembers().size() != 1) {
        cout << "Test two failed" << endl;
        passed = false;
    }

    return passed;
}
