//
// Created by Muhammad Sunaam on 03/01/2023.
//

#ifndef PROJECT_NEW_MAINMENU_H
#define PROJECT_NEW_MAINMENU_H
#include<iostream>
#include"Functions/Functions.h"
using namespace std;

string pathToCSV = "/Users/muhammadsunaam/Library/CloudStorage/OneDrive-NationalUniversityofSciences&Technology/Semester 3/DSA/CSV-Parser-Analytics/CSV/Property.csv";

AVLOwnerSortAgency *agenciesTree;
AVLOwner *ownerTree;
HashTableAVL *propertyTable;

class Menu{
public:
    Menu(){

        int choice;
        do{
            cout << "Welcome to the Property Management System" << endl;
            cout << "1. Load Data" << endl;
            cout << "2. Exit" << endl;
            cin.clear();
            cin >> choice;
            if(choice == 1){
                storeInStructures(pathToCSV, 200000, agenciesTree, ownerTree, propertyTable);
                cout << "Data Loaded Successfully" << endl;
            }
            else if(choice == 2){
                cout << "Thank you for using the Property Management System" << endl;
                return;
            }
            else{
                cout << "Invalid input, please try again" << endl;
                cin.clear();
                cin >> choice;
            }
        } while(choice != 1 && choice != 2);

        do{
            cout << "1. Search for a property" << endl;
            cout << "2. Search for an agent" << endl;
            cout << "3. Search for an agency" << endl;
            cout << "4. Exit" << endl;
            cin >> choice;
            if(choice == 1){
                int searchId;
                cout << "Enter the search term" << endl;
                cin.clear();
                cin >> searchId;
                searchPropertyByID(searchId, propertyTable);
            }
            else if(choice == 2){
                string searchName;
                cout << "Enter the Agent Name" << endl;
                cin.clear();
                getline(cin, searchName);
                searchForAgent(ownerTree, searchName);
            }
            else if(choice == 3){
                string searchName;
                cout << "Enter the Agency Name" << endl;
                cin.clear();
                getline(cin, searchName);
                searchForAgency(agenciesTree, searchName);
            }
            else if(choice == 4){
                cout << "Thank you for using the Property Management System" << endl;
                return;
            }
            else{
                cout << "Invalid input, please try again" << endl;
                cin >> choice;
            }
        } while(choice != 1 && choice != 2 && choice != 3 && choice != 4);


    }
};

#endif //PROJECT_NEW_MAINMENU_H
