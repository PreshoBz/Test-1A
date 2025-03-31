#include "BST.h"
#include<iostream>
#include<queue>

using namespace std;

BinaryTree::BinaryTree() : root(nullptr){}

BinaryTree::~BinaryTree(){
    deleteTree(root);
}

void BinaryTree::deleteTree(Node* node){
    if(node != nullptr){
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;

    }
}

void BinaryTree::insert(int value){
    Node* newNode = new Node(value);
    if(!root){
        root = newNode;
        return;
    }
}