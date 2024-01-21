#include "sort.h"


/**
 * swap - Swaps two integers in an array.
 * @x: Pointer to the first integer to swap.
 * @y: Pointer to the second integer to swap.
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Will print the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly;

	if (array == NULL || size < 2)
		return;
	do {
		bubbly = false;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + i + 1);
				print_array(array, size);
				bubbly = true;
			}
		}
		len--;
	} while (bubbly);
}
