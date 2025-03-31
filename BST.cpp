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
    Node* current = root;
    Node* parent = nullptr;
    while(current){
        parent = current;
        if(value < current->data){
            current = current->left;
        } else if (value > current->data){
            current = current->right;
        } else {
           delete newNode;
           return; 
        }
        }
        if(value < parent->data){
            parent->left = newNode;
        } else {
           parent->right = newNode;
        }
    }
    
