#include "binary_trees.h"
/**
 * is_leaf - checks if a node is a leaf
 * @node: a pointer to the node to check
 * Return: 1 if the node is a leaf, else 0
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - returns the depth of a node in a binary tree
 * @tree: a pointer to the node to measure
 * Return: depth of node
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - returns depth of a node in a binary tree
 * @tree: a pointer to the node to measure depth
 * Return: a pointer to the first checked leaf
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * @leaf_dep: the depth of one leaf
 * @level: level of current node
 * Return: 1 if the tree is perfect, else 0
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_dep, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_dep ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_dep, level + 1) &&
		is_perfect_recursive(tree->right, leaf_dep, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: a pointer to the root node of the tree to check
 * Return: 0 if not perfect, else 1
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
