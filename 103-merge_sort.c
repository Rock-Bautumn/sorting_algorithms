#include <stdlib.h>
#include "sort.h"

/*
 * int left_half_size = middle - left + 1;
 * int right_half_size = right - middle;
*/

/**
 * print_labeled_array - prints the array with the name of the array
 * @label: The name we are printing with the label
 * @array: The array to print
 * @size: How many elements of the array to print
 * Return: void
*/

void print_labeled_array(char *label, int *array, int size)
{
	printf("[%s]: ", label);
	print_array(array, size);
}

/**
 * merge_sort_merge - This does the actual work of the merge sort
 * @array: The original array address we are sorting, even if recursively
 * @left: The left part of the left half
 * @middle: The middle value used to split
 * @right: The right of the right half side
 * Return: void
 */
void merge_sort_merge(int *array, int left, int middle, int right)
{
	int x, y, insertion_point;
	int left_half_size = middle - left + 1;
	int right_half_size = right - middle;
	int old_left[4096], old_right[4096];

	printf("Merging...\n");
	for (x = 0; x < left_half_size; x++)
		old_left[x] = array[left + x];
	print_labeled_array("left", &array[left], left_half_size);
	for (x = 0; x < right_half_size; x++)
		old_right[x] = array[(middle + x + 1)];
	print_labeled_array("right", &array[middle + 1], right_half_size);
	x = 0, y = 0, insertion_point = left;
	while (x < left_half_size && y < right_half_size)
	{
		if (old_left[x] <= old_right[y])
		{
			array[insertion_point] = old_left[x];
			x++;
		}
		else
		{
			array[insertion_point] = old_right[y];
			y++;
		}
		insertion_point++;
	}
	while (x < left_half_size)
	{
		array[insertion_point] = old_left[x];
		x++;
		insertion_point++;
	}
	while (y < right_half_size)
	{
		array[insertion_point] = old_right[y];
		y++;
		insertion_point++;
	}
}

/**
 * merge_sort - the entry point to the recursive function that does the sorting
 * @array: pointer to the array
 * @size: size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	merge_sorter(array, 0, (size - 1));
}

/**
 * merge_sorter - The recursive function that actually does the sorting
 * @array: pointer to the array
 * @left: 0 index
 * @right: last index
 * Return: void
 */
void merge_sorter(int *array, int left, int right)
{
	if (left < right)
	{
		int middle = (right - left) / 2 + left;

		merge_sorter(array, left, middle);
		merge_sorter(array, (middle + 1), right);

		merge_sort_merge(array, left, middle, right);
		print_labeled_array("done", &array[left], (right - left));

	}
}
