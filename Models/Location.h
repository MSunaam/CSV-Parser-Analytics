//
// Created by Muhammad Sunaam on 25/12/2022.
//

#ifndef PROJECT_NEW_LOCATION_H
#define PROJECT_NEW_LOCATION_H

#include<string>
#include "City.h"
#include "Province.h"
using namespace std;

class Location{
    double latitude, longitude;
    string location_name;
    Province province;
    City city;
    int locationId;
public:
    Location();
    Location(int id, string name, double latitude, double longitude, string province, string city);
    void print();
};

Location::Location() {
    this->locationId = 0;
    this->location_name = "";
    this->latitude = 0;
    this->longitude = 0;
    this->province = Null;
    this->city = Empty;
}

Location::Location(int id, string name, double latitude, double longitude, string province, string city) {
    this->locationId = id;
    this->location_name = name;
    this->latitude = latitude;
    this->longitude = longitude;
    this->province = provinceMap[province];
    this->city = cityMap[city];
}

void Location::print() {
    cout << "Location ID: " << locationId << endl;
    cout << "Location Name: " << location_name << endl;
    cout << "Latitude: " << latitude << endl;
    cout << "Longitude: " << longitude << endl;
    cout << "Province: " << valuesProvinceMap[province] << endl;
    cout << "City: " << valuesCityMap[city] << endl;
}

#endif //PROJECT_NEW_LOCATION_H
