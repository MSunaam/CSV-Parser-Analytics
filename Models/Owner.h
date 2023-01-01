//
// Created by Muhammad Sunaam on 25/12/2022.
//

#ifndef PROJECT_NEW_OWNER_H
#define PROJECT_NEW_OWNER_H

#include<string>
//#include "DataStructures/AVLProperty.h"

using namespace std;

class Owner{
    string agency, agent;
    AVLProperty *properties;
public:
    Owner(string agency, string agent){
        this->agency = agency;
        this->agent = agent;
        properties = new AVLProperty();
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
    void insertProperty(Property* aProperty){
        properties->insertNode(aProperty, properties->getRoot());
    }
};

#endif //PROJECT_NEW_OWNER_H
