#include<iostream>
using namespace std;

int decreaseWithReturn(int num1, int num2) {
    int total;
    total = num1 - num2; 
    return total;
}

void decreaseWithoutReturn(int num1, int num2){
    int total;
    total = num1 - num2; 
    cout << "(No return) Result: " << total << endl;
}

main(){
    int total;
    total = decreaseWithReturn(10,4);
    decreaseWithoutReturn(10,4);
    cout << "(With return) Result: " << total << endl;
}
