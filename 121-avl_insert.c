#include "binary_trees.h"
/**
 * height - measures the height of a binary tree
 * @tree: a pointer to the root of the tree to measure the height
 * Return: if NULL return 0, else return height
 */
size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t lef = 0, rig = 0;

		lef = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		rig = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((lef > rig) ? lef : rig);
	}
	return (0);
}

/**
 * balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance
 * Return: 0 if the tree is NULL, else balance factor
 */
int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recursive - inserts a value into an AVL tree recursively
 * @tree: double pointer tom the root node of the AVL
 * @parent: parent node of the current working node
 * @new: double pointer to store the new node
 * @value: value to insert into the AVL tree.
 * Return: pointer to the new root after insertion, or NULL
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int tmp;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	tmp = balance(*tree);
	if (tmp > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (tmp < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (tmp > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (tmp < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - inserts a value into an AVL tree
 * @tree: double pointer to the root node of the AVL tree to insert
 * @value: value to insert into the AVL tree
 * Return: pointer to the inserted node, else NULL
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new, value);
	return (new);
}
