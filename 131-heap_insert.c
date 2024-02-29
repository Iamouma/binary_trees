#include "binary_trees.h"
/**
 * heap_insert - inserts a value in the MBH
 * @root: a double pointer to the root node of the Heap
 * @value: the value to store in the node
 * Return: a pointer to the created node, else NULL
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *len;
	int size, current, sub, bitt, level, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	current = size;
	for (level = 0, sub = 1; current >= sub; sub *= 2, level++)
		current -= sub;

	for (bitt = 1 << (level - 1); bitt != 1; bitt >>= 1)
		tree = current & bitt ? tree->right : tree->left;
	
	new = binary_tree_node(tree, value);
	current & 1 ? (tree->right = new) : (tree->left = new);

	len = new;
	for (; len->parent && (len->n > len->parent->n); len = len->parent)
	{
		tmp = len->n;
		len->n = len->parent->n;
		len->parent->n = tmp;
		new = new->parent;
	}

	return (new);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure size of
 * Return: 0 if NULL, else size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
