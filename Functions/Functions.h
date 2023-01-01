//
// Created by Muhammad Sunaam on 01/01/2023.
//

#ifndef PROJECT_NEW_FUNCTIONS_H
#define PROJECT_NEW_FUNCTIONS_H

#include <iostream>
#include <string>
#include "../DataStructures/AVLOwner.h"
using namespace std;

void searchForAgent(AVLOwner* owners, string agent){
    owners->printByAgent(agent);
}


#endif //PROJECT_NEW_FUNCTIONS_H
