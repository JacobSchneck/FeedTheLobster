// Jacob Schneck
// CS 120
// Module-2: Open Ended Project

#include "Family.h"
#include <ctime>
#include <stdlib.h>
using namespace std;


//----------------------- Constructors -----------------

//----------------------- Getters -----------------------
vector<string> Family::getMembers() const {
    return members;
}

//----------------------- Setters -----------------------
void Family::addMember(string name) {
    members.push_back(name);
}

//----------------------- Non Trivial Methods -----------

string Family::removeMember(std::ostream &outs) {
    int familyIndex = rand() % members.size(); 
    int messageIndex = rand() % GOODBYE_MESSAGES.size();
    string removedMember  = members[familyIndex];
    outs << GOODBYE_MESSAGES[messageIndex] << removedMember << endl;

    // remove family members from members variable
    members.erase(members.begin() + familyIndex);
    return removedMember;
}

void Family::printMembers(std::ostream &outs) {
    for (auto &m : members) {
        outs << m << " ";
    }
    outs << endl;
}