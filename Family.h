// Jacob Schneck
// CS 120
// Module-2: Open Ended Project

#include <ostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

class Family { 
    private:
        vector<string> members;
        const vector<string> GOODBYE_MESSAGES = {"NOOOOOOO! -screamed ",
                                                 "Weird way to go but oh well -said ", 
                                                 "Sweet sweet relief -sighed ",
                                                 "I want my Mommmy!!! -cried "};
    public:
        // Constructors;
        Family() = default;

        // Getters;
        vector<string> getMembers() const;

        // Setters;
        void addMember(string name);

        // Non Trivial Functions;

        // Randomly remove a member from the family
        string removeMember(std::ostream &outs);
        void printMembers(std::ostream &outs);

};