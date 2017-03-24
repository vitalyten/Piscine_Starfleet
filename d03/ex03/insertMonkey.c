/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertMonkey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 23:30:02 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/24 00:17:59 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

// typedef struct  s_node {
// 	int value;
// 	struct s_node *right;
// 	struct s_node *left;
// }               t_node;



int	height(t_node *node)
{
	if (node == NULL)
		return (0);
	return (1 + MAX(height(node->left), height(node->right)));
}

void	swapleft(t_node **n1, t_node **n2)
{
	t_node *tmp;

	// int tmp;

	// tmp = (*n1)->value;
	// (*n1)->value = (*n2)->value;
	// (*n2)->value = tmp;
	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;

	tmp = (*n1)->right;
	(*n1)->right = (*n2)->right;
	(*n2)->right = tmp;

	tmp = (*n1)->left;
	(*n1)->left = (*n2)->left;
	(*n2)->left = tmp;
}

void	swapright(t_node **n1, t_node **n2)
{
	t_node *tmp;

	// int tmp;

	// tmp = (*n1)->value;
	// (*n1)->value = (*n2)->value;
	// (*n2)->value = tmp;
	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;

	tmp = (*n1)->left;
	(*n1)->left = (*n2)->left;
	(*n2)->left = tmp;

	tmp = (*n1)->right;
	(*n1)->right = (*n2)->right;
	(*n2)->right = tmp;


}


int	ismaxheap(t_node *node)
{
	if (node->left == NULL && node->right == NULL)
		return (1);
	if (node->left && node->left->value > node->value)
		return (0);
	if (node->right && node->right->value > node->value)
		return (0);
	return (ismaxheap(node->left) && ismaxheap(node->right));
}

int	isminheap(t_node *node)
{
	if (node->left == NULL && node->right == NULL)
		return (1);
	if (node->left && node->left->value < node->value)
		return (0);
	if (node->right && node->right->value < node->value)
		return (0);
	return (isminheap(node->left) && isminheap(node->right));
}

void	maxify(struct s_node **root)
{
	if (*root == NULL)
		return;
	puts("test");
	while (!ismaxheap(*root))
	{
		maxify(&((*root)->left));
		if ((*root)->left && (*root)->left->value > (*root)-> value)
			swapleft(root, &((*root)->left));
		maxify(&((*root)->right));
		if ((*root)->right && (*root)->right->value > (*root)-> value)
			swapright(root, &((*root)->right));
	}
}

int	countelem(t_node *node)
{
	int ret;

	ret = 0;
	if (node)
	{
		ret++;
		if (node->left)
			ret += countelem(node->left);
		if (node->right)
			ret += countelem(node->right);
	}
	return (ret);
}

void insertrec(struct s_node **root, struct s_node *monkey)
{
	if (*root == NULL)
	{
		*root = monkey;
		return;
	}
	if (countelem((*root)->left) > countelem((*root)->right))
		insertMonkey(&((*root)->right), monkey);
	else
		insertMonkey(&((*root)->left), monkey);
}

void insertMonkey(struct s_node **root, struct s_node *monkey)
{
	insertrec(root, monkey);

	// maxify(root);
	// int h;
	// t_node *tmp;

	// tmp = monkey;
	// h = height(*root);
	// printf("%d\n", h);
}













