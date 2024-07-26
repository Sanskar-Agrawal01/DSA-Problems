#include <stdio.h>

void PrintArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: %d\n", i, A[i]);
    }
}

int partition(int *A, int low, int high)
{
    int temp;
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);
    
    // Swap the pivot element with A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    
    return j;
}

void QuickSort(int *A, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(A, low, high);
        QuickSort(A, low, partitionIndex - 1);
        QuickSort(A, partitionIndex + 1, high);
    }
}

int main()
{
      int A[] = {9, 4, 4, 8, 7, 5, 6};
    int n = 7;
    PrintArray(A, n);
    QuickSort(A, 0, n-1);
    PrintArray(A, n);

    return 0;
}
