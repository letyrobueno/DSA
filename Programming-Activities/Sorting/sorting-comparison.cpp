/* Sorting algorithms implemented for comparison of practical time. 
    Quadratic algorithms (in the worst case): Insertion Sort, Selection Sort, and Bubble Sort.
    Efficient algorithms: HeapSort, MergeSort and QuickSort.
    To compile it in Linux (terminal): g++ -o program sorting-comparison.cpp
    To run it in Linux (terminal): ./program
*/

#include<cstdlib>
#include<iostream>
#include<fstream>   // to manipulate files
#include<string.h>  // for using method strcpy
#include<stdlib.h>  // for generating random numbers
#include<math.h>
#include<limits.h>

using namespace std;
char method_name[20];


//******************* INPUT AND OUTPUT METHODS **************************************
 
// Write total time of execution in the output file
void writeTotalTimeFile(int totaltime){
    ofstream myfile; // open file and points to the next position where to write an element
    myfile.open("sorting.txt",ios::app); // append the text at the final position of the file
    myfile << "################################################## \nTotal Time: " << totaltime << "\n";
    myfile.close();
}

// Write seed used in the output file
void writeFile(int n, int seed){
    ofstream myfile; // open file and points to the next position where to write an element
    myfile.open("sorting.txt", ios::app); // append the text at the final position of the file
    myfile << "################################################## \nn: " << n << " Seed: " << seed << "\n";
    myfile.close();
}

// Write results in the output file
void writeResults(int V[], int n, int time){
    ofstream myfile; // open file and points to the next position where to write an element
    myfile.open("sorting.txt", ios::app); // append the text at the final position of the file
    myfile << "Algorithm: " << method_name << "\n";
    myfile << "Time: " << time << "\n \n";
    myfile.close();
}

void printArray(int V[], int n){
    for (int i=0; i<n; i++)
        cout << "V[" << i << "]: " << V[i] << "\n";
}

//******************* QUADRATIC SORTING ALGORITHMS **************************************
// Insertion sort. Complexity: O(n^2) in the worst case and O(n) in the best case
void insertionSort(int V[], int n){
    int key;
    int i;
        
    for (int j=1; j < n; j++){
        key = V[j];
        i = j-1;
        while ((i >= 0) && (V[i] > key)){
            V[i+1] = V[i]; 
            i = i-1;
        }
        V[i+1] = key;
    }        
}

// Selection sort. Complexity: O(n^2) in the worst and best cases
void selectionSort(int V[], int n){
    int key;
    int index;
    
    for (int i=0; i < n; i++){
        key = V[i]; 
        index = i; 
        for (int j = i+1; j < n; j++){
            if (V[j] < key){
                key = V[j]; 
                index = j; 
            }
        }
        V[index] = V[i];
        V[i] = key; 
    }
}
        
// Bubble sort. Complexity: O(n^2) in the worst case and O(n) in the best case
void bubbleSort(int V[], int n){
    int key;
    int pass = 1;
    bool sorted = false;
    
    while ((pass < n) && (sorted == false)){
        sorted = true;
        for (int i=0; i < n-pass; i++){
            if (V[i] > V[i+1]){
                key = V[i];
                V[i] = V[i+1];
                V[i+1] = key;
                sorted = false;
            }
        }
        pass = pass + 1;
    }
}

//*******************MÉTODOS DE ORDENAÇÃO EFICIENTES**************************************

// HeapSort. Complexity: O(n log n) in the worst and best case
void Heapify(int V[], int i, int NHeap){
    int le, ri, greatest, aux;
    le = (2*i);
    ri = ((2*i)+1);
    if ((le < NHeap) && (V[le] > V[i]))
        greatest = le;
    else greatest = i;

    if ((ri < NHeap) && (V[ri] > V[greatest]))
        greatest = ri;

    if (greatest != i){
        aux = V[i];
        V[i] = V[greatest];
        V[greatest] = aux;
        Heapify(V, greatest, NHeap);
    }
}

void HeapBuild(int V[], int n){
    for(int i=floor(n/2); i>=0; i--)
        Heapify(V, i, n);
}

void heapSort(int V[], int n){
    int aux;
    int NHeap = n;
    HeapBuild(V, n);
    for(int i=(n-1); i>=0; i--) {
        aux = V[0];
        V[0] = V[i];
        V[i] = aux;
        NHeap = NHeap - 1;
        Heapify(V, 0, NHeap);
    }
}

// MergeSort. Complexity: O(n log n) in the worst and best case
void merge(int V[], int ini, int middle, int end){
    int p = middle - ini + 1;
    int m = end - middle;
    int L[end], R[end];

    for (int i=0; i<p; i++) L[i] = V[ini+i];

    for (int j=1; j<=m; j++) R[j-1] = V[(middle + j)];

    L[p] = INT_MAX;
    R[m] = INT_MAX;
    int i = 0;
    int j = 0;
    for (int k=ini; k<=end; k++){
        if (L[i] <= R[j]){
            V[k] = L[i];
            i = i + 1;
        } else {
            V[k] = R[j];
            j = j + 1;
        }
    }
}

void mergeSort(int V[], int ini, int end){
    if (ini < end){
        int middle = floor((ini + end) / 2);
        mergeSort(V, ini, middle);
        mergeSort(V, middle + 1, end);
        merge(V, ini, middle, end);
    }
}

// QuickSort. Complexity: O(n log n) in the worst and average case, O(n^2) in the worst case

// Traditional QuickSort: this method divides the sequence in the middle
int partition(int V[], int p, int r){
    int aux;
    int pivot = V[r];
    int i = p-1;
    for (int j=p; j <= r-1; j++){
        if (V[j] <= pivot){
            i = i+1;
            aux = V[i];
            V[i] = V[j];
            V[j] = aux;
        }
    }
    aux = V[i+1];
    V[i+1] = V[r];
    V[r] = aux;
    return (i+1);
}

// Random QuickSort: this method divides the sequence in a random position
int randomPartition(int V[], int p, int r){
    int i = rand() % (r-p+1) + p; // take a random number between p and r
    int aux = V[i];
    V[i] = V[r];
    V[r] = aux;
    return partition(V, p, r);
}

void quickSort(int V[], int p, int r){
    if (p<r){
        // int q = partition(V, p, r); // For a traditional QuickSort, use this line
        int q = randomPartition(V, p, r); // For a random QuickSort, use this line
        quickSort(V, p, q-1);
        quickSort(V, q+1, r);
    }
}

//******************* MAIN METHOD **************************************
int main() {
    time_t secondsProgram = time(NULL);

    int n = 30000;
    int V[n];

    int seed[6];
    seed[0] = 4;
    seed[1] = 81;
    seed[2] = 151;
    seed[3] = 1601;
    seed[4] = 2307;
    seed[5] = 4207;
    
    for(int t=0; t<6; t++){
        // *********** BUBBLE SORT ***********
        srand(seed[t]);
        for(int i=0; i<n; i++){
            V[i] = rand();
        }

        cout << "SEQUENCE GENERATED -- SEED: " << seed[t] << "\n";
        writeFile(n, seed[t]);

        time_t seconds = time(NULL);
        bubbleSort(V, n);
        int runned_time = time(NULL) - seconds;

        cout << "SORTED SEQUENCE - BUBBLE SORT\n";
        cout << "Time: " << runned_time << "\n";
        strcpy(method_name, "Bubble Sort");
        writeResults(V, n, runned_time);

        // *********** SELECTION SORT ***********
        srand(seed[t]);
        for(int i=0; i<n; i++){
            V[i] = rand();
        }

        cout << "SEQUENCE GENERATED -- SEED: " << seed[t] << "\n";
        seconds = time(NULL);
        selectionSort(V, n);
        runned_time = time(NULL) - seconds;
    
        cout << "SORTED SEQUENCE - SELECTION SORT\n";
        cout << "Time: " << runned_time << "\n";
        strcpy(method_name, "Selection Sort");
        writeResults(V, n, runned_time);

        // *********** INSERTION SORT ***********
        srand(seed[t]);
        for(int i=0; i<n; i++){
            V[i] = rand();
        }

        cout << "SEQUENCE GENERATED -- SEED: " << seed[t] << "\n";
        seconds = time(NULL); 
        insertionSort(V, n);
        runned_time = time(NULL) - seconds;
    
        cout << "SORTED SEQUENCE - INSERTION SORT\n";
        cout << "Time: " << runned_time << "\n";
        strcpy(method_name, "Insertion Sort");
        writeResults(V, n, runned_time);

        // *********** MERGESORT ***********
        srand(seed[t]);
        for(int i=0; i<n; i++){
            V[i] = rand();
        }

        cout << "SEQUENCE GENERATED -- SEED: " << seed[t] << "\n";
        seconds = time(NULL); 
        mergeSort(V, 0, n-1);
        runned_time = time(NULL) - seconds;
    
        cout << "SORTED SEQUENCE - MERGESORT\n";
        cout << "Time: " << runned_time << "\n";
        strcpy(method_name, "MergeSort");
        writeResults(V, n, runned_time);

        // *********** HEAPSORT ***********
        srand(seed[t]);
        for(int i=0; i<n; i++){
            V[i] = rand();
        }

        cout << "SEQUENCE GENERATED -- SEED: " << seed[t] << "\n";
        seconds = time(NULL); 
        heapSort(V, n);
        runned_time = time(NULL) - seconds;
    
        cout << "SORTED SEQUENCE - HEAPSORT\n";
        cout << "Time: " << runned_time << "\n";
        strcpy(method_name, "HeapSort");
        writeResults(V, n, runned_time);

        // *********** QUICKSORT ***********
        srand(seed[t]);
        for(int i=0; i<n; i++){
            V[i] = rand();
        }

        cout << "SEQUENCE GENERATED -- SEED: " << seed[t] << "\n";
        seconds = time(NULL); 
        quickSort(V, 0, n-1);
        runned_time = time(NULL) - seconds;
    
        cout << "SORTED SEQUENCE - QUICKSORT\n";
        cout << "Time: " << runned_time << "\n";
        strcpy(method_name, "QuickSort");
        writeResults(V, n, runned_time);
    }

    int runned_timeProgram = time(NULL) - secondsProgram;
    cout << "Total time of execution: " << runned_timeProgram << "\n";
    writeTotalTimeFile(runned_timeProgram);
    return 0;
}
