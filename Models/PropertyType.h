//
// Created by Muhammad Sunaam on 31/12/2022.
//

#ifndef PROJECT_NEW_PROPERTYTYPE_H
#define PROJECT_NEW_PROPERTYTYPE_H

#include <map>
using namespace std;



enum propertyType {
    NAN,
    Farm_House,
    Flat,
    House,
    Lower_Portion,
    Penthouse,
    Room,
    Upper_Portion,
};

map<string, propertyType> typeMap = {
        { "Farm House", propertyType::Farm_House },
        { "Flat", propertyType::Flat },
        {"House", propertyType::House},
        {"Lower Portion", propertyType::Lower_Portion},
        {"Penthouse", propertyType::Penthouse},
        {"Room", propertyType::Room},
        {"Upper Portion", propertyType::Upper_Portion},
        {"", propertyType::NAN}
};

map<propertyType, string> typeMapValues = {
        {propertyType::Farm_House, "Farm House"},
        {propertyType::Flat, "Flat"},
        {propertyType::House, "House"},
        {propertyType::Lower_Portion, "Lower Portion"},
        {propertyType::Penthouse, "Penthouse"},
        {propertyType::Room, "Room"},
        {propertyType::Upper_Portion, "Upper Portion"},
        {propertyType::NAN, ""}
};

#endif //PROJECT_NEW_PROPERTYTYPE_H
