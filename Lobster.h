// Jacob Schneck
// CS 120
// Module-2: Open Ended Project

#ifndef LOBSTER_H
#define LOBSTER_H

#include "Pet.h"

class Lobster : public Pet {
    private: 
        string favorite_food;
        Stomache stomache; // Every Lobster has a stomache not every pet does (looking at you pet rocks)
    
    public:
        Lobster();
        explicit Lobster(string name, string owner, vector<string> foods, string favorite_food);
    
        // Getters;
        string getFavoriteFood() const;
        Stomache getStomache() const;

        // Setters;
        void setFavoriteFood(string favorite_food);

        // Non-Trivial Methods
        virtual bool feed(string food) override; 
};

#endif 