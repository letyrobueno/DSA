/* 
  To compile it in Linux (terminal): g++ -o program prototype_function.cpp
  To run it in Linux (terminal): ./program
*/

#include<iostream>
using namespace std;

// global variables
int global_variable = 0;

// create the prototype of functions
int increase(int x, int y);
int decrease(int x, int y);

main(){
	int n, m, sum, subtraction;
	cout << "Enter with the 1st value: ";
	cin >> n;
	cout << "Enter with the 2nd value: ";
	cin >> m;
 
	// calling all functions
	sum = increase(n, m);
	subtraction = decrease(n, m);

	cout << n << " + " << m << " = " << sum << endl;
	cout << n << " - " << m << " = " << subtraction << endl;
}

// The functions
int increase(int x, int y){
	return x+y;
}

int decrease(int x, int y){
	return x-y;
}
