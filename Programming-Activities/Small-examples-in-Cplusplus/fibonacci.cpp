/* Program to calculate Fibonacci numbers, i.e., 
	F(0) = 0
	F(1) = 1
	F(n) = F(n-1) + F(n-2), for n>1

    To compile it in Linux (terminal): g++ -o fibonacci fibonacci.cpp
    To run it in Linux (terminal): ./fibonacci
*/

#include<iostream>
using namespace std;

int recFibonacci(int n);
int iterFibonacci(int n);

main(){
	int n, fib;
	cout << "Enter with a value for n: ";
	cin >> n;
	fib = recFibonacci(n);
	cout << "(recursive) Fibonacci of " << n << " is " << fib << endl;
	fib = iterFibonacci(n);
    cout << "(iterative) Fibonacci of " << n << " is " << fib << endl;
}

// calculate Fibonacci numbers recursively
int recFibonacci(int n){
	if (n < 2){
		return n;
	} else {
		return recFibonacci(n-1) + recFibonacci(n-2);
	}
}

// calculate Fibonacci numbers iteratively
int iterFibonacci(int n){
	int i = 1, j = 0, t;
	for (int k=1; k<=n; k++){
		t = i + j;
		i = j;
		j = t;
	}
	return j;
}
