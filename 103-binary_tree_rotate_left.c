#include "binary_trees.h"
/**
 * binary_tree_rotate_left - rotates a binary tree left
 * @tree: a [ointer to the root node of the tree to rotate
 * Return: a pointer to the new root after rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *current, *len;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	current = tree->right;
	len = current->left;
	current->left = tree;
	tree->right = len;
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