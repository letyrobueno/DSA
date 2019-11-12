/* Examples and main operations with single linked lists
    To compile it in Linux (terminal): g++ -o program linked_list.cpp
    To run it in Linux (terminal): ./program
*/

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

typedef struct {
    char name[30];
    int age;
    int id;
    float grade; 
    } itemType;

typedef struct Node *Pointer;

typedef struct Node {
    itemType item;
    Pointer next;
    } NodeStudent;

typedef struct {
    Pointer First, Last;
    } ListType;

void createList(ListType *List);
void insertNode(itemType student, ListType *List);
void removeNode(int id, ListType *List);
void searchNodeWithoutReturn(int id, ListType *List);
NodeStudent* searchNodeWithReturn(int id, ListType *List);
void recursiveSearch(int id, Pointer p);
NodeStudent* recursiveSearchWithReturn(int id, Pointer p);
void printList(ListType *List);

main(){
    itemType student;
    ListType List;

    // create dynamic list
    createList(&List);

    // insertion
    cout << endl << "Inserting id: 1234" << endl;
    strcpy(student.name, "Test1");
    student.age = 23;
    student.id = 1234;
    student.grade = 8.5;
    insertNode(student, &List);

    // insertion
    cout << "Inserting id: 2345" << endl;
    strcpy(student.name, "Test2");
    student.age = 25;
    student.id = 2345;
    student.grade = 6.5;
    insertNode(student, &List);

    // insertion
    cout << "Inserting id: 2346" << endl;
    strcpy(student.name, "Test3");
    student.age = 25;
    student.id = 2346;
    student.grade = 6.5;
    insertNode(student, &List);

    // insertion
    cout << "Inserting id: 5678" << endl;
    strcpy(student.name, "Test4");
    student.age = 27;
    student.id = 5678;
    student.grade = 4.5;
    insertNode(student, &List);

    // print the list
    printList(&List);
    cout << endl;

    // test iterative search without return
    cout << endl << "Search without return - Searching id: 2345" << endl;
    searchNodeWithoutReturn(2345, &List);

    // test search with return
    cout << endl << "Search with return - Searching id: 2345" << endl;
    NodeStudent *p = searchNodeWithReturn(2345, &List);
    cout << "Found! Name: " << p->item.name << " Age: " << p->item.age << " id: " << p->item.id << " Grade: " << p->item.grade  << endl;

    // test recursive search without return
    cout << endl << "Recursive search without return - Searching id: 2345" << endl;
    recursiveSearch(2345, List.First->next);

    // test recursive search with return
    cout << endl << "Recursive search with return - Searching id: 2345" << endl;
    p = recursiveSearchWithReturn(2345, List.First->next);
    cout << "Found! Name: " << p->item.name << " Age: " << p->item.age << " id: " << p->item.id << " Grade: " << p->item.grade  << endl;

    // removal of an element
    cout << endl << "Removing id: 2345" << endl;
    removeNode(2345, &List);

    // print the list
    cout << endl << "Printing the list:" << endl;
    printList(&List);
    cout << endl << endl;
}

// Initialize single linked list using a head-node, i.e.,
// the first node of the list does not contain a valid element
void createList(ListType *List){
    List->First = (Pointer) malloc(sizeof(NodeStudent)); // allocate space for the head-node
    List->Last = List->First; // equivalent to (*List).Last = (*List).First;
    List->First->next = NULL; // it's mandatory to attribute NULL
}

// insert new node
void insertNode(itemType student, ListType *List){
    List->Last->next = (Pointer) malloc(sizeof(NodeStudent)); // allocate space for the head-node
    List->Last = List->Last->next;
    List->Last->item = student;
    List->Last->next = NULL;
}

// Print all nodes in the list iteratively
void printList(ListType *List){
    Pointer p;
    p = List->First->next;
    cout << endl << "Printing the List" << endl;
    while (p != NULL){
        cout << "Name: " << p->item.name << " Age: " << p->item.age << " id: " << p->item.id << " Grade: " << p->item.grade << "           ";
        p = p->next;
    }
}

// Remove a node from the list
void removeNode(int id, ListType *List){
    Pointer p, q;
    p = List->First->next;
    q = List->First->next;
    // First search the node to be removed
    while ((p!=NULL) && (p->item.id!=id)){
        q = p;
        p = p->next;
    }
    if (p!=NULL){
        q->next = p->next;
        free(p);
    } else { // if node is not found, it gives an error message
        cout << "Student not found!" << endl;
    }
}

// Recursive search without return
void recursiveSearch(int id, Pointer p){
    if (p != NULL){
        if (p->item.id != id){
            recursiveSearch(id, p->next);
        } else {
            cout << "Found! Name: " << p->item.name << " Age: " << p->item.age << " id: " << p->item.id << " Grade: " << p->item.grade  << endl;
        }
    } else {
        cout << "Not found!" << endl;
    }
}

// Recursive search with return
NodeStudent* recursiveSearchWithReturn(int id, Pointer p){
    if (p!=NULL){
        if (p->item.id != id){
            recursiveSearchWithReturn(id, p->next);
        } else {
            return p;
        }
    } else {
        return NULL;
    }
}

// Iterative search without return
void searchNodeWithoutReturn(int id, ListType *List){
    Pointer p;
    p = List->First->next;
    while ((p != NULL) && (p->item.id != id)){
        p = p->next;
    }
    if (p != NULL){
        cout << "Found! Name: " << p->item.name << " Age: " << p->item.age << " id: " << p->item.id << " Grade: " << p->item.grade  << endl;
    } else {
        cout << "Not found!" << endl;
    }
}

// Iterative search with return
NodeStudent* searchNodeWithReturn(int id, ListType *List){
    Pointer p;
    p = List->First->next;
    while ((p != NULL) && (p->item.id != id)){
        p = p->next;
    }
    if (p != NULL){
        return p;
    } else {
        return NULL;
    }
}
