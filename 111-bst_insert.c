#include "binary_trees.h"
/**
 * bst_insert - inserts a value in a BST
 * @tree: a double pointer to the root node of the BST
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *len, *new;

	if (tree != NULL)
	{
		len = *tree;

		if (len == NULL)
		{
			new = binary_tree_node(len, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}

		if (value < len->n)
		{
			if (len->left != NULL)
				return (bst_insert(&len->left, value));

			new = binary_tree_node(len, value);
			if (new == NULL)
				return (NULL);
			return (len->left = new);
		}
		if (value > len->n)
		{
			if (len->right != NULL)
				return (bst_insert(&len->right, value));

			new = binary_tree_node(len, value);
			if (new == NULL)
				return (NULL);
			return (len->right = new);
		}
	}
	return (NULL);
}
