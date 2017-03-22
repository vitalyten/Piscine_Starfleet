/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printReverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 20:17:20 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/21 20:45:16 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct s_stack *stackInit(void)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->item = NULL;
	return (stack);
}


void push(struct s_stack *stack, char *word)
{
	t_item *elem = (t_item *)malloc(sizeof(t_item));

	elem->word = strdup(word);
	elem->next = stack->item;
	stack->item = elem;
}

void *pop(struct s_stack *stack)
{
	t_item *elem;

	if (!(elem = stack->item))
		return (NULL);
	stack->item = elem->next;
	return ((void *)elem);
}

void printReverse(struct s_node *lst)
{
	t_stack *stack = stackInit();
	t_item *item;
	int i = 0;

	while (lst)
	{
		i++;
		push(stack, lst->word);
		lst = lst->next;
	}
	while ((item = (t_item *)pop(stack)))
	{
		i--;
		printf("%s", item->word);
		if (i > 0)
			printf(" ");
		else
			printf("\n");
	}
}
