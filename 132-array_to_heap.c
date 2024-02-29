#include "binary_trees.h"
/**
 * array_to_heap - builds a MBH tree from an array
 * @array: a pointer to the first element of the array
 * @size: size of the array
 * Return: a pointer to the root node, else NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int len;
	heap_t *root = NULL;

	for (len = 0; len < size; len++)
		heap_insert(&root, array[len]);

	return (root);
}
