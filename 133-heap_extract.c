#include "binary_trees.h"
/**
 * tree_height - measures height of a binary tree
 * @tree: a pointer to the root node of the tree to measure
 * Return: height of the treee, else NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t hgt_lef = 0;
	size_t hgt_rig = 0;

	if (!tree)
		return (0);

	if (tree->left)
		hgt_lef = 1 + tree_height(tree->left);

	if (tree->right)
		hgt_rig = 1 + tree_height(tree->right);

	if (hgt_lef > hgt_rig)
		return (hgt_lef);
	return (hgt_rig);
}

/**
 * tree_size_ht - measures sum of a tree
 * @tree: a pointer to the root node of the tree
 * Return: Height of the tree, else 0 if NULL
 */
size_t tree_size_ht(const binary_tree_t *tree)
{
	size_t hgt_lef = 0;
	size_t hgt_rig = 0;

	if (!tree)
		return (0);

	if (tree->left)
		hgt_lef = 1 + tree_size_ht(tree->left);

	if (tree->right)
		hgt_rig = 1 + tree_size_ht(tree->right);

	return (hgt_lef + hgt_rig);
}

/**
 * _preorder - traverse a binary tree using pre-order
 * @tree: a pointer to the root node pf the tree to traverse
 * @node: last node to traverse
 * @height: heigth of the tree
 * Return: Nothing
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - heapifies MBH
 * @root: a pointer to binary heap
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *len1, *len2;

	if (!root)
		return;

	len1 = root;

	while (1)
	{
		if (!len1->left)
			break;
		if (!len1->right)
			len2 = len1->left;
		else
		{
			if (len1->left->n > len1->right->n)
				len2 = len1->left;
			else
				len2 = len1->right;
		}
		if (len1->n > len2->n)
			break;
		value = len1->n;
		len1->n = len2->n;
		len2->n = value;
		len1 = len2;
	}
}

/**
 * heap_extract - extracts the root node of a MBH
 * @root: a double pointer to the root node of heap
 * Return: 0 on fauilure, else value in the node
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (value);
	}

	_preorder(heap_r, &node, tree_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r);
	*root = heap_r;
	return (value);
}
