#include <stdio.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int binarysearch(int arr[], int element, int size)
{
    int beg = 0;
    int end = size - 1;
    int mid;
    
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (element > arr[mid])
        {
            beg = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[10] = {2, 3, 4, 5, 6}; 
    int size = 5;
    int element;
    int index;

    printf("Enter element to be found: ");
    scanf("%d", &element);

    index = binarysearch(arr, element, size);

    if (index == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at index %d\n", index);
    }

    display(arr, size);

    return 0;
}
