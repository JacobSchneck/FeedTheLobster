// Jacob Schneck
// CS 120
// Module-2: Open Ended Project

#ifndef STOMACHE_H
#define STOMACHE_H

#include <string>
#include <vector>
using std::string;
using std::vector;

class Stomache {
    private:
        vector<string> contents; 
        const int STOMACHE_CAPACITY = 100; 
        int hunger_level;

    public: 
        // Constructors 
        Stomache();

        // Getters
        vector<string> getContents() const;
        int getStomacheCapacity() const;
        int getHungerLevel() const;

        // Setters
        void addContents(string foodItem);
        void setHungerLevel(int foodValue);

        // Non Trivial Methods
        /*
        * Function that resets hunger_level and clears contents when Stomache_Capacity is reached
        * params: None
        * returns: boolean 
        */
        bool checkHungerLevel();

};

#endif
