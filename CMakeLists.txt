cmake_minimum_required(VERSION 3.23)
project(Project_New)

set(CMAKE_CXX_STANDARD 11)

add_executable(Project_New
        main.cpp Models/Property.h Models/Location.h Models/Owner.h DataStructures/AVLProperty.h Models/PropertyType.h Models/Purpose.h CSV/csv.h DataStructures/HashTableAVL.h DataStructures/AVLOwner.h printFunction.h Models/City.h Models/Province.h Functions/Functions.h DataStructures/AVLOwnerSortAgency.h DataStructures/AVLSortByDate.h)



