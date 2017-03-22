/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 20:49:50 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/21 22:39:10 by vtenigin         ###   ########.fr       */
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


void push(struct s_stack *stack, int idx)
{
	t_item *elem = (t_item *)malloc(sizeof(t_item));

	elem->idx = idx;
	elem->next = stack->item;
	stack->item = elem;
}

int pop(struct s_stack *stack)
{
	t_item *elem;

	if (!(elem = stack->item))
		return (0);
	stack->item = elem->next;
	return (elem->idx);
}

char *console(void)
{
	size_t size = 255;
	char *msg = (char *)malloc(sizeof(char) * 256);
	char *input = (char *)malloc(sizeof(char) * 256);
	t_stack *stack = stackInit();
	int i;

	msg[0] = '\0';
	input[0] = '\0';
	printf("?: ");
	while (getline(&input, &size, stdin) > 0)
	{
		i = 0;
		while (input[i] && input[i] != '\n')
			i++;
		input[i] = '\0';
		if (strcmp("SEND", input) == 0)
			break;
		if (strcmp("UNDO", input) == 0)
		{
			i = pop(stack);
			msg[i] = '\0';
		}
		else
		{
			push(stack, strlen(msg));
			if (strlen(msg) > 0)
				strcat(msg, " ");
			strcat(msg, input);
		}
		printf("%s\n", msg);
		printf("?: ");
	}
	return (msg);
}
