#include <stdio.h>
#include "isort.h"

int main()
{
    int arr[SIZE];
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("Enter the %ld number: ", i + 1);

        scanf("%d", &arr[i]);
    }
    printf("The original array:\n");
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    insertion_sort(arr, SIZE);
    printf("\nThe sorted array:\n");

    printf("%d", arr[0]);
    for (size_t i = 1; i < SIZE; i++)
    {
        
        printf(",%d", arr[i]);
    }
    printf("\n");
    return 0;
}