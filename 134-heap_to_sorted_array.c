#include "binary_trees.h"
/**
 * tree_size - measures the sum of height of a tree
 * @tree: a pointer to the root node of the tree to remove
 * Return: height , else 0 if NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t hgt_lef = 0;
	size_t hgt_rig = 0;

	if (!tree)
		return (0);

	if (tree->left)
		hgt_lef = 1 + tree_size(tree->left);

	if (tree->right)
		hgt_rig = 1 + tree_size(tree->right);

	return (hgt_lef + hgt_rig);
}

/**
 * heap_to_sorted_array - converts a MBH to sorted array
 * @heap: a pointer to the root node of the heap
 * @size: size of the array
 * Return: NULL on failure, else generated array
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *b = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	b = malloc(sizeof(int) * (*size));

	if (!b)
		return (NULL);

	for (i = 0; heap; i++)
		b[i] = heap_extract(&heap);

	return (b);
}
