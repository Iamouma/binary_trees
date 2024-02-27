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
 * push - pushes a node to the back of a levelorder level queue
 * @node: node to print and push
 * @head: a pointer to the head of the queue
 * @tail: a pointer to the tail of the queue
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new;

	new = create_node(node);
	if (new == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
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
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node to traverse
 * Return: 0 if tree is not complete, else 1
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char tmp = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (tmp == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			tmp = 1;
		if (head->node->right != NULL)
		{
			if (tmp == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			tmp = 1;
		pop(&head);
	}
	return (1);
}
