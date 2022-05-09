#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}


int main()
{
    int arr[8];
    int i = 0;

    while (i < 8)
    {
        arr[i] = 8 - i;
        i++;
    }
    print_array(arr, 8);
    print_array(&arr[2], 4);
    return (0);
}
