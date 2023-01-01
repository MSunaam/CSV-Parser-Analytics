//
// Created by Muhammad Sunaam on 31/12/2022.
//

#ifndef PROJECT_NEW_HASHTABLEAVL_H
#define PROJECT_NEW_HASHTABLEAVL_H

#include <iostream>
#include "AVLProperty.h"
#include "../Models/Property.h"
using namespace std;

class HashTableAVL{
private:
    int tableSize;
public:
    AVLProperty* table;
    HashTableAVL();
    HashTableAVL(int size);
    void insertIntoTable(Property* property);
    int getIndex(int id);
    Property* getValueByID(int id);
    Property* getArray();
    void print(int i);
};

HashTableAVL::HashTableAVL() {
    tableSize = 2000;
    table = new AVLProperty[tableSize];
}

HashTableAVL::HashTableAVL( int size ) {
    this->tableSize = size;
    table = new AVLProperty[tableSize];
}

void HashTableAVL::insertIntoTable( Property* property ) {
    //get property id
    int index = getIndex(property->getPropertyId());
    table[index].setRoot(table[index].insertNode(property,table[index].getRoot()));
}

int HashTableAVL::getIndex( int id ) {
    return (id % tableSize);
}

Property* HashTableAVL::getValueByID( int id ) {
    int index = getIndex(id);
    Property* aProperty = table[index].getProperty(id);
    return aProperty;
}

void HashTableAVL::print( int i ) {
    for(int j = 0; j < i; j++){
        table[j].printPreOrder(table[j].getRoot());
    }
}


#endif //PROJECT_NEW_HASHTABLEAVL_H
