/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 19:23:26 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/21 19:46:29 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

char *precious(int *text, int size)
{
	t_node *first;
	t_node *node;
	t_node *tmp;
	char	*ret;
	int i, j;

	i = -1;
	first = NULL;
	tmp = NULL;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	while (CS[++i])
	{
		node = (t_node *)malloc(sizeof(t_node));
		node->c = CS[i];
		node->prev = tmp;
		node->next = NULL;
		if (tmp)
			tmp->next = node;
		if (i == 0)
			first = node;
		tmp = node;
	}
	node->next = first;
	first->prev = node;
	i = -1;
	while (++i < size)
	{
		if (text[i] > 0)
		{
			j = -1;
			while (++j < text[i])
				first = first->next;
		}
		else if (text[i] < 0)
		{
			j = 1;
			while (--j > text[i])
				first = first->prev;
		}
		ret[i] = first->c;
	}
	return (ret);
}
