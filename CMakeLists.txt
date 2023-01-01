cmake_minimum_required(VERSION 3.23)
project(Project_New)

set(CMAKE_CXX_STANDARD 11)

add_executable(Project_New
        main.cpp Models/Property.h Models/Location.h Models/Owner.h DataStructures/AVLProperty.h DataStructures/HashTable.h Models/PropertyType.h Models/Purpose.h CSV/csv.h DataStructures/HashTableAVL.h DataStructures/AVLOwner.h printFunction.h)




#cmake_minimum_required(VERSION 3.14)
#project(HelloSFML)
#
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#
#set(SOURCE_FILES main.cpp)
#add_executable(HelloSFML ${SOURCE_FILES})
#include_directories(/usr/local/include)
#
#find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
#include_directories(${SFML_INCLUDE_DIRS})
#target_link_libraries(HelloSFML sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
