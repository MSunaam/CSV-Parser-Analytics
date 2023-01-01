//
// Created by Muhammad Sunaam on 01/01/2023.
//

#ifndef PROJECT_NEW_PROVINCE_H
#define PROJECT_NEW_PROVINCE_H

#include <map>
#include <string>
using namespace std;

enum Province{
    Null,
    IslamabadCapital,
    Puniab,
    Sindh,
};

map<string, Province> provinceMap = {
    {"", Null},
    {"Islamabad Capital", IslamabadCapital},
    {"Punjab", Puniab},
    {"Sindh", Sindh},
};

map<Province, string> valuesProvinceMap = {
        {Null, ""},
    {IslamabadCapital, "Islamabad Capital"},
    {Puniab, "Punjab"},
    {Sindh, "Sindh"},
};

#endif //PROJECT_NEW_PROVINCE_H
