/*  To compile in Linux from terminal: g++ -o program seqSearchRec.cpp
    To run in Linux from terminal: ./program
*/

#include <iostream> // including standard C++ input/output library file
using namespace std; // it makes easier to reference operations included in std (ex: instead of std::cout we use just cout)

/*
    Recursive Sequential/Linear Search.
    Parameters:
        n: size of the array
        v: list with the elements (passed by reference)
        x: element to search
*/
int SeqSearchRec(int n, int v[], int x) {
    if (n==0) {
        return -1;
    } else if (x==v[n-1]) {
        return n-1;
    } else {
        return SeqSearchRec(n-1, v, x);
    }
}

main (){
    int vector[10]={1,3,5,7,9,11,13,15,17,19};
    int found=-1;
    int x;

    cout << "Enter the element to search: ";
    cin >> x;
    found = SeqSearchRec(10,vector,x);

    if (found==-1) cout << "Element not in the list " << endl;
    else cout << "Element in the position " << found+1 << endl;
}