/* Program to calculate the factorial of a number n, i.e., n!=n * (n-1) * ... * 2 * 1.
    To compile it in Linux (terminal): g++ -o factorial factorial.cpp
    To run it in Linux (terminal): ./factorial
*/

#include<iostream>
using namespace std;

int recFactorial(int n);
int iterFactorial(int n);

main(){
    int n, fat;
    cout << "Enter with a value for n: ";
    cin >> n;
    fat = recFactorial(n);
    cout << "(recursive) Factorial of " << n << " is " << fat << endl;
    fat = iterFactorial(n);
    cout << "(iterative) Factorial of " << n << " is " << fat << endl;
}

// calculate factorial of a number recursively
int recFactorial(int n) {
    if (n==1){
        return 1;
    } else {
        return n * recFactorial(n-1);
    }
}

// calculate factorial of a number iteratively
int iterFactorial(int n){
    int fat = 1;
    for(int i=2; i<=n; i++)
        fat = fat * i;
    return fat;
}
