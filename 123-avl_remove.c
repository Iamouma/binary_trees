#include "binary_trees.h"
/**
 * bl - checks balance factor for AVL
 * @tree: tree to check
 * Return: balanced factor
 */
void bl(avl_t **tree)
{
	int len;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bl(&(*tree)->left);
	bl(&(*tree)->right);
	len = binary_tree_balance((const binary_tree_t *)*tree);
	if (len > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (len < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor - gets the next successor
 * @node: tree to check
 * Return: the minimum value of the node
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}

/**
 * remove_type - removes a node depending of its children
 * @root: node to remove
 * Return: 0 if it has no children, else other values
 */
int remove_type(bst_t *root)
{
	int i = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		i = successor(root->right);
		root->n = i;
		return (i);
	}
}

/**
 * bst_remove - remove a node from BST
 * @root: root of the tree
 * @value: node with value to remove
 * Return: tree modified
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int current = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		current = remove_type(root);
		if (current != 0)
			bst_remove(root->right, current);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - removes a node from a AVL tree
 * @root: root of the binary tree
 * @value: node with value to modify
 * Return: tree modified
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bl(&root_a);
	return (root_a);
}
