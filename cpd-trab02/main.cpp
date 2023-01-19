#include <bits/stdc++.h>
using namespace std;
//Feito por Joao Paulo Vasquez Dias e Pedro Henrique Bouvie Roewer

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

int partition(int arr[], int low, int high, int pivot_mode, int partition_mode, int *swaps)
{

    int pivot, pivot_index;

    if(pivot_mode == RAND)
    {
        pivot_index = low + (rand() % (high-low));
    }
    else if(pivot_mode == MEDIAN)
    {
        pivot = max(min(arr[low],arr[(low+((high-low)/2))]), min(max(arr[low],arr[(low+((high-low)/2))]),arr[high]));

        if(pivot == arr[low])
            pivot_index = low;
        else if( pivot == arr[high])
            pivot_index = high;
        else
            pivot_index = (low+((high-low)/2));

    }

    if(partition_mode == LOMUTO)
    {
        swap(arr[high], arr[pivot_index]);
        (*swaps)++;
        pivot = arr[high];

        int i = (low - 1);

        for (int j = low; j < high ; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
                (*swaps)++;
            }
        }
        swap(arr[i+1], arr[high]);
        (*swaps)++;

        return (i + 1);
    }

    if(partition_mode == HOARE)
    {
        swap(arr[low], arr[pivot_index]);
        (*swaps)++;
        pivot = arr[low];

        int i = low - 1;
        int f = high + 1;

        while(1)
        {
            while(arr[++i]<pivot)
            {
                continue;
            }
            while(arr[--f]>pivot)
            {
                continue;
            }
            if(i>=f)
                return f;
            swap(arr[i], arr[f]);
            (*swaps)++;
        }
    }
}

void quickSort(int arr[], int low, int high, int pivot_mode, int partition_mode, int *swaps, int *recursions)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, pivot_mode, partition_mode, swaps);
        (*recursions)+=2;
        quickSort(arr, low, pi, pivot_mode, partition_mode, swaps, recursions);
        quickSort(arr, pi + 1, high, pivot_mode, partition_mode, swaps, recursions);
    }
}


int main()
{
    /* int arr[] = { 0, 8, 19, 13, 2, 8, 12, 3, 1, 99, 101, -1, -2};
     int n = sizeof(arr) / sizeof(arr[0]);
     int swaps = 0, recursions = 0;
     quickSort(arr, 0, n - 1, MEDIAN, LOMUTO, &swaps, &recursions);
     cout << "Sorted array: \n";
     printArray(arr, n);
     cout << swaps << ' '<< recursions<< "\n";
     return 0;*/

    int tamanho_vetor, swaps, recursions;
    clock_t start_clock, end_clock;
    while (scanf("%d", &tamanho_vetor) != EOF)
    {
        int vetor[tamanho_vetor];
        swaps = 0;
        recursions = 0;

        for (int i=0; i<tamanho_vetor; i++)
            scanf("%d", &vetor[i]);

        start_clock = clock();
        quickSort(vetor, 0, tamanho_vetor-1, MEDIAN, LOMUTO, &swaps, &recursions);
        end_clock = clock();

        printf("TAMANHO ENTRADA %d\nSWAPS %d\nRECURSOES %d\nTEMPO %f\n", tamanho_vetor, swaps, recursions,(end_clock - start_clock)/(double)CLOCKS_PER_SEC);
    }
}
