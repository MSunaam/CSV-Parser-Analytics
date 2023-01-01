//
// Created by Muhammad Sunaam on 31/12/2022.
//

#ifndef PROJECT_NEW_HASHTABLE_H
#define PROJECT_NEW_HASHTABLE_H

#include<iostream>
#include "../Models/Property.h"
using namespace std;


class HashTable{
private:
    int sizeOfTable;
public:
    Property *array;
public:
    HashTable();
    HashTable(int size);
    int getHash(int propertyId, int collisionNumber);
    void insertNode(Property obj);
    Property getValueAtIndex(int index);
    Property* getArray();
    void print(int i);
};

HashTable::HashTable() {
    sizeOfTable = 20000;
    array = new Property[sizeOfTable];
}

HashTable::HashTable( int size ) {
    sizeOfTable = size;
    array = new Property[sizeOfTable];
}

int HashTable::getHash( int propertyId, int collisionNumber ) {
    return (propertyId % sizeOfTable);
//    + collisionNumber * (31 - propertyId % 31) % sizeOfTable;
}

void HashTable::insertNode( Property obj ) {
    int collision = 1;
    int index = getHash(obj.getPropertyId(), collision);
    while(!array[index].isEmpty()){
        cout << "Collision at index " << index << endl;
        getchar();
//        index = getHash(obj.getPropertyId(), collision++);
//        index = (index + 1) % sizeOfTable;
    }
    array[index] = obj;
}

Property HashTable::getValueAtIndex( int index ) {
    return array[index];
}

Property *HashTable::getArray() {
    return array;
}

void HashTable::print( int i ) {
    for(int j = 0; j < i; j++){
        array[j].print();
        cout << "---------------------------------" << endl;
    }
}

#endif //PROJECT_NEW_HASHTABLE_H
