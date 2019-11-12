/* Examples with sending parameters by reference
    To compile it in Linux (terminal): g++ -o program param_by_ref.cpp
    To run it in Linux (terminal): ./program
*/

#include<iostream>
#include<string.h>
using namespace std;

void test(float *a, float *b, int *c, int V[], char word[]);

main(){
    // declaring and initializing variables
    float a = 10.5, b = 17.1; 
    int c = 0;
    int V[10];
    char word[100];
    strcpy(word, "BEFORE:");
    for(int i=0; i<10; i++) V[i] = i;

    cout << endl << word << endl << "a = " << a << "; b = " << b << "; c = " << c << endl;
    for(int i=0; i<10; i++) cout << "V[i] = " << V[i] << endl;
    cout << "##########################" << endl << endl;

    test(&a, &b, &c, V, word); 

    cout << word << endl << "a = " << a << "; b = " << b << "; c = " << c << endl;
    for(int i=0; i<10; i++) cout << "V[i]=" << V[i] << endl;
}

void test(float *a, float *b, int *c, int V[], char word[]) { // OR EQUIVALENTLY:
//void test(float *a, float *b, int *c, int *V, char *word) {  
    float *p, *q;   // two pointers of the type float
    float temp;     // float variable

    temp = *a;      // temp receives the value inside the address pointed by a
    *a = *b;        // value in a is replaced by the value in b
    *b = temp;      // b receives the value in temp
    *c = 12;        // value in c is replaced by 12
    p = a;          // p points to the same address that a does
    q = b;          // q points to the same address that b does

    cout << "Checking pointers inside the function: " << endl;
    cout << "Value in p = " << *p << "; value in q = " << *q << endl;
    cout << "a = " << a << " b = " << b << endl << endl;
    cout << "##########################" << endl;

    for(int i=0; i<10; i++) V[i] = V[i]+10;   
    strcpy(word, "AFTER:");
}
