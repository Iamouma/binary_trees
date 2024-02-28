#include "binary_trees.h"
/**
 * binary_tree_rotate_right - Rotates a binary tree right.
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node after rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *current, *len;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	current = tree->left;
	len = current->right;
	current->right = tree;
	tree->left = len;
	if (len != NULL)
		len->parent = tree;
	len = tree->parent;
	tree->parent = current;
	current->parent = len;
	if (len != NULL)
	{
		if (len->left == tree)
			len->left = current;
		else
			len->right = current;
	}

	return (current);
}
