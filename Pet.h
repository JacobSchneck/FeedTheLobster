// Jacob Schneck
// CS 120
// Module-2: Open Ended Project

#ifndef PET_H
#define PET_H

#include "Stomache.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

class Pet {
    protected:
        string name;
        string owner;
        vector<string> foods;

    public:
        // Constructors 
        Pet();

        explicit Pet(string name, string owner, vector<string> foods);

        // Getters
        string getName() const;
        string getOwner() const;
        vector<string> getFoods() const;

        // Setters;
        void setName(string name);
        void setOwner(string owner);
        void addFood(string food);

        // Methods that do other things
        virtual bool feed(string food) = 0;
};

#endif 
