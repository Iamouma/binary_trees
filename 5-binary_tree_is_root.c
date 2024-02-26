#include "binary_trees.h"
/**
 * binary_tree_is_root - checks if a node is a root
 * @node: a pointer to the node to check
 * Return: if node is a root return -1, otherwise 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}