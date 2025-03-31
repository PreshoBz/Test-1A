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

int BinaryTree::findHeight(){
    if(!root) return -1;
    queue<Node*> q;
    q.push(root);
    int height = -1;

    while(!q.empty()){
        int levelSize = q.size();
        for(int i = 0; i < levelSize; i++){
            Node* current = q.front();
            q.pop();
            if (current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
        height++;
    }
    return height;
}

void BinaryTree::levelOrder(){
    int height = findHeight();
    for(int i = 0; i<= height; i++){
        printLevel(root, i);
    }
    cout << endl;
}

void BinaryTree::printLevel(Node* node, int level){
    if(!node)return;
    if(level == 0){
        cout << node->data << " ";
      } else {
        printLevel(node->left, level - 1);
        printLevel(node->right, level - 1);
      }
}

int BinaryTree::countNodes(){
    if(!root) return 0;
    int count = 0;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        count++;
        if(current->left)q.push(current->left);
        if(current->right)q.push(current->right);
    }
    return count;
}

bool BinaryTree::search(int value){
    Node* current = root;
    while(current){
        if(current->data == value) return true;
        current = (value < current->data) ? current->left: current->right;
    }
    return false;
}