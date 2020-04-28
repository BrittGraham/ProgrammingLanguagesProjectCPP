#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;
auto SelectionSort(int A[], int n);
auto BubbleSort(int A[], int n);
void merge(int A[], int low, int mid, int high);
void mergeSort(int A[], int low, int high);
int partition(int A[], int low, int high);
void quickSort(int A[], int low, int high);

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
    int i;
    int j;
    int k;
    int bSize = mid - low + 1;
    int cSize = high - mid;

    int b[bSize];
    int c[cSize];
    //copy data into arrays
    for (int i = 0; i < bSize; ++i) {
        b[i] = A[low + i];
    }
    for (int j = 0; j < cSize; ++j) {
        c[j] = A[mid + 1 + j];
    }
    k = low;
    i = 0;
    j = 0;
    //merge the temp arrays into A
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
    //Copy remaining elements if they exist.
    while(i < bSize) {
        A[k] = b[i];
        i++;
        k++;
    }

    while(j < cSize) {
        A[k] = c[j];
        j++;
        k++;
    }

}

void mergeSort(int A[], int low, int high){
    if(low < high){
        //int middle = low+floor((high-1)/2);
        int middle = floor((low+high)/2);
        //sorting both halves
        mergeSort(A, low, middle);
        mergeSort(A, middle+1,high);
        merge(A, low, middle, high);
    }
}

int partition(int A[], int low, int high){
    int pivot = A[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (A[j] <= pivot){
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    }
    int temp = A[i+1];
    A[i+1] = A[high];
    A[high] = temp;
    return i + 1;
}

void quickSort(int A[], int low, int high){
    if (low < high){
        int i = partition(A,low,high);
        quickSort(A, low, i-1);
        quickSort(A, i+1, high);
    }
}

int main(){
    int arr[7800] = {};
    int SS[7800];
    int BS[7800];
    int MS[7800];
    int QS[7800];
    //Creating a random array.
    for(int i = 0; i < 7800; i++) {
        arr[i] = (rand()%2000 + (-1000));
    }
    //creating copies of random array for each sorting array.
    for (int j = 0; j < 7800; ++j) {
        SS[j] = arr[j];
        BS[j] = arr[j];
        MS[j] = arr[j];
        QS[j] = arr[j];
    }

    auto ssTime = SelectionSort(SS, 7800);
    cout << "Part of new array after Selection Sort: ";
    //Printing array out
//    for(int a = 0; a < 100; a++){
//        cout << SS[a] << " ";
//    }
    cout << endl;
    cout << "SelectionSort time: " << ssTime.count() << " Milliseconds"<< endl;
    cout << "SelectionSort lines of code: 10" << endl;
    cout << "------------------------------------------------------------------" << endl;
    auto bsTime = BubbleSort(BS, 7800);
    cout << "Part of new array after Bubble Sort: ";
//    for(int b = 0; b < 100; b++){
//        cout << BS[b] << " ";
//    }
    cout << endl;
    cout << "BubbleSort time: " << bsTime.count() << " Milliseconds"<< endl;
    cout << "BubbleSort lines of code: 6" << endl;
    cout << "------------------------------------------------------------------" << endl;
    int msSize = sizeof(MS)/sizeof(MS[0]);
    auto msStart = high_resolution_clock::now();
    mergeSort(MS,0, msSize - 1);
    auto msEnd = high_resolution_clock::now();
    auto msDuration = duration_cast<milliseconds>(msEnd - msStart);
    cout << "Part of new array after Merge Sort: ";
//    for(int c = 0; c < 100; c++){
//        cout << MS[c] << " ";
//    }
    cout << endl;
    cout << "MergeSort time: " << msDuration.count() << " Milliseconds"<< endl;
    cout << "MergeSort lines of code: 35" << endl;
    cout << "------------------------------------------------------------------" << endl;
    int qsSize = sizeof(QS)/sizeof(QS[0]);
    auto qsStart = high_resolution_clock::now();
    quickSort(QS,0,qsSize - 1);
    auto qsEnd = high_resolution_clock::now();
    auto qsDuration = duration_cast<milliseconds>(qsEnd - qsStart);
    cout << "Part of new array after Quick Sort: ";
//    for(int d = 0; d < 100; d++){
//        cout << QS[d] << " ";
//    }
    cout << endl;
    cout << "QuickSort time: " << qsDuration.count() << " Milliseconds"<< endl;
    cout << "QuickSort lines of code: 16" << endl;


    return 0;
}