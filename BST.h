#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

class BinaryTree{
    private:

    struct Node{
        int data;
        Node* left;
        Node* right;

        Node(int value) : data(value), left(nullptr), right(nullptr){}
    };

    Node* root;
    void deleteTree(Node* node);
    Node* deleteNode(Node* node, int value);
    void inOrder(Node* node);
    void preOrder(Node* node);
    void postOrder(Node* node);
    void printLevel(Node* node, int level);
    int countNodes(Node* node);
    int findHeight(Node*node);

    public:

    BinaryTree();
    ~BinaryTree();
    void insert(int value);
    bool search(int value);
    void deleteValue(int value);
    void inOrder();
    void preOrder();
    void postOrder();
    void levelOrder();
    int countNodes();
    int findHeight();

};

#endif

