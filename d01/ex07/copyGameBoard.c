/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyGameBoard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:39:07 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/22 22:31:00 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct s_node *cloneGameBoard(struct s_node *node)
{
	t_node *cur;
	t_node *tmp;
	t_node *orig;
	t_node *copy;

	cur = node;
	while (cur)
	{
		tmp = cur->next;
		cur->next = (t_node *)malloc(sizeof(t_node));
		cur->next->value = cur->value;
		cur->next->random = NULL;
		cur->next->next = tmp;
		cur = tmp;
	}
	cur = node;
	while (cur)
	{
		if (cur->next && cur->random)
			cur->next->random = cur->random->next;
		cur = cur->next ? cur->next->next : cur->next;
	}
	orig = node;
	copy = node->next;
	tmp = copy;
	while (orig && copy)
	{
		orig->next = orig->next ? orig->next->next : orig->next;
		copy->next = copy->next ? copy->next->next : copy->next;
		orig = orig->next;
		copy = copy->next;
	}
	return (tmp);
}
