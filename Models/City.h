//
// Created by Muhammad Sunaam on 01/01/2023.
//

#ifndef PROJECT_NEW_CITY_H
#define PROJECT_NEW_CITY_H

#include <string>
#include <map>
using namespace std;

enum City{
    Faisalabad,
    Islamabad,
    Karachi,
    Lahore,
    Rawalpindi,
    Empty
};

map<string, City> cityMap ={
    {"", Empty },
    {"Faisalabad", Faisalabad},
    {"Islamabad", Islamabad},
    {"Karachi", Karachi},
    {"Lahore", Lahore},
    {"Rawalpindi", Rawalpindi},
};

map<City, string> valuesCityMap = {
    {Empty, ""},
    {Faisalabad, "Faisalabad"},
    {Islamabad, "Islamabad"},
    {Karachi, "Karachi"},
    {Lahore, "Lahore"},
    {Rawalpindi, "Rawalpindi"},
};


#endif //PROJECT_NEW_CITY_H
