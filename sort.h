#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void heap_sort(int *array, int n);
void insertion_sort_list(listint_t **list);
void merge_sort_merge(int *array, int left, int middle, int right);
void merge_sort(int *array, size_t size);
void merge_sorter(int *array, int left, int right);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quicksort_2(int *array, int left, int right, size_t size);
int partition(int *array, int left, int right, size_t size);
void merge_sort(int *array, size_t size);
void mergeSort(int *array, int start, int end, int *temp_array);
void merge(int *array, int start, int mid, int end, int *temp_array);
void print_labeled_array(char *label, int *array, int size);
void radix_sort(int arr[], int n);

#endif
