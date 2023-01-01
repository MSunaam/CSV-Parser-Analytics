//
// Created by Muhammad Sunaam on 25/12/2022.
//

#ifndef PROJECT_NEW_LOCATION_H
#define PROJECT_NEW_LOCATION_H

#include<string>
using namespace std;

class Location{
    double latitude, longitude;
    string location_name, province, city;
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
    this->province = "";
    this->city = "";
}

Location::Location(int id, string name, double latitude, double longitude, string province, string city) {
    this->locationId = id;
    this->location_name = name;
    this->latitude = latitude;
    this->longitude = longitude;
    this->province = province;
    this->city = city;
}

void Location::print() {
    cout << "Location ID: " << locationId << endl;
    cout << "Location Name: " << location_name << endl;
    cout << "Latitude: " << latitude << endl;
    cout << "Longitude: " << longitude << endl;
    cout << "Province: " << province << endl;
    cout << "City: " << city << endl;
}

#endif //PROJECT_NEW_LOCATION_H
