//
// Created by Muhammad Sunaam on 25/12/2022.
//

#ifndef PROJECT_NEW_PROPERTY_H
#define PROJECT_NEW_PROPERTY_H
#include <string>
#include "Location.h"
#include "Purpose.h"
#include "PropertyType.h"
//#include "Owner.h"
using namespace std;
class Owner;
class Property{
    int propertyId, baths, bedrooms;
    string pageUrl, dateAdded;
    propertyType propertyType;
    purpose purpose;
    long int price;
    Location* location;
    Owner* owner;
public:
    string getDate();
    void print();
    int getPropertyId() const;
    Property();
    bool isEmpty() const;
    Property(int id, int baths, int bedrooms, string url, string date, long int price, enum propertyType pType, enum purpose purpose, Location* loc, Owner* owner);
    bool operator= (Property obj2);
};

int Property::getPropertyId() const {
    return propertyId;
}

bool Property::isEmpty() const {
    return propertyId == 0;
}

Property::Property( int id, int baths, int bedrooms, string url, string date, long int price,
                    enum propertyType pType,enum purpose purpose, Location *loc, Owner* owner) {
    propertyId = id;
    this->baths = baths;
    this->bedrooms = bedrooms;
    this->pageUrl = url;
    this->dateAdded = date;
    this->price = price;
    this->propertyType = pType;
    this->purpose = purpose;
    this->location = loc;
    this->owner = owner;
}

Property::Property() {
    propertyId = 0;
    this->baths = 0;
    this->bedrooms = 0;
    this->pageUrl = "";
    this->dateAdded = "";
    this->price = 0;
    this->propertyType = NAN;
    this->purpose = NA;
    this->location = nullptr;
    this->owner = nullptr;
}



bool Property::operator=(Property obj1) {
    return (this->propertyId == obj1.propertyId);
}

string Property::getDate() {
    return dateAdded;
}


#endif //PROJECT_NEW_PROPERTY_H
