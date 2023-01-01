//
// Created by Muhammad Sunaam on 01/01/2023.
//

#ifndef PROJECT_NEW_FUNCTIONS_H
#define PROJECT_NEW_FUNCTIONS_H

#include <iostream>
#include "../DataStructures/AVLAgent.h"
#include "../Models/Owner.h"
using namespace std;

void searchForAgent( AVLAgent* ownerTree, string agent){
    Owner* owner = ownerTree->getAgent(agent);
    if(owner == nullptr){
        cout << "Agent not found" << endl;
    }
    else{
        if(owner->getAgentName() == agent){
            owner->printForOwner();
        }else{
            cout << "Agent not found" << endl;
        }
    }

}

void searchForAgency( AVLAgency* ownerTree, string agency){
    Owner* owner = ownerTree->getAgency(agency);
    if(owner == nullptr){
        cout << "Agency not found" << endl;
    }
    else{
        if(owner->getAgencyName() == agency){
            owner->printForOwner();
        }else{
            cout << "Agency not found" << endl;
        }
    }
}

#endif //PROJECT_NEW_FUNCTIONS_H
