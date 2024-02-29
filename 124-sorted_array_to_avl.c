#include "binary_trees.h"
/**
 * aux_sort - creates tree using half the elements of array
 * @parent: parent of the node
 * @array: the sorted array
 * @beg: where the array starts
 * @las: where the array ends
 * Return: tree created
 */
avl_t *aux_sort(avl_t *parent, int *array, int beg, int las)
{
	avl_t *root;
	binary_tree_t *aux;
	int midd = 0;

	if (beg <= las)
	{
		midd = (beg + las) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[midd]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = aux_sort(root, array, beg, midd - 1);
		root->right = aux_sort(root, array, midd + 1, las);
		return (root);
	}
	return (NULL);
}

/**
 * sorted_array_to_avl - creates a AVL tree
 * @array: sorted array
 * @size: size of the sorted array
 * Return: AVL tree from sorted array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}
