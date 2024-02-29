#include "binary_trees.h"
/**
 * binary_tree_is_heap - check if a binary tree is a MBH
 * @tree: a pointer to the root node of the tree
 * Return: 1 if tree is MBH, 0 NULL, else 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (b_helper(tree));
}

/**
 * b_helper - check if a binary tree is a MBH
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is MBH, 1 if NULL, else 0
 */
int b_helper(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!binary_tree_is_complete(tree))
		return (0);

	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);
	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);

	return (b_helper(tree->left) &&
		b_helper(tree->right));
}

/**
 * binary_tree_is_complete - check if a binary tree is complete
 * @tree: a pointer to the root node of the tree
 * Return: 1 if tree is complete, 0 if not, else 0 if NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);

	return (bc_helper(tree, 0, size));
}

/**
 * bc_helper - check if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * @index: node index to be checked
 * @size: number of nodes in the tree
 * Return: 1 if complete, 0 if not, else NULL
 */
int bc_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (bc_helper(tree->left, 2 * index + 1, size) &&
		bc_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size
 * Return: 0 if the tree is NULL, else size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
