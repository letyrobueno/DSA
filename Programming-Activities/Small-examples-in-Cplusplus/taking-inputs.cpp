/* Example of a reading and writing of data from/to the user
    To compile it in Linux (terminal): g++ -o program taking-inputs.cpp
    To run it in Linux (terminal): ./program
*/

#include <iostream>

using namespace std;
main(){ 
    int age;
    char name[100];
    cout << "Enter with the name: ";
    cin.getline(name,100);
    cout << "Enter with the age: ";
    cin >> age;
    cout << "Name: " << name << " Age: " << age << endl;
}
