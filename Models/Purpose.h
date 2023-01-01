//
// Created by Muhammad Sunaam on 31/12/2022.
//

#ifndef PROJECT_NEW_PURPOSE_H
#define PROJECT_NEW_PURPOSE_H

#include <map>
using namespace std;

enum purpose{
    NA,
    Rent,
    For_Sale,
};

//map
map<string, purpose> purposeMap = {
        {"Rent", purpose::Rent},
        {"For Sale", purpose::For_Sale},
        {"", purpose::NA}
};

map<purpose, string> purposeMapValues = {
        {purpose::Rent,"Rent"},
        {purpose::For_Sale, "For Sale"},
        {purpose::NA, ""}
};

#endif //PROJECT_NEW_PURPOSE_H
