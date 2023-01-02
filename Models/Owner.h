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
    Owner(string agency, string agent);
    void printForOwner();
    void printFromProperty();
    string getAgencyName();
    string getAgentName();
    void insertProperty(Property* aProperty);
    Property* getFirstPropertyInserted();
    void printFromTree();
};

Owner::Owner(string agency, string agent){
this->agency = agency;
this->agent = agent;
properties = new AVLProperty();
}

void Owner::printForOwner(){
    cout << "Agency: " << agency << endl;
    cout << "Agent: " << agent << endl;
    cout << "_____Properties_____" << endl;
    properties->printPreOrder(properties->getRoot());
}
void Owner::printFromProperty(){
    cout << "Agency: " << agency << endl;
    cout << "Agent: " << agent << endl;
}
string Owner::getAgencyName(){
    return agency;
}
string Owner::getAgentName(){
    return agent;
}
void Owner::insertProperty(Property* aProperty){
    properties->setRoot(properties->insertNode(aProperty, properties->getRoot()));
}
Property* Owner::getFirstPropertyInserted(){
    return properties->getRootObject();
}

void Owner::printFromTree() {
    cout << "Agency: " << agency << endl;
    cout << "Agent: " << agent << endl;
}

#endif //PROJECT_NEW_OWNER_H
