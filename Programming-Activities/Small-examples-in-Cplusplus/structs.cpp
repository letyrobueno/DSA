/* Example with structs
    To compile it in Linux (terminal): g++ -o program structs.cpp
    To run it in Linux (terminal): ./program
*/

#include <iostream>
#include <string.h>
using namespace std;

// construction of a struct
struct student_type {
    char name[50];
    int age;
    int id;
    float grade;
};

main(){
    struct student_type students[20]; // declaring a variable using the constructed type
    int n = 0;
    cout << "Enter with the number of students to be added: ";
    cin >> n;

    // reading the data from the user
    int i=0;
    while (i<n){
        cin.ignore();
        cout << "Enter with the name: ";
        cin.getline(students[i].name, 50);
        cout << "Enter with the age: ";
        cin >> students[i].age;
        cout << "Enter with the id: ";
        cin >> students[i].id;
        cout << "Enter with the grade: ";
        cin >> students[i].grade;
        i++;
    }

    // printing the data
    i = 0;
    while (i<n){
        cout << "Name: " << students[i].name << ", Age: " << students[i].age << ", id: " << students[i].id << ", Grade: " << students[i].grade  << endl;
        i++;
    }
}
