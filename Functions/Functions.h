//
// Created by Muhammad Sunaam on 01/01/2023.
//

#ifndef PROJECT_NEW_FUNCTIONS_H
#define PROJECT_NEW_FUNCTIONS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../CSV/csv.h"
#include "../DataStructures/AVLOwner.h"
#include "../DataStructures/AVLOwnerSortAgency.h"
#include "../Models/Property.h"
#include "../DataStructures/HashTableAVL.h"
using namespace std;



void storeInStructures(string path, int size, AVLOwnerSortAgency *agenciesTree, AVLOwner *ownerTree, HashTableAVL *propertyTable){

    propertyTable = new HashTableAVL(200000);

    ownerTree = new AVLOwner();

    agenciesTree = new AVLOwnerSortAgency();

    std::ifstream in(path);
    if (in.fail()){
        (cout << "File not found" << endl);
        return;
    }
    int counter = 0;


    int property_id, baths, bedrooms, location_id;
    long int price;
    string page_url, location, city, province, area, date, agency, agent;
    double latitude, longitude;
    enum propertyType type;
    enum purpose purpose;


    while(in.good() and counter <= 200000)
    {
        std::vector<std::string> row = csv_read_row(in, ',');
        if(counter != 0){
            //read the row and parse into PropertyObject
            for(int i = 0, leng = row.size(); i < leng; i++){
                switch ( i ) {
                    case 0:
                        !row[i].empty() ? property_id = stoi(row[i]) : property_id = 0;
                        break;
                    case 1:
                        !row[i].empty() ? location_id = stoi(row[i]) : location_id = 0;
                        break;
                    case 2:
                        page_url = row[i];
                        break;
                    case 3:
                        type = typeMap[row[i]];
                        break;
                    case 4:
                        !row[i].empty() ? price = stoi(row[i]) : price = 0;
                        break;
                    case 5:
                        location = row[i];
                        break;
                    case 6:
                        city = row[i];
                        break;
                    case 7:
                        province = row[i];
                        break;
                    case 8:
                        !row[i].empty() ? latitude = stod(row[i]) : latitude = 0;
                        break;
                    case 9:
                        !row[i].empty() ? longitude = stod(row[i]) : longitude = 0;
                        break;
                    case 10:
                        !row[i].empty() ? baths = stoi(row[i]) : baths = 0;
                        break;
                    case 11:
                        area = row[i];
                    case 12:
                        purpose = purposeMap[row[i]];
                        break;
                    case 13:
                        !row[i].empty() ? bedrooms = stoi(row[i]) : bedrooms = 0;
                        break;
                    case 14:
                        date = row[i];
                        break;
                    case 15:
                        agency = row[i];
                        break;
                    case 16:
                        agent = row[i];
                        break;
                    default:
                        break;
                }
            }
            Location *loc = new Location(location_id, location, latitude, longitude, province, city);
            Owner* owner = new Owner(agency, agent);
            Property *prop = new Property(property_id, baths, bedrooms, page_url, date, price, type, purpose, loc, owner);

            //Insert property into owner
//            owner->insertProperty(prop);

            if(agency == "Estate Region"){

            }

            //Insert Owner Into Owner Tree according to agent
            ownerTree->setRoot(ownerTree->insertNode(owner, ownerTree->getRoot(), prop));

            //Insert Owner Into Owner Tree sorted by Agencies
            agenciesTree->setRoot(agenciesTree->insertNode(owner, agenciesTree->getRoot(), prop));

            //Insert property into hash table
            propertyTable->insertIntoTable(prop);
        }
        counter++;
    }
}

void searchForAgent(AVLOwner* owners, string agent){
    owners->printByAgent(agent);
}

void searchForAgency( AVLOwnerSortAgency* agencies, string agency){
    agencies->printByAgency(agency);
}

void searchPropertyByID(int id, HashTableAVL* table){
    Property* aProperty = table->getValueByID(id);
    if(aProperty) aProperty->print();
}


#endif //PROJECT_NEW_FUNCTIONS_H
