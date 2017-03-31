/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 21:00:19 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/30 21:14:16 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

t_node *newnode(int val)
{
	t_node *node = (t_node *)malloc(sizeof(t_node));
	if (node)
	{
		node->value = val;
		node->left = NULL;
		node->right = NULL;
	}
	return (node);
}

t_node *arraytobst(int *arr, int start, int end)
{
	if (start > end)
		return (NULL);
	int mid = (start + end) / 2;
	t_node *root = newnode(arr[mid]);
	root->left = arraytobst(arr, start, mid - 1);
	root->right = arraytobst(arr, mid + 1, end);
	return (root);
}

struct s_node *createBST(int *arr, int n)
{
	return (arraytobst(arr, 0, n - 1));
}
