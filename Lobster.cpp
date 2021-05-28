// Jacob Schneck
// CS 120
// Module-2: Open Ended Project

#include "Lobster.h"

//----------------------- Constructors -----------------
Lobster::Lobster() : Pet(), favorite_food(foods[0]) {}

Lobster::Lobster(string name, string owner, vector<string> foods, string favorite_food) : Pet(name, owner, foods) {
    setFavoriteFood(favorite_food);
}

//----------------------- Getters -----------------------
string Lobster::getFavoriteFood() const {
    return favorite_food;
}

Stomache Lobster::getStomache() const {
    return stomache;
}

//----------------------- Setters -----------------------
void Lobster::setFavoriteFood(string favorite_food) {
    this->favorite_food = favorite_food;
    // check to see if favorite food is in foods
    bool found = false;
    for (string f : foods) {
        if (f == favorite_food) {
            found = true;
            break;
        }
    }

    if (!(found)) {
        foods.push_back(favorite_food);
    }
}


//----------------------- Non Trivial Methods -----------

// Function to feed the lobster
bool Lobster::feed(string food) {

    bool isFoodPresent = false;
    
    for (auto &f : foods) {
        if (food == f) {
            isFoodPresent = true;
        }
    }
    if (!isFoodPresent) {
        return isFoodPresent;
    }

    if (food == favorite_food) {
        stomache.setHungerLevel(50);
        return isFoodPresent;
    }
    stomache.setHungerLevel(10);
    return isFoodPresent;
}