#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

auto SelectionSort(int A[], int n){
    auto start = high_resolution_clock::now();
    for (int i = 0; i < n-1; ++i) {
        int first = i;
        int minimum = first;
        for (int j = i + 1; j < n; ++j) {
            if(A[j] < A[minimum]){
                minimum = j;
            }
        }
        if (minimum != first){
            int temp = A[minimum];
            A[minimum] = A[i];
            A[i] = temp;
        }
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration;
}

auto BubbleSort(int A[], int n){
    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (n-i); ++j) {
            if (A[j-1] > A[j]){
                int temp = A[j-1];
                A[j-1] = A[j];
                A[j] = temp;
            }
        }
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration;
}

void merge(int A[], int low, int mid, int high){
    int i, j, k;
    int bSize = mid - low + 1;
    int cSize = high - mid;

    int b[bSize];
    int c[cSize];
    for (int i = 0; i < bSize; ++i) {
        b[i] = A[low + i];
    }
    for (int j = 0; j < cSize; ++j) {
        c[j] = A[mid + 1 + j];
    }
    k = low;
    i = 0;
    j = 0;
    while (i < bSize && j < cSize){
        if(b[i] <= c[j]){
            A[k] = b[i];
            i++;
        }
        else{
            A[k] = c[j];
            j++;
        }
        k++;
    }
    while(j < cSize) {
        A[k] = c[j];
        j++;
        k++;
    }

    while(i < bSize) {
        A[k] = b[i];
        i++;
        k++;
    }
}

void mergeSort(int A[], int low, int high){
    if(low < high){
        int middle = low+(high-1)/2;
        mergeSort(A, low, middle);
        mergeSort(A, middle+1,high);
        merge(A, low, middle, high);
    }
}

int main(){
    int arr[1000] = {};
    int SS[1000];
    int BS[1000];
    int MS[1000];
    int QS[1000];
    //Creating a random array.
    for(int i = 0; i < 1000; i++) {
        arr[i] = (rand()%2000 + (-1000));
    }
    //creating copies of random array for each sorting array.
    for (int j = 0; j < 1000; ++j) {
        SS[j] = arr[j];
        BS[j] = arr[j];
        MS[j] = arr[j];
        QS[j] = arr[j];
    }

    auto ssTime = SelectionSort(SS, 1000);
    cout << "New array after Selection Sort: ";
    for(int a = 0; a < 1000; a++){
        cout << SS[a] << " ";
    }
    cout << endl;
    cout << "SelectionSort time: " << ssTime.count() << " Milliseconds"<< endl;
    cout << "SelectionSort lines of code: 10" << endl;
    cout << "------------------------------------------------------------------" << endl;
    auto bsTime = BubbleSort(BS, 1000);
    cout << "New array after Bubble Sort: ";
    for(int b = 0; b < 1000; b++){
        cout << BS[b] << " ";
    }
    cout << endl;
    cout << "BubbleSort time: " << bsTime.count() << " Milliseconds"<< endl;
    cout << "BubbleSort lines of code: 6" << endl;
    cout << "------------------------------------------------------------------" << endl;
    auto start = high_resolution_clock::now();
    mergeSort(MS,0, 999);
    auto end = high_resolution_clock::now();
    auto msDuration = duration_cast<milliseconds>(end - start);
    cout << "New array after Merge Sort: ";
    for(int c = 0; c < 1000; c++){
        cout << MS[c] << " ";
    }
    cout << endl;
    cout << "MergeSort time: " << msDuration.count() << " Milliseconds"<< endl;
    cout << "MergeSort lines of code: 33" << endl;


    return 0;
}