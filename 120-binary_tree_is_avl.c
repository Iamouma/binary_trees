#include "binary_trees.h"
#include "limits.h"
/**
 * height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: 0 if treee NULL, otherwise height
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lef = 0, rig = 0;

		lef = tree->left ? 1 + height(tree->left) : 1;
		rig = tree->right ? 1 + height(tree->right) : 1;
		return ((lef > rig) ? lef : rig);
	}
	return (0);
}

/**
 * is_avl_helper - checks if a binary tree is a valid AVL tree
 * @tree: a pointer to the root node of the tree to check
 * @low: value of the smallest node visited
 * @high: value of the largest node visited
 * Return: 1 if the tree is valid AVL tree, else 0
 */
int is_avl_helper(const binary_tree_t *tree, int low, int high)
{
	size_t lefhgt, righgt, diff;

	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		lefhgt = height(tree->left);
		righgt = height(tree->right);
		diff = lefhgt > righgt ? lefhgt - righgt : righgt - lefhgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, low, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL tree, else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
