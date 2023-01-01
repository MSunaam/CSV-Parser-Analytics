//
// Created by Muhammad Sunaam on 25/12/2022.
//

#ifndef PROJECT_NEW_OWNER_H
#define PROJECT_NEW_OWNER_H

#include<string>
#include "../DataStructures/AVLProperty.h"
using namespace std;

class Owner{
    string agency, agent;
public:
    Owner(string agency, string agent){
        this->agency = agency;
        this->agent = agent;
    }
    void print(){
        cout << "Agency: " << agency << endl;
        cout << "Agent: " << agent << endl;
    }
    string getAgencyName(){
        return agency;
    }
    string getAgentName(){
        return agent;
    }
};

#endif //PROJECT_NEW_OWNER_H
