//
// Created by Muhammad Sunaam on 01/01/2023.
//

#ifndef PROJECT_NEW_AVLAGENCY_H
#define PROJECT_NEW_AVLAGENCY_H

#include "../Models/Owner.h"

#include<iostream>
using namespace std;


struct NodeAgency{
    Owner* obj;
    NodeAgency* left, *right;
    int height;
    NodeAgency(){
        left = right = nullptr;
        height = 1;
    }
};

class AVLAgency{
private:
    NodeAgency* root, *loc, *ploc;
public:
    AVLAgency();
    bool isEmpty();
    NodeAgency* insertNodeAgency(Owner *value, NodeAgency* temp);
    void searchNodeAgency(Owner *value);
    int getBalanceFactor(NodeAgency* temp);
    int getHeight(NodeAgency* temp);
    NodeAgency* rightRotate(NodeAgency* tempRoot);
    NodeAgency* leftRotate(NodeAgency* tempRoot);
    void deleteNodeAgency(Owner *value);
    void printPreOrder( NodeAgency* temp);
    NodeAgency* getRoot();
    void setRoot(NodeAgency* temp);
    int updateHeight(NodeAgency* temp);
    Owner* getAgency(string agency);
    Owner* getAgent(string agent);
    void searchAgency(string agency);
    void searchAgent(string agent);
};


AVLAgency::AVLAgency() {
    root = loc = ploc = nullptr;
}


bool AVLAgency::isEmpty() {
    return root == nullptr;
}


NodeAgency* AVLAgency::insertNodeAgency( Owner* value, NodeAgency* temp ) {
    if(temp == nullptr){
        auto* newNodeAgency = new NodeAgency;
        newNodeAgency->obj = value;
        return newNodeAgency;
    }
    else if( temp->obj->getAgencyName() == value->getAgencyName()){
        //NodeAgency with that value already exists, avoid duplication.
        //But Insert the values of properties
        temp->obj->insertProperty(value->getFirstPropertyInserted());
        return temp;
    }
    else if( temp->obj->getAgencyName() > value->getAgencyName()){
        //go left
        temp->left = insertNodeAgency(value, temp->left);
    }else{
        temp->right = insertNodeAgency(value, temp->right);
    }

    //change the heights
    temp->height = 1 + max(( getHeight(temp->left)), getHeight(temp->right));

    //balance the tree with rotations
    int balanceFactor = getBalanceFactor(temp);
    if(balanceFactor < -1){
        //right side heavier
        if(value->getAgencyName() < temp->right->obj->getAgencyName() ){
            //right left rotation
            temp->right = rightRotate(temp->right);
            return leftRotate(temp);
        }else{
            return leftRotate(temp);
        }
    }else if(balanceFactor > 1){
        //left side heavier
        if(value->getAgencyName() > temp->left->obj->getAgencyName()){
            //left right rotation
            temp->left = leftRotate(temp->left);
            return rightRotate(temp);
        }else{
            return rightRotate(temp);
        }
    }
    return temp;
}


void AVLAgency::searchNodeAgency( Owner* owner ) {
    loc = ploc = nullptr;
    if(!isEmpty()){
        loc = root;
        while( loc->obj->getAgencyName() != owner->getAgencyName() and loc != nullptr){
            ploc = loc;
            if(owner->getAgencyName() < loc->obj->getAgencyName()){
                loc = loc->left;
            }else{
                loc = loc->right;
            }
        }
    }
}


int AVLAgency::getBalanceFactor( NodeAgency *temp ) {
    if(temp == nullptr) return 0;
    return ( getHeight(temp->left) - getHeight(temp->right) );
}


int AVLAgency::getHeight( NodeAgency *temp ) {
    if(temp == nullptr) return 0;
    return temp->height;
}


NodeAgency *AVLAgency::rightRotate( NodeAgency *tempRoot ) {
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


NodeAgency *AVLAgency::leftRotate( NodeAgency *tempRoot ) {
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


void AVLAgency::deleteNodeAgency( Owner* value ) {
    if(!isEmpty()){
        //tree exists
        searchNodeAgency(value);
        NodeAgency* loc1, *ploc1;
        loc1 = loc; ploc1 = ploc;

        //case 1: NodeAgency has two children
        if(loc->right!=nullptr and loc->left!=nullptr){
            //find rightmost child in the left subtree for replacement
            ploc = loc;
            loc = loc->left;
            while(loc->right!=nullptr){
                ploc = loc;
                loc=loc->right;
            }
        }

        //case 2: NodeAgency has right subtree only
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

            //case 3: NodeAgency has left subtree only
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

            //case 4: NodeAgency is a leaf
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

        if( loc->obj->getAgencyName() == value->getAgencyName()){
            delete loc;
        }else{
            //replacement NodeAgency is loc
            //NodeAgency to be deleted is loc1
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


void AVLAgency::printPreOrder( NodeAgency *temp ) {
    if(temp != nullptr){
        temp->obj->printForOwner();
        cout << "___________________________________" << endl;
        printPreOrder(temp->left);
        printPreOrder(temp->right);
    }
}


NodeAgency *AVLAgency::getRoot() {
    return root;
}


void AVLAgency::setRoot( NodeAgency *temp ) {
    root = temp;
}


int AVLAgency::updateHeight( NodeAgency *temp ) {
    if(temp){
        return(1+(max(getHeight(temp->left), getHeight(temp->right))));
    }
    return 0;
}

Owner* AVLAgency::getAgency( string agency ) {
    searchAgency(agency);
    if(loc != nullptr){
        return loc->obj;
    }
    return nullptr;
}

void AVLAgency::searchAgency( string agency ) {

//    loc = ploc = nullptr;
//    if(!isEmpty()){
//        loc = root;
//        while( loc->obj->getAgencyName() != agent and loc != nullptr){
//            ploc = loc;
//            if(agent < loc->obj->getAgencyName()){
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

void AVLAgency::searchAgent( string agent ) {
    loc = ploc = nullptr;
    if(!isEmpty()){
        loc = root;
        while( loc->obj->getAgencyName() != agent and loc != nullptr){
            ploc = loc;
            if(agent < loc->obj->getAgencyName()){
                loc = loc->left;
            }else{
                loc = loc->right;
            }
        }
    }
}

Owner *AVLAgency::getAgent( string agent ) {
    searchAgent(agent);
    if(loc->obj->getAgencyName() == agent){
        return loc->obj;
    }
    return nullptr;
}

#endif //PROJECT_NEW_AVLAGENCY_H
