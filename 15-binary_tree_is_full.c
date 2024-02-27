#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to root node of the tree to chec
 * Return: 0 if tree is not full, else -1
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_full_recursive(tree));
}

/**
 * is_full_recursive - checks if a binary tree is full recursive.
 * @tree: a pointer to the root of the node of the tree to check
 * Return: 0 if tree is full, else 1
 */
int is_full_recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
			(tree->left == NULL && tree->right != NULL) ||
			is_full_recursive(tree->left) == 0 ||
			is_full_recursive(tree->right) == 0)
			return (0);
	}
	return (1);
}
