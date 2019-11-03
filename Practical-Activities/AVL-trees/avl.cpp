/*  To compile and run in a Linux terminal: g++ -o avl avl.cpp ; ./avl
*/
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

typedef struct Node *Pointer;

typedef struct Node {
    int key;
    int bal; // hD(no)-hE(no)
    Pointer left,right;
    } NodeTree;

NodeTree* insert(int key, Pointer p); // TODO: modify by adding calls to the balancing methods
NodeTree* search(int key, Pointer p);
NodeTree* case1(Pointer p);
NodeTree* case2(Pointer p);
void listParentAndChildren(Pointer p);
void remove(int key, Pointer p); // TODO: implement with calls to the balancing methods

int main(){
    NodeTree *root = NULL;
    root = insert(23, root);
    root = insert(12, root);
    root = insert(70, root);
    cout << "\nRESULTING TREE: \n \n";
    listParentAndChildren(root);

    return(0);
}

// it inserts a node into the AVL tree recursively
NodeTree* insert(int key, Pointer p) {
    if (p == NULL) {
        cout << "INSERTING: " << key << "\n";
        p = new NodeTree;
        p->key = key;
        p->left = NULL;
        p->right = NULL;
    } else if (key < p->key) {
        p->left = insert(key, p->left);
    } else if (key > p->key) {
        p->right = insert(key, p->right);
    } else cout << "Error! Key already exists!";
    return p;
}

// it searches a key inside the AVL tree recursively
NodeTree* search(int key, Pointer p) {
    if (p == NULL) {
        return NULL;
    } else if (key < p->key) {
        return search(key, p->left);
    } else if (key > p->key) {
        return search(key, p->right);
    } else
    return p;
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
        listParentAndChildren(p->left); // it prints the left subtree
        listParentAndChildren(p->right); // it prints the right subtree
    }
}

// No comments here because it's up to you to understand this part of code
NodeTree* case1(Pointer p) {
    NodeTree *ptu = p->left;
    if (ptu->bal == -1) {
        p->left = ptu->right;
        ptu->right = p;
        p->bal = 0;
        p = ptu;
    } else {
        NodeTree *ptv = ptu->right;
        ptu->right = ptv->left;
        ptv->left = ptu;
        p->left = ptv->right;
        ptv->right = p;
        if (ptv->bal == -1) {
            p->bal = 1;
        } else {
            p->bal = 0;
        }
        if (ptv->bal == 1) {
            ptu->bal = -1;
        } else {
            ptu->bal = 0;
        }
        p = ptv;
    }
    p->bal = 0;
    return p;
}

// No comments here because it's up to you to understand this part of code
NodeTree* case2(Pointer p) {
    NodeTree *ptu = p->right;

    if (ptu->bal == 1) {
        p->right = ptu->left;
        ptu->left = p;
        p->bal = 0;
        p = ptu;
    } else {
        NodeTree *ptv = ptu->left;
        ptu->left = ptv->right;
        ptv->right = ptu;
        p->right = ptv->left;
        ptv->left = p;
        if (ptv->bal == 1) {
            p->bal = -1;
        } else {
            p->bal = 0;
        }
        if (ptv->bal == -1) {
            ptu->bal = 1;
        } else {
            ptu->bal = 0;
        }
        p = ptv;
    }
    p->bal = 0;
    return p;
}

// TODO: it removes a node from the AVL tree
void remove(int key, Pointer p) {
    
}
