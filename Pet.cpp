// Jacob Schneck
// CS 120
// Module-2: Open Ended Project

#include "Pet.h"
using namespace std;

//----------------------- Constructors -----------------
Pet::Pet() : name("Pet"), owner("John Doe") {
    addFood("flesh");
}

Pet::Pet(string name, string owner, vector<string> foods) {
    this->name = name;
    this->owner = owner;
    this->foods = foods;
}
//----------------------- Getters -----------------------
string Pet::getName() const {
    return name;
}

string Pet::getOwner() const {
    return owner;
}

vector<string> Pet::getFoods() const{
    return foods;
}

//----------------------- Setters -----------------------
void Pet::setName(string name) {
    this->name = name;
}

void Pet::setOwner(string owner) {
    this->owner = owner;
}

void Pet::addFood(string food) {
    foods.push_back(food);
}

// void feed(string food