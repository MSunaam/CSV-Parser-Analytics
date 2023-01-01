#include <iostream>
#include <vector>
#include <istream>
#include <fstream>
#include "CSV/csv.h"
#include "DataStructures/HashTableAVL.h"
//#include "Models/Property.h"
#include "Models/Location.h"
//#include "Models/Owner.h"
//#include "DataStructures/AVLOwner.h"
#include "printFunction.h"
#include "Functions/Functions.h"
using namespace std;

string pathToCSV = "/Users/muhammadsunaam/Library/CloudStorage/OneDrive-NationalUniversityofSciences&Technology/Semester 3/DSA/CSV-Parser-Analytics/CSV/Property.csv";

AVLOwnerSortAgency *agenciesTree;
AVLOwner *ownerTree;
HashTableAVL *propertyTable;

void storeInStructures(string path, int size, int choiceOfSort){

    propertyTable = new HashTableAVL(200000);


    ownerTree = new AVLOwner();


    agenciesTree = new AVLOwnerSortAgency();

    std::ifstream in(pathToCSV);
    if (in.fail()){
        (cout << "File not found" << endl);
        return;
    }
    int counter = 0;


    int property_id, baths, bedrooms, location_id;
    long int price;
    string page_url, location, city, province, area, date, agency, agent;
    double latitude, longitude;
    enum propertyType type;
    enum purpose purpose;


    while(in.good() and counter <= 200000)
    {
        std::vector<std::string> row = csv_read_row(in, ',');
        if(counter != 0){
            //read the row and parse into PropertyObject
            for(int i = 0, leng = row.size(); i < leng; i++){
                switch ( i ) {
                    case 0:
                        !row[i].empty() ? property_id = stoi(row[i]) : property_id = 0;
                        break;
                    case 1:
                        !row[i].empty() ? location_id = stoi(row[i]) : location_id = 0;
                        break;
                    case 2:
                        page_url = row[i];
                        break;
                    case 3:
                        type = typeMap[row[i]];
                        break;
                    case 4:
                        !row[i].empty() ? price = stoi(row[i]) : price = 0;
                        break;
                    case 5:
                        location = row[i];
                        break;
                    case 6:
                        city = row[i];
                        break;
                    case 7:
                        province = row[i];
                        break;
                    case 8:
                        !row[i].empty() ? latitude = stod(row[i]) : latitude = 0;
                        break;
                    case 9:
                        !row[i].empty() ? longitude = stod(row[i]) : longitude = 0;
                        break;
                    case 10:
                        !row[i].empty() ? baths = stoi(row[i]) : baths = 0;
                        break;
                    case 11:
                        area = row[i];
                    case 12:
                        purpose = purposeMap[row[i]];
                        break;
                    case 13:
                        !row[i].empty() ? bedrooms = stoi(row[i]) : bedrooms = 0;
                        break;
                    case 14:
                        date = row[i];
                        break;
                    case 15:
                        agency = row[i];
                        break;
                    case 16:
                        agent = row[i];
                        break;
                    default:
                        break;
                }
            }
            Location *loc = new Location(location_id, location, latitude, longitude, province, city);
            Owner* owner = new Owner(agency, agent);
            Property *prop = new Property(property_id, baths, bedrooms, page_url, date, price, type, purpose, loc, owner);

            //Insert property into owner
            owner->insertProperty(prop);


            if(choiceOfSort == 2){
                //Insert Owner Into Owner Tree according to agent
                ownerTree->setRoot(ownerTree->insertNode(owner, ownerTree->getRoot()));
            }else if(choiceOfSort == 1){
                //Insert Owner Into Owner Tree sorted by Agencies
                agenciesTree->setRoot(agenciesTree->insertNode(owner, agenciesTree->getRoot()));
            }

            //Insert property into hash table
            propertyTable->insertIntoTable(prop);
        }
        counter++;
    }
    in.close();
}

int main(){

    //give menu to user
    int choice = -1;
    bool sortedByAgent = false;

    cout << "---------Welcome---------" << endl;
    do{
        cout << "Enter 0 to Exit" << endl;
        cout << "Enter 1 to load CSV file" << endl;
        cin.clear(); cin.ignore(255, '\n'); cin >> choice;
    }while(choice < 0 || choice > 1);

    if(choice == 0) return 0;
    else{

        choice  = -1;

        do{
            cout << "Press 1 to sort the owner information according to the agency" <<endl;
            cout << "Press 2 to sort the owner information according to the agent" <<endl;
            cin.clear(); cin.ignore(255, '\n'); cin >> choice;
        }while(choice < 1 || choice > 2);
        if(choice == 1){
            storeInStructures(pathToCSV, 200000, 1);
        }else{
            storeInStructures(pathToCSV, 200000, 2);
            sortedByAgent = true;
        }
        cout << "Data Stored!" << endl;
    }
    choice = -1;

    while(choice != 0){

        do{
            if(sortedByAgent){
                //data sorted by agent
                cout << "Press 1 to search an agent" << endl;
            }else{
                //data sorted by agency
                cout << "Press 1 to search an agency" << endl;
            }
            cout << "Press 2 to print all properties" << endl;
            cin.clear(); cin.ignore(255, '\n'); cin >> choice;

            string name;
            switch ( choice ) {
                case 1:
                    if(sortedByAgent){
                        cout << "Enter Agent Name: " << endl;
                        cin.clear(); cin.ignore(256, '\n');
                        getline(cin, name);
                        searchForAgent(ownerTree,name);
                    }else{
                        cout << "Enter Agency Name: " << endl;
                        cin.clear(); cin.ignore(256, '\n');
                        getline(cin, name);
                        searchForAgency(agenciesTree, name);
                    }
                    break;
                case 2:
                    propertyTable->print(200000);
                    break;
                default:
                    break;
            }

        }while((choice < 1 || choice > 2) and choice != 0);



    }
    cout << "---------Bye-Bye---------" << endl;


}












