/*  To compile in Linux from terminal: g++ -o bst bst.cpp
    To run in a Linux terminal: ./bst
*/
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

typedef struct Node *Pointer;

typedef struct Node {
    int key;
    Pointer right,left;
    } NodeTree;

NodeTree* insert(int key, Pointer p);
void listParentAndChildren(Pointer p);
// NodeTree* search(int key, Pointer p);
// void inOrder(Pointer p);
// void preOrder(Pointer p);
// void postOrder(Pointer p);
// int calculateHeight(Pointer p);

int main(){
    Pointer root = NULL;
    root = insert(23, root);
    cout << "\n RESULTING TREE: \n \n";
    listParentAndChildren(root);

    return(0);
}

// it inserts a node into the BST recursively
NodeTree* insert(int key, Pointer p) {
    if (p == NULL) {
        cout << "INSERTING: " << key << "\n";
        p = (Pointer) malloc(sizeof(NodeTree));
        p->key = key;
        p->left = NULL;
        p->right = NULL;
    } else if (key < p->key) {
        p->left = insert(key, p->left);
    } else if (key > p->key) {
        p->right = insert(key, p->right);
    } else cout << "Error! The key already exists!";

    return p;
}

// it searches a key inside the BST recursively
NodeTree* search(int key, Pointer p) {
    if (p == NULL) {
        return NULL;
    } else if (key < p->key) {
        return search(key, p->left);
    } else if (key > p->key) {
        return search(key, p->right);
    } else return p;
}

// it prints the whole tree recursively
void listParentAndChildren(Pointer p) {
    if (p != NULL) {
        int left = -1, right = -1;
        if (p->left != NULL) {
            left = p->left->key;
        }
        if (p->right != NULL) {
            right = p->right->key;
        }
        cout << "Parent: " << p->key << ", left node: " << left << ", right node: " << right << "\n";
        listParentAndChildren(p->left); // it calls the method to print the left subtree
        listParentAndChildren(p->right); // it calls the method to print the right subtree
    }
}

// it lists all keys in the BST using in-order traversal
void inOrder(Pointer p) {

}

// it lists all keys in the BST using pre-order traversal
void preOrder(Pointer p) {

}

// it lists all keys in the BST using post-order traversal
void postOrder(Pointer p) {

}
    
// it calculates the height of the BST recursively
int calculateHeight(Pointer p){ 
    if (p==NULL){
        return 0;
    } else {
        int left = calculateHeight(p->left);
        int right = calculateHeight(p->right);
        if (left>right) return left+1;
        else return right+1;
    }
}
