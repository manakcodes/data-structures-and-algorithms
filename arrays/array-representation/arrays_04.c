#include <stdio.h>

int main()
{
    int size = 0;
    printf("enter the size of the array : ");
    scanf("%zu", &size);

    int arr[size];

    printf("array of size %zu created successfully\n", size);

    return 0;
}