#include <stdio.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}

void insertion(int arr[], int element, int index, int size)
{
    if (size >= 100)
    {
        return;
    }
    for (int i = size; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
}

void deletion(int arr[], int num, int *size)
{
    int found = 0;
    for (int i = 0; i < *size; i++)
    {
        if (arr[i] == num)
        {
            found = 1;
        }
        if (found && i < *size - 1)
        {
            arr[i] = arr[i + 1];
        }
    }
    if (found)
    {
        (*size)--;
    }
}

int main()
{
    int arr[100] = {2, 3, 4, 5, 6};
    int size = 5; // Correct initial size
    int element;
    int index;

    printf("Array before insertion:\n");
    display(arr, size);

    printf("Enter element to be inserted: ");
    scanf("%d", &element);

    printf("Enter index to be inserted: ");
    scanf("%d", &index);

    insertion(arr, element, index, size);
    size++;
    printf("Array after insertion:\n");
    display(arr, size);

    int num;
    printf("Enter number to be deleted: ");
    scanf("%d", &num);

    deletion(arr, num, &size);
    printf("Array after deletion:\n");
    display(arr, size);

    return 0;
}
