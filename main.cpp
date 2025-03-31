#include "BST.h"
#include<iostream>
using namespace std;

int main() {
    BinaryTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder Traversal: ";
    tree.inOrder();

    cout << "Preorder Travesal: ";
    tree.preOrder();

    cout << "Postorder Traversal: ";
    tree.postOrder();

    cout << "Height of the tree: " << tree.findHeight() << endl;

    cout << "Levelorder Travesal: ";
    tree.levelOrder();

    cout << "Number of noded: " << tree.countNodes() << endl; 

    if(tree.search(40)){
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }

    if(tree.search(90)){
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }

    


    

    return 0;
}

