//
// Created by Muhammad Sunaam on 01/01/2023.
//

#ifndef PROJECT_NEW_FUNCTIONS_H
#define PROJECT_NEW_FUNCTIONS_H

#include <iostream>
#include <string>
#include "../DataStructures/AVLOwner.h"
#include "../DataStructures/AVLOwnerSortAgency.h"
using namespace std;

void searchForAgent(AVLOwner* owners, string agent){
    owners->printByAgent(agent);
}

void searchForAgency( AVLOwnerSortAgency* agencies, string agency){
    agencies->printByAgency(agency);
}


#endif //PROJECT_NEW_FUNCTIONS_H
