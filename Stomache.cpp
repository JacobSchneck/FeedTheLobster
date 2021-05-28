// Jacob Schneck
// CS 120
// Module-2: Open Ended Project

#include "Stomache.h"

//----------------------- Constructors -----------------
Stomache::Stomache() : hunger_level(0) {}

//----------------------- Getters -----------------------
vector<string> Stomache::getContents() const {
    return contents;
}

int Stomache::getStomacheCapacity() const {
    return STOMACHE_CAPACITY;
}

int Stomache::getHungerLevel() const {
    return hunger_level;
}

//----------------------- Setters -----------------------
void Stomache::addContents(string foodItem) {
    contents.push_back(foodItem);
}

// Set Hunger level increments level rather than changing value
void  Stomache::setHungerLevel(int foodValue) {
    hunger_level += foodValue;
    checkHungerLevel();
}

//----------------------- Non-Trivial Methods ------------
bool Stomache::checkHungerLevel() {
    if (hunger_level >= STOMACHE_CAPACITY) {
        hunger_level = 0;    
        contents.clear();
        return true;
    }
    return false;
}
