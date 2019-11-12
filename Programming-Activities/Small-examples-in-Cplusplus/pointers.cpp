/* Examples with pointers
   To compile it in Linux (terminal): g++ -o program pointers.cpp
   To run it in Linux (terminal): ./program
*/

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

void mystery(int *p, int *q);

main(){
    // Ex.1: What do the lines below do? Answer: c=a+b
    int a = 5, b = 12;
    int *p;        /* p is a pointer to an integer */
    int *q; 
    p = &a;        /* the value of p is the address of a */
    q = &b;        /* q points to b */
    int c = *p + *q;

    // Ex.2: What do the lines below do? Answer: c=a+b
    //int *p;  
    int **r;       /* r is a pointer to a pointer to an integer */
    p = &a;        /* p points to a */
    r = &p;        /* r points to p and *r points to a */
    c = **r + b;

    // Ex.3: What's the problem of the function mystery()? Answer: temp is not an integer, but rather a pointer to an integer
    int i = 6, j = 10;
    mystery(&i, &j);

    // Ex.4: What do the lines below do? Answer: y = x + 100;
    int x = 99, y;
    int *z;
    z = &x;
    y = *z + 100;
}

// Ex.3: What's the problem of the function mystery()? Answer: temp is not an integer, but rather a pointer to an integer
void mystery(int *p, int *q){
    int *temp;
    *temp = *p;
    *p = *q;
    *q = *temp;
    cout << " temp: " << *temp << " p: " << *p << " q: " << *q << endl;
}
