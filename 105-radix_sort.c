#include "sort.h"

/**
 * radix_sort - Sorting using place values from least significant digit
 * @arr: The array to sort
 * @n: the number of digits of the array (to sort on the left side)
 * Return: void
*/

void radix_sort(int arr[], int n)
{
	int maximum = arr[0], digits = 0, i, j, num, power;
	int count[10];
	int *new_array;

	for (i = 1; i < n; i++)
	{
		if (maximum < arr[i])
		maximum = arr[i];
	}
	while (maximum > 0)
	{
		digits++;
		maximum /= 10;
	}
	power = 1;
	for (i = 0; i < digits; i++)
	{
		new_array = malloc(sizeof(int) * n);
		for (j = 0; j < 10; j++)
			count[j] = 0;
		for (j = 0; j < n; j++)
		{
			num = (arr[j] / power) % 10;
			count[num]++;
		}
		for (j = 1; j < 10; j++)
			count[j] += count[j - 1];
		for (j = n - 1; j >= 0; j--)
		{
			num = (arr[j] / power) % 10;
			new_array[count[num] - 1] = arr[j];
			count[num]--;
		}
		for (j = 0; j < n; j++)
			arr[j] = new_array[j];
		power *= 10;
		free(new_array);
		print_array(arr, n);
	}
}
