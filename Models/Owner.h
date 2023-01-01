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
    void printForOwner(){
        cout << "Agency: " << agency << endl;
        cout << "Agent: " << agent << endl;
        cout << "_____Properties_____" << endl;
        properties->printPreOrder(properties->getRoot());
    }
    void printFromProperty(){
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
        properties->setRoot(properties->insertNode(aProperty, properties->getRoot()));
    }
    Property* getFirstPropertyInserted(){
        return properties->getRootObject();
    }
};

#endif //PROJECT_NEW_OWNER_H
