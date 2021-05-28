// Jacob Schneck
// CS 1wait0
// Module-wait: Open Ended Project

#include "Family.h"
#include "Lobster.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
using namespace std;

bool isInVector(vector<string> &vec, string item);
bool removeFromVector(vector<string> &vec, string item);

int main() {
    Lobster larry;
    string userInput;
    string user;
    Family userFamily;
    double wait = 1; // speed of printing 

    cout << "Hello and Welcome!" << endl;
    sleep(wait); 
    cout << "This is a virtual pet simulator" << endl;
    sleep(wait);
    cout << "First things first, what is your name?" << endl;
    getline(cin, userInput);
    user = userInput;

    cout << "What are your family members names? (press n to leave)" << endl;
    cout << "(For the sake of the program please enter at least three names)" << endl;
    int ct = 0; 
    while (ct <3) {
        getline(cin, userInput);
        if (userInput == "n") {
            cout << "Oi, at least three family members, follow directions!" << endl;
            continue;
        }
        userFamily.addMember(userInput);
        ct++;
    }
    while(userInput != "n") {
        getline(cin, userInput);
        if (userInput != "n") {
            userFamily.addMember(userInput);
        }
    }
    cout << "Your family: " << endl;
    sleep(wait);
    userFamily.printMembers(cout);
    cout << endl;

    cout << "Now lets start the simulation" << endl;
    sleep(wait);
    cout << "Your have a pet lobster." << endl;
    sleep(wait);
    cout << "His name is Larry." << endl;
    sleep(wait);
    cout << "He needs food." << endl;
    sleep(wait);
    cout << "Lets go to the pantry." << endl;
    sleep(wait);

    vector<string> pantry = {"Cat food", 
                             "Dog food", 
                             "Lobster food", 
                             "Fish food",
                             "Butter", 
                             "I can't Believe its not Butter", 
                             "Gary the Snail", 
                             "Tofu", 
                             "Carnivourous Tofu",
                             "Chocolate Chips",
                             "Kale",
                             "Almonds",
                             "A human foot",
                             "Mince meat pie"};  
    
    cout << "\nYou have: " << endl;
    // Print pantry
    for (auto &p : pantry) {
        sleep(wait/2);
        cout << p << endl;
    }

    // Add food into larry's diet
    larry.addFood(pantry[0]);
    larry.addFood(pantry[1]);
    larry.addFood(pantry[3]);
    larry.addFood(pantry[6]);
    larry.addFood(pantry[7]);
    larry.addFood(pantry[10]);
    larry.setFavoriteFood(pantry[6]);
    for (auto &f : userFamily.getMembers()) {
        larry.addFood(f);
    }

    cout << "\nLarry eats 6 of these items." << endl;

    bool lobsterFood;
    int prevHungerLevel = 0;
    int currHungerLevel; 
    vector<string> contents;

    // Huge while loop to play the game
    while(userFamily.getMembers().size() > 0) {
        
        cout << "Larry's Hunger level is " << prevHungerLevel << " out of 100" << endl;
        sleep(wait);
        cout << "\nFeed him (type pantry to see food list): ";


        getline(cin, userInput);
        if (userInput == "pantry") {
            for (auto &p : pantry) {
                cout << p << endl;
            }
            cout << "\nFeed him (type pantry to see food list): ";
            getline(cin, userInput);
        } 
        // Is it in the pantry?
        if (isInVector(pantry, userInput)) {
            lobsterFood = larry.feed(userInput);
            // Check to see if it is lobster food and do things
            if (lobsterFood) {
                cout << "Chomp!" << endl;
                sleep(wait);
                
                // Get his current hunger level
                currHungerLevel = larry.getStomache().getHungerLevel();
                // Get his stomahce contents
                contents = larry.getStomache().getContents();
                // Favorite food
                if (currHungerLevel - prevHungerLevel > 11) { 
                    cout << "Larry loves eating " << userInput << ". Its his favorite" << endl;
                    sleep(wait);
                    removeFromVector(pantry, userInput); 
                    cout << "We are now out of " << userInput << "." << endl;
                    prevHungerLevel = currHungerLevel;
                // Win Condition (Larry has been fed)
                } else if (currHungerLevel - prevHungerLevel <= 0) {
                    cout << "Larry pukes up: " << endl;
                    for (auto &c : contents) {
                        sleep(wait / 2);
                        cout << c << endl;
                    }
                    sleep(wait);
                    cout << "Larry's stomache is empty" << endl;
                    sleep(wait);
                    cout << "Larry demands flesh!" << endl;
                    while (0 < userFamily.getMembers().size()) {
                        sleep(wait);
                        userFamily.removeMember(cout);
                    }
                // All Other foods
                } else {
                    cout << "Larry enjoys " << userInput << endl;
                    removeFromVector(pantry, userInput); 
                    cout << "We are now out of " << userInput << "." << endl;
                    prevHungerLevel = currHungerLevel;
                }
            
            // Wrong guess
            } else {
                cout << "Oh Nooo! Larry doesn't like that" << endl;
                sleep(wait);
                cout << "He's gonna eat..." << endl;
                sleep(wait);
                userFamily.removeMember(cout);
                cout << "You lost a family member." << endl;
                sleep(wait);
                cout << endl;
                cout << "Your family is now" << endl;
                userFamily.printMembers(cout);
                sleep(wait);
                if (userFamily.getMembers().size() == 0) {
                    cout << "... gone" << endl;
                }
            }
        
        // Not in pantry
        } else {
            cout << "Sorry, thats not in stock" << endl;
        }
    }

    cout << "\nLarry turns his putrid eyes toward you...\n" << endl;
    sleep(wait);

    cout << "Thanks for playing!" << endl;

    return 0;
}

bool isInVector(vector<string> &vec, string item) {
    // more efficient way is binary search but whatever
    for (auto &el : vec) {
        if (el == item) {
            return true;
        }
    }
    return false;
}

bool removeFromVector(vector<string> &vec, string item) {
    int index = 0;
    for (auto &el : vec) {
        if (el == item) {
            vec.erase(vec.begin() + index);
            return true;
        }
        index++;
    }
    return false;
}
