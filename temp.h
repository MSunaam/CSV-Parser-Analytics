//
// Created by Muhammad Sunaam on 01/01/2023.
//

#include "Models/Property.h"
#include "Models/Owner.h"
#include <iostream>
using namespace std;

void Property::print() {
    if(propertyId != 0){
        cout << "Property ID: " << propertyId << endl;
        cout << "Baths: " << baths << endl;
        cout << "Bedrooms: " << bedrooms << endl;
        cout << "Page URL: " << pageUrl << endl;
        cout << "Date Added: " << dateAdded << endl;
        cout << "Price: " << price << endl;
        cout << "Property Type: " << typeMapValues[propertyType] << endl;
        cout << "Purpose: " << purposeMapValues[purpose] << endl;
        if(location == nullptr){
            cout << "Location: NULL" << endl;
        }else{
            location->print();
        }
        if(owner){
            owner->print();
        }else{
            cout << "Owner: NULL" << endl;
        }
    }else{
        cout << "Empty Slot" << endl;
    }
}