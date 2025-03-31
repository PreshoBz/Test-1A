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
    
void BinaryTree::inOrder(Node* node){
    if(node){
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void BinaryTree::inOrder(){
    inOrder(root);
    cout << endl;
}

void BinaryTree::preOrder(Node* node){
    if(node){
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void BinaryTree::preOrder(){
    preOrder(root);
    cout << endl;
}

void BinaryTree::postOrder(Node* node){
    if(node){
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

void BinaryTree::postOrder(){
    postOrder(root);
    cout << endl;
}