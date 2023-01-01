//
// Created by Muhammad Sunaam on 01/01/2023.
//

#ifndef PROJECT_NEW_AVLAGENT_H
#define PROJECT_NEW_AVLAGENT_H

//
// Created by Muhammad Sunaam on 25/12/2022.
//

#include "../Models/Owner.h"

#include<iostream>
using namespace std;


struct Node{
    Owner* obj;
    Node* left, *right;
    int height;
    Node(){
        left = right = nullptr;
        height = 1;
    }
};

class AVLAgent{
private:
    Node* root, *loc, *ploc;
public:
    AVLAgent();
    bool isEmpty();
    Node* insertNode(Owner *value, Node* temp);
    void searchNode(Owner *value);
    int getBalanceFactor(Node* temp);
    int getHeight(Node* temp);
    Node* rightRotate(Node* tempRoot);
    Node* leftRotate(Node* tempRoot);
    void deleteNode(Owner *value);
    void printPreOrder( Node* temp);
    Node* getRoot();
    void setRoot(Node* temp);
    int updateHeight(Node* temp);
    Owner* getAgency(string agency);
    Owner* getAgent(string agent);
    void searchAgency(string agency);
    void searchAgent(string agent);
};


AVLAgent::AVLAgent() {
    root = loc = ploc = nullptr;
}


bool AVLAgent::isEmpty() {
    return root == nullptr;
}


Node* AVLAgent::insertNode( Owner* value, Node* temp ) {
    if(temp == nullptr){
        auto* newNode = new Node;
        newNode->obj = value;
        return newNode;
    }
    else if( temp->obj->getAgentName() == value->getAgentName()){
        //Node with that value already exists, avoid duplication.
        //But Insert the values of properties
        temp->obj->insertProperty(value->getFirstPropertyInserted());
        return temp;
    }
    else if( temp->obj->getAgentName() > value->getAgentName()){
        //go left
        temp->left = insertNode(value, temp->left);
    }else{
        temp->right = insertNode(value, temp->right);
    }

    //change the heights
    temp->height = 1 + max(( getHeight(temp->left)), getHeight(temp->right));

    //balance the tree with rotations
    int balanceFactor = getBalanceFactor(temp);
    if(balanceFactor < -1){
        //right side heavier
        if(value->getAgentName() < temp->right->obj->getAgentName() ){
            //right left rotation
            temp->right = rightRotate(temp->right);
            return leftRotate(temp);
        }else{
            return leftRotate(temp);
        }
    }else if(balanceFactor > 1){
        //left side heavier
        if(value->getAgentName() > temp->left->obj->getAgentName()){
            //left right rotation
            temp->left = leftRotate(temp->left);
            return rightRotate(temp);
        }else{
            return rightRotate(temp);
        }
    }
    return temp;
}


void AVLAgent::searchNode( Owner* owner ) {
    loc = ploc = nullptr;
    if(!isEmpty()){
        loc = root;
        while( loc->obj->getAgentName() != owner->getAgentName() and loc != nullptr){
            ploc = loc;
            if(owner->getAgentName() < loc->obj->getAgentName()){
                loc = loc->left;
            }else{
                loc = loc->right;
            }
        }
    }
}


int AVLAgent::getBalanceFactor( Node *temp ) {
    if(temp == nullptr) return 0;
    return ( getHeight(temp->left) - getHeight(temp->right) );
}


int AVLAgent::getHeight( Node *temp ) {
    if(temp == nullptr) return 0;
    return temp->height;
}


Node *AVLAgent::rightRotate( Node *tempRoot ) {
    auto* x = tempRoot;
    auto* y = x->left;
    auto* temp = y->right;
    y->right = x;
    x->left = temp;
    //update heights
    x->height = updateHeight(x);
    y->height = updateHeight(y);
    return y;
}


Node *AVLAgent::leftRotate( Node *tempRoot ) {
    auto* x = tempRoot;
    auto* y = x->right;
    auto* temp = y->left;
    y->left = x;
    x->right = temp;
    //update heights
    x->height = updateHeight(x);
    y->height = updateHeight(y);
    return y;
}


void AVLAgent::deleteNode( Owner* value ) {
    if(!isEmpty()){
        //tree exists
        searchNode(value);
        Node* loc1, *ploc1;
        loc1 = loc; ploc1 = ploc;

        //case 1: Node has two children
        if(loc->right!=nullptr and loc->left!=nullptr){
            //find rightmost child in the left subtree for replacement
            ploc = loc;
            loc = loc->left;
            while(loc->right!=nullptr){
                ploc = loc;
                loc=loc->right;
            }
        }

        //case 2: Node has right subtree only
        if(loc->left == nullptr and loc->right != nullptr){
            if(loc == root){
                root = root->right;
            }
            else if (ploc->left == loc){
                ploc->left = loc->right;
            }else{
                ploc->right = loc->right;
            }
            loc->right = nullptr;
        }

            //case 3: Node has left subtree only
        else if(loc->right == nullptr and loc->left != nullptr){
            if(loc == root){
                root = root->left;
            }
            else if (ploc->right == loc){
                ploc->right = loc->left;
            }else{
                ploc->left = loc->left;
            }
            loc->left = nullptr;
        }

            //case 4: Node is a leaf
        else if (loc->right == nullptr and loc->left == nullptr){
            if(loc == root){
                root = nullptr;
            }
            else if(ploc->left == loc){
                ploc->left = nullptr;
            }else {
                ploc->right = nullptr;
            }
        }

        if( loc->obj->getAgentName() == value->getAgentName()){
            delete loc;
        }else{
            //replacement node is loc
            //Node to be deleted is loc1
            loc->left = loc1->left;
            loc->right = loc1->right;
            if(ploc1->right == loc1){
                ploc1->right = loc;
            }else{
                ploc1->left = loc;
            }
            delete loc1;
        }
    }else{
        //empty tree
        return;
    }
}


void AVLAgent::printPreOrder( Node *temp ) {
    if(temp != nullptr){
        temp->obj->printxForOwner();
        cout << "___________________________________" << endl;
        printPreOrder(temp->left);
        printPreOrder(temp->right);
    }
}


Node *AVLAgent::getRoot() {
    return root;
}


void AVLAgent::setRoot( Node *temp ) {
    root = temp;
}


int AVLAgent::updateHeight( Node *temp ) {
    if(temp){
        return(1+(max(getHeight(temp->left), getHeight(temp->right))));
    }
    return 0;
}

Owner* AVLAgent::getAgency( string agency ) {
    searchAgency(agency);
    if(loc != nullptr){
        return loc->obj;
    }
    return nullptr;
}

void AVLAgent::searchAgency( string agency ) {

//    loc = ploc = nullptr;
//    if(!isEmpty()){
//        loc = root;
//        while( loc->obj->getAgentName() != agent and loc != nullptr){
//            ploc = loc;
//            if(agent < loc->obj->getAgentName()){
//                loc = loc->left;
//            }else{
//                loc = loc->right;
//            }
//        }
//    }


    loc = ploc = nullptr;
    if(!isEmpty()){
        loc = root;
        while( loc != NULL and loc->obj->getAgencyName() != agency){
            ploc = loc;
            if(agency < loc->obj->getAgencyName()){
                loc = loc->left;
            }else{
                loc = loc->right;
            }
        }
    }
}

void AVLAgent::searchAgent( string agent ) {
    loc = ploc = nullptr;
    if(!isEmpty()){
        loc = root;
        while( loc->obj->getAgentName() != agent and loc != nullptr){
            ploc = loc;
            if(agent < loc->obj->getAgentName()){
                loc = loc->left;
            }else{
                loc = loc->right;
            }
        }
    }
}

Owner *AVLAgent::getAgent( string agent ) {
    searchAgent(agent);
    if(loc->obj->getAgentName() == agent){
        return loc->obj;
    }
    return nullptr;
}


#endif //PROJECT_NEW_AVLAGENT_H
