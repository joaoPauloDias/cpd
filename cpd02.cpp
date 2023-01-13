#include <bits/stdc++.h>
using namespace std;
//Feito por João Paulo Vasquez Dias e Pedro Henrique Bouvie Roewer

#define RAND 1
#define MEDIAN 2

#define LOMUTO 3
#define HOARE 4


void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(int arr[], int low, int high, int pivot_mode, int partition_mode)
{

    int pivot, pivot_index;

    if(pivot_mode == RAND){
        pivot_index = low + (rand() % (high-low));
    }else if(pivot_mode == MEDIAN){
        pivot = max(min(arr[low],arr[(low+((high-low)/2))]), min(max(arr[low],arr[(low+((high-low)/2))]),arr[high]));

        if(pivot == arr[low])
            pivot_index = low;
        else if( pivot == arr[high])
            pivot_index = high;
        else
            pivot_index = (low+((high-low)/2));

    }

    if(partition_mode == LOMUTO){
        swap(arr[high], arr[pivot_index]);
        pivot = arr[high];

        int i = (low - 1); // Index of smaller element and indicates
                     // the right position of pivot found so far

        for (int j = low; j < high ; j++) {
            if (arr[j] < pivot) {
                i++; // increment index of smaller element
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1], arr[high]);

        return (i + 1);
    }

    if(partition_mode == HOARE){
        swap(arr[low], arr[pivot_index]);
        pivot = arr[low];

        int i = low - 1;
        int f = high + 1;

        while(1){
            while(arr[++i]<pivot){
                continue;
            }
            while(arr[--f]>pivot){
                continue;
            }
            if(i>=f)
                return f;
            swap(arr[i], arr[f]);
        }
    }
}

void quickSort(int arr[], int low, int high, int pivot_mode, int partition_mode)
{

    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high, pivot_mode, partition_mode);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi, pivot_mode, partition_mode);
        quickSort(arr, pi + 1, high, pivot_mode, partition_mode);
    }
}


int main()
{
    int arr[] = { 0, 8, 19, 13, 2, 8, 12, 3, 1, 99, 101, -1, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1, MEDIAN, LOMUTO);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
