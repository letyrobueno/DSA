/* Quadratic sorting algorithms: Insertion, Selection and Bubble sort.
    With two different implementations for Insertion Sort and Bubble Sort, for which the best implementation runs in 
    linear time in the best case (elements already partially sorted).
    To compile it in Linux (terminal): g++ -o program quadratic-sorting.cpp
    To run it in Linux (terminal): ./program
*/

#include<cstdlib>
#include<iostream>

using namespace std;

// Insertion sort. Complexity: O(n^2) in the worst and best cases
void insertion(int n, char S[]){
    char key;
    int k;
    
    for (int j=2; j<=n; j++){
        key = S[j];
        k = j;
        for (int i=j-1; i>=1; i--){
            if (S[i]>key){
                S[i+1] = S[i]; 
                k = i;
            }
        }
        S[k] = key;
    }        
}
   
// Insertion sort. Complexity: O(n^2) in the worst case and O(n) in the best case
void insertion_best(int n, char S[]){
    char key;
    int i;
    
    for (int j=2; j<=n; j++){
        key = S[j];
        i = j-1;
        while ((i>0) && (S[i]>key)){
            S[i+1] = S[i]; 
            i = i-1;
        }
        S[i+1] = key;
    }        
}

// Selection sort. Complexity: O(n^2) in the worst and best cases
void selection(int n, char S[]){
    char key;
    int index;
    
    for (int i=1; i<=n-1; i++){
        key = S[i]; 
        index = i; 
        for (int j = i+1; j <= n; j++){
            if (S[j]<key){
                key = S[j]; 
                index = j; 
            }
        }
        S[index]= S[i];
        S[i] = key; 
    }
}
        
// Bubble sort. Complexity: O(n^2) in the worst and best cases        
void bubble(int n, char S[]){
    char key;
    for (int i = 1; i <= n; i++){
        for (int j = 2; j <= n; j++){
            if (S[j-1]>S[j]){
                key = S[j-1];
                S[j-1] = S[j];
                S[j] = key;
            }
        }
    }
}

// Bubble sort. Complexity: O(n^2) in the worst case and O(n) in the best case
void bubble_best(int n, char S[]){
    char key;
    int pass = 1;
    bool sorted = false;
    
    while ((pass < n) && (sorted == false)){
        sorted = true;
        for (int i=1; i <= n-pass; i++){
            if (S[i] > S[i+1]){
                key = S[i];
                S[i] = S[i+1];
                S[i+1] = key;
                sorted = false;
            }
        }
        pass = pass + 1;
    }
}

int main(int argc, char** argv) {
    char S[20];
    S[1] = 'S'; S[2] = 'O'; S[3] = 'R'; S[4] = 'T'; S[5] = 'I'; S[6] = 'N'; S[7] = 'G';

    cout << "\n*************\n Unsorted Elements\n*************\n";
    for (int i=1; i<=7; i++)
        cout << "S[" << i <<"]: " << S[i] << "\n";
    
    cout << "\n*************\n Sorted by Bubble Sort\n*************\n";
    bubble_best(7, S);
    for (int i=1; i<=7; i++)
        cout << "S[" << i << "]: " << S[i] << "\n";    

    return 0;
}
