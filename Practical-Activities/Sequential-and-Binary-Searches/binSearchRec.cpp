/*  To compile in Linux from terminal: g++ -o program binSearchRec.cpp
    To run in Linux from terminal: ./program
*/

#include <iostream> // including standard C++ input/output library file
using namespace std; // it makes easier to reference operations included in std (ex: instead of std::cout we use just cout)

/*
    Recursive Binary Search.
    Parameters:
        v: list with the elements (passed by reference)
        ini: first position to look
        end: last position to look
        elem: element to search
*/
int BinSearchRec(int v[],int ini,int end,int elem);

main (){
    int v[10]={1,3,5,7,9,11,13,15,17,19};
    int found, x;

    cout << "Enter the element to search: ";
    cin >> x;
    found=BinSearchRec(v,0,9,x);

    if (found==-1) cout << "Element not in the list " << endl;
    else cout << "Element in the position " << found+1 << endl;
}

int BinSearchRec(int v[],int ini,int end,int elem) {
    while (ini<=end) {
        int meio;
        meio = (ini+end)/2;
        if (v[meio]==elem){
            return meio;
        } else if (v[meio]<elem) {
            return BinSearchRec(v,meio+1,end,elem);
        } else {
            return BinSearchRec(v,ini,meio-1,elem);
        }
    }
    return -1;
}
