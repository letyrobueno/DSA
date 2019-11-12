/* Examples and main operations with a static list
    To compile it in Linux (terminal): g++ -o program static_list.cpp
    To run it in Linux (terminal): ./program
*/

#include<iostream>
#include <string.h>
using namespace std;

typedef struct {
    char name[30];
    int age;
    int id;
    float grade; 
    } studentType;

void insert(studentType student, studentType students[], int *cont);
void printList(studentType students[], int cont);
int RecursiveSeqSearch(int n, studentType v[], int x);
void remove(studentType students[], int *cont, int key);
void countKeys(studentType students[], int n);

main (){
    studentType students[10];
    studentType student;
    int cont=0;

    // Insertion
    cout << endl << "Inserting id: 1234" << endl;
    strcpy(student.name, "Test");
    student.age = 23;
    student.id = 1234;
    student.grade = 8.5;
    insert(student, students, &cont);

    // Insertion
    cout << "Inserting id: 2345" << endl;
    strcpy(student.name, "Test2");
    student.age = 25;
    student.id = 2345;
    student.grade = 6.5;
    insert(student, students, &cont);

    // Insertion
    cout << "Inserting id: 5678" << endl;
    strcpy(student.name, "Test3");
    student.age = 27;
    student.id = 5678;
    student.grade = 4.5;
    insert(student, students, &cont);

    // Insertion
    cout << "Inserting id: 2345" << endl;
    strcpy(student.name, "Test2");
    student.age = 25;
    student.id = 2345;
    student.grade = 6.5;
    insert(student, students, &cont);

    // Insertion
    cout << "Inserting id: 1234" << endl;
    strcpy(student.name, "Test3");
    student.age = 27;
    student.id = 1234;
    student.grade = 4.5;
    insert(student, students, &cont);

    // Insertion
    cout << "Inserting id: 1234" << endl;
    strcpy(student.name, "Test3");
    student.age = 27;
    student.id = 1234;
    student.grade = 4.5;
    insert(student, students, &cont);

    // Insertion
    cout << "Inserting id: 4567" << endl;
    strcpy(student.name, "Teste4");
    student.age = 27;
    student.id = 4567;
    student.grade = 4.5;
    insert(student, students, &cont);

    // Insertion
    cout << "Inserting id: 1111" << endl;
    strcpy(student.name, "Teste5");
    student.age = 27;
    student.id = 1111;
    student.grade = 4.5;
    insert(student, students, &cont);

    // print the list
    printList(students, cont);
    countKeys(students, cont);

    // test the search
    cout << endl << "Searching id: 2345" << endl;
    int result;
    result = RecursiveSeqSearch(cont, students, 2345);
    cout << "Position: " << result << endl;

    // removal
    cout << endl << "Removing id: 2345" << endl;
    remove(students, &cont, 2345);

    // print the list
    printList(students,cont);
    cout << endl;
}

// insert new student
void insert(studentType student, studentType students[], int *cont){
    students[*cont] = student;
    *cont = *cont+1;
}

// Print all students in the list
void printList(studentType students[], int cont){
    cout << endl << "PRINTING THE LIST:" << endl;
    for(int i=0; i<cont; i++){
        cout << i << ". Name " << students[i].name << " Age: " << students[i].age << " id: " << students[i].id << " Grade: " << students[i].grade  << endl;
    }
}

// Recursive search
int RecursiveSeqSearch(int cont, studentType students[], int key) {
    if (cont==0) {
        return -1;
    } else if (key==students[cont-1].id) {
        return cont-1;
    } else {
        return RecursiveSeqSearch(cont-1, students, key);
    }
}

// Remove a student from the list
void remove(studentType students[], int *cont, int key){
    int result;
    result = RecursiveSeqSearch(*cont, students, key);
    if (result != -1) {
        *cont = *cont-1;
        students[result] = students[*cont];
    }
}

// Count the number of occurrences of a key
void countKeys(studentType students[], int n){
    int amount[n];
    int keys[n];
    int m = 0;
    for(int i=0; i<n; i++){ // checks each key
        bool found = false; // to indicate if the key is already in the array of keys
        for(int j=0; j<m; j++){
            if (keys[j]==students[i].id) {
                amount[j] = amount[j]+1;
                found = true;
            }
        }
        if (!found){ // if it's not in the array of keys, insert and set amount to 1
            keys[m] = students[i].id;
            amount[m] = 1;
            m++;
        }
    }
    // calculating the smaller number of occurrences of keys
    int smallest = n;
    for(int j=0; j<m; j++){
        if (amount[j]<smallest) smallest = amount[j];
    }
    // printing keys with smallest number of occurrences
    for(int j=0; j<m; j++){
        if (amount[j]==smallest) cout << "Key: " << keys[j] << " - Amount: " << amount[j] << endl;
    }
}
