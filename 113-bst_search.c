#include "binary_trees.h"
/**
 * bst_search - searches for a value in a BST
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search for in BST
 * Return: NULL if tree or value not found, or pointer to the node
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
