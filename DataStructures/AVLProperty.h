//
// Created by Muhammad Sunaam on 25/12/2022.
//

#ifndef PROJECT_NEW_AVLPROPERTY_H
#define PROJECT_NEW_AVLPROPERTY_H

#include "../Models/Property.h"
#include "../Models/Owner.h"


#include<iostream>
using namespace std;


struct NodeAVL{
    Property* obj;
    Owner* owner;
    NodeAVL* left, *right;
    int height;
    NodeAVL(){
        obj = nullptr;
        owner = nullptr;
        left = right = nullptr;
        height = 1;
    }
};

class AVLProperty{
private:
    NodeAVL* root, *loc, *ploc;
public:
    AVLProperty();
    bool isEmpty();
    NodeAVL* insertNode(Property *value, NodeAVL* temp);
    void searchNode(Property *value);
    int getBalanceFactor(NodeAVL* temp);
    int getHeight(NodeAVL* temp);
    NodeAVL* rightRotate(NodeAVL* tempRoot);
    NodeAVL* leftRotate(NodeAVL* tempRoot);
    void deleteNode(Property *value);
    void printPreOrder( NodeAVL* temp);
    NodeAVL* getRoot();
    void setRoot(NodeAVL* temp);
    int updateHeight(NodeAVL* temp);
    Property* getProperty(int id);
    void searchNode(int id);
    Property* getRootObject();
};


AVLProperty::AVLProperty() {
    root = loc = ploc = nullptr;
}


bool AVLProperty::isEmpty() {
    return root == nullptr;
}


NodeAVL* AVLProperty::insertNode( Property* value, NodeAVL* temp ) {
    if(temp == nullptr){
        auto* newNode = new NodeAVL;
        newNode->obj = value;
        return newNode;
    }
    else if( temp->obj->getPropertyId() == value->getPropertyId()){
        //Node with that value already exists, avoid duplication.
        return temp;
    }
    else if( temp->obj->getPropertyId() > value->getPropertyId()){
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
        if(value->getPropertyId() < temp->right->obj->getPropertyId() ){
            //right left rotation
            temp->right = rightRotate(temp->right);
            return leftRotate(temp);
        }else{
            return leftRotate(temp);
        }
    }else if(balanceFactor > 1){
        //left side heavier
        if(value->getPropertyId() > temp->left->obj->getPropertyId()){
            //left right rotation
            temp->left = leftRotate(temp->left);
            return rightRotate(temp);
        }else{
            return rightRotate(temp);
        }
    }
    return temp;
}


void AVLProperty::searchNode( Property* value ) {
    loc = ploc = nullptr;
    if(!isEmpty()){
        loc = root;
        while( loc->obj->getPropertyId() != value->getPropertyId() and loc != nullptr){
            ploc = loc;
            if(value->getPropertyId() < loc->obj->getPropertyId()){
                loc = loc->left;
            }else{
                loc = loc->right;
            }
        }
    }
}


int AVLProperty::getBalanceFactor( NodeAVL *temp ) {
    if(temp == nullptr) return 0;
    return ( getHeight(temp->left) - getHeight(temp->right) );
}


int AVLProperty::getHeight( NodeAVL *temp ) {
    if(temp == nullptr) return 0;
    return temp->height;
}


NodeAVL *AVLProperty::rightRotate( NodeAVL *tempRoot ) {
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


NodeAVL *AVLProperty::leftRotate( NodeAVL *tempRoot ) {
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


void AVLProperty::deleteNode( Property* value ) {
    if(!isEmpty()){
        //tree exists
        searchNode(value);
        NodeAVL* loc1, *ploc1;
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

        if( loc->obj->getPropertyId() == value->getPropertyId()){
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


void AVLProperty::printPreOrder( NodeAVL *temp ) {
    if(temp != nullptr){
        temp->obj->print();
        cout << "___________________________________" << endl;
        printPreOrder(temp->left);
        printPreOrder(temp->right);
    }
}


NodeAVL *AVLProperty::getRoot() {
    return root;
}


void AVLProperty::setRoot( NodeAVL *temp ) {
    root = temp;
}


int AVLProperty::updateHeight( NodeAVL *temp ) {
    if(temp){
        return(1+(max(getHeight(temp->left), getHeight(temp->right))));
    }
    return 0;
}

Property* AVLProperty::getProperty( int id ) {
    searchNode(id);
    if(loc->obj->getPropertyId() == id){
        return loc->obj;
    }
    return nullptr;
}

void AVLProperty::searchNode( int id ) {
    loc = ploc = nullptr;
    if(!isEmpty()){
        loc = root;
        while( loc->obj->getPropertyId() != id and loc != nullptr){
            ploc = loc;
            if(id < loc->obj->getPropertyId()){
                loc = loc->left;
            }else{
                loc = loc->right;
            }
        }
    }
}

Property *AVLProperty::getRootObject() {
    if(root) return root->obj;
    return nullptr;
}


#endif //PROJECT_NEW_AVLPROPERTY_H
