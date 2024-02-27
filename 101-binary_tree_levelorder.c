#include "binary_trees.h"
/**
 * create_node - creates a new levelorder node
 * @node: the new node
 * Return: NULL if an error occurs, else a pointer to the new node
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * free_queue - frees a levelorder queue
 * @head: a pointer to the head of the queue
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *len;

	while (head != NULL)
	{
		len = head->next;
		free(head);
		head = len;
	}
}

/**
 * print_push - pushe the children of a binary tree to a levelorder queue
 * @node: binary tree to print and push
 * @head: pointer to the head of the queue
 * @tail: pointer to the tail of the queue
 * @func: pointer to the function to call on node
 */
void print_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = create_node(node->left);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
	if (node->right != NULL)
	{
		new = create_node(node->right);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
}

/**
 * pop - pops the head of a levelorder queue
 * @head: duoble pointer to the head of the queue
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *len;

	len = (*head)->next;
	free(*head);
	*head = len;
}

/**
 * binary_tree_levelorder - iterates a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		print_push(head->node, head, &tail, func);
		pop(&head);
	}
}

