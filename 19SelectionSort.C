#include <stdio.h>
void PrintArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Elements of Array: %d\n", A[i]);
    }
}
void SelectionSort(int *A, int n)
{
    int temp;
    for (int i = 0; i <= n - 1; i++)
    {
        int indexofmin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexofmin])
            {
                indexofmin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexofmin];
        A[indexofmin] = temp;
    }
}
int main()
{
    // Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13


    int A[] = {1, 20, 3, 40, 5, 60};
    int n = 6;
    printf("Array before  sort\n");
    PrintArray(A, n);
    SelectionSort(A, n);
    printf("Array After Selection sort (increasing order)\n");
    PrintArray(A, n);
    return 0;
}