/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:41:20 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/23 16:23:36 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

int	findmax(t_node *node)
{
	int max;

	max = node->value;
	if (node->left)
		max = MAX(max, findmax(node->left));
	if (node->right)
		max = MAX(max, findmax(node->right));

	return (max);
}

int	findmin(t_node *node)
{
	int min;

	min = node->value;
	if (node->left)
		min = MIN(min, findmin(node->left));
	if (node->right)
		min = MIN(min, findmin(node->right));

	return (min);
}

int	findelem(t_node *node)
{
	int ret;

	ret = 0;
	if (node)
	{
		ret++;
		if (node->left)
			ret += findelem(node->left);
		if (node->right)
			ret += findelem(node->right);
	}
	return (ret);
}

int	finddep(t_node *node)
{
	int ret;

	ret = 0;
	if (node)
	{
		if (node->left || node->right)
			ret++;
		ret += MAX(finddep(node->left), finddep(node->right));
	}
	return (ret);
}

int	height(t_node *node)
{
	if (node == NULL)
		return (0);
	return (1 + MAX(height(node->left), height(node->right)));
}

int	isbst(t_node *node)
{
	if (node == NULL)
		return (1);
	if (node->left && findmax(node->left) > node->value)
		return (0);
	if (node->right && findmin(node->right) <= node->value)
		return (0);
	return  (isbst(node->left) && isbst(node->right));
}

int	isbal(t_node *node)
{
	int lh;
	int rh;

	if (node == NULL)
		return (1);
	lh = height(node->left);
	rh = height(node->right);
	if (abs(lh - rh) <= 1 && isbal(node->left) && isbal(node->right))
		return (1);
	return (0);
}

struct s_info   getInfo(struct s_node *root)
{
	t_node *tmp;
	t_info info;

	tmp = root;
	info.max = findmax(root);
	info.min = findmin(root);
	info.elements = findelem(root);
	info.depth = height(root);
	info.isBST = isbst(root);
	info.isBalanced = isbal(root);
	// printf("\nmax    = %d\n", info.max);
	// printf("min    = %d\n", info.min);
	// printf("elem   = %d\n", info.elements);
	// printf("height = %d\n", info.depth);
	// printf("isBST  = %d\n", info.isBST);
	// printf("isBal  = %d\n", info.isBalanced);
	return (info);
}
