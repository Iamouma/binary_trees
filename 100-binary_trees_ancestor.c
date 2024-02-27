#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor
 * @first: a pointer to the first node
 * @second: a pointer to the second mde
 * Return: NULL if no common ancestor, otherwise common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mama, *baba;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mama = first->parent, baba = second->parent;
	if (first == baba || !mama || (!mama->parent && baba))
		return (binary_trees_ancestor(first, baba));
	else if (mama == second || !baba || (!baba->parent && mama))
		return (binary_trees_ancestor(mama, second));
	return (binary_trees_ancestor(mama, baba));
}
