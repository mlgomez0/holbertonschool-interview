#include "binary_trees.h"

/**
 * iterate_level - function inserts in last node
 * @tree: root of binary tree
 * @level: level to interate
 * @value: value in node to insert
 * @new: double pointer for new node
*/

void iterate_level(heap_t *tree, int level, int value, heap_t **new)
{
	if (tree->right == NULL)
	{
		if (level == 1 && *new == NULL)
		{
			*new = binary_tree_node(tree, value);
			if (tree->left == NULL)
				tree->left = *new;
			else
				tree->right = *new;
		}
		return;
	}
	if (level > 1)
	{
		iterate_level(tree->left, level - 1, value, new);
		iterate_level(tree->right, level - 1, value, new);
	}

}

/**
 * binary_tree_height - that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: If tree is NULL, return 0
*/

size_t binary_tree_height(heap_t *tree)
{
	size_t height_left = 0, height_rigth = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		height_left = binary_tree_height(tree->left) + 1;
	if (tree->right)
		height_rigth = binary_tree_height(tree->right) + 1;
	if (height_left >= height_rigth)
		return (height_left);
	else
		return (height_rigth);
}

/**
 * get_last_node - gets last node and insets a node
 * @tree: pointer to the root node
 * @value: value to add to the new node
 * Return: new node
*/

heap_t *get_last_node(heap_t *tree, int value)
{
	int i, height = 0;
	heap_t *new = NULL;

	height = binary_tree_height(tree);
	for (i = 1; i <= height + 1; i++)
	{
		iterate_level(tree, i, value, &new);


	}
	return (new);

}

/**
 * heap_insert - inserst a new node in a max-heap
 * @root: double pointer to the root node of the tree
 * @value: value to add to the new node
 * Return: If tree is NULL, your function must return 0
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL;
	heap_t *father = NULL;
	int temp;

	if (*root == NULL)
	{
		new = binary_tree_node(*root, value);
		*root = new;
		return (new);
	}
	new = get_last_node(*root, value);
	father = new;
	while (father->parent != NULL)
	{
		father = father->parent;
		if (father->n < new->n)
		{
			temp = father->n;
			father->n = new->n;
			new->n = temp;
			new = father;
		}
		else
			break;
	}
	if ((*root)->n < new->n)
	{
		temp = (*root)->n;
		(*root)->n = new->n;
		new->n = temp;
	}
	return (new);
}
