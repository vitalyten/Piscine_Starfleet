/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:38:34 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/22 16:48:10 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printstacks(t_stack **stacks, int n)
{
	int i;

	i = -1;
	while (++i < n)
	{
		if (i == 0)
			printf("normal  ");
		else
			printf("nitro%d  ", i);
	}
	printf("\n");
	i = -1;
	while (++i < n)
		printf("------  ");
	printf("\n");
	i = -1;
	while (++i < n)
		printf("|%-4d|  ", stacks[i]->sum);
	printf("\n");
	i = -1;
	while (++i < n)
		printf("|    |  ");
	printf("\n\n");
}

struct s_tank *initTank(void)
{
	t_tank *tank;

	tank = (t_tank *)malloc(sizeof(t_tank));
	tank->stacks = (t_stack **)malloc(sizeof(t_stack *) * 2);
	tank->stacks[0] = (t_stack *)malloc(sizeof(t_stack));
	tank->stacks[1] = NULL;
	tank->stacks[0]->elem = NULL;
	tank->stacks[0]->sum = 0;
	tank->n = 1;
	return (tank);
}

void tankPush(struct s_tank *tank, int energy)
{
	t_elem	*elem;
	int		i = 0;

	printf("push(%d):\n\n", energy);
	if (energy < 10 || energy > 999)
		return;
	elem = (t_elem *)malloc(sizeof(t_elem));
	elem->energy = energy;
	elem->next = NULL;
	while (tank->stacks[i])
	{
		if (tank->stacks[i]->sum + energy < 1000)
			break;
		i++;
	}
	if (tank->stacks[i] == NULL)
	{
		tank->n++;
		tank->stacks = (t_stack **)realloc(tank->stacks, sizeof(t_stack *) * (tank->n + 1));
		tank->stacks[tank->n] = NULL;
		tank->stacks[i] = (t_stack *)malloc(sizeof(t_stack));
		tank->stacks[i]->elem = NULL;
		tank->stacks[i]->sum = 0;
	}
	tank->stacks[i]->sum += energy;
	elem->next = tank->stacks[i]->elem;
	tank->stacks[i]->elem = elem;
	printstacks(tank->stacks, tank->n);
}

int tankPop(struct s_tank *tank)
{
	t_stack *stack;
	t_elem	*elem;
	int i = 0;
	int ret = 0;

	while (tank->stacks[i])
		i++;
	stack = tank->stacks[i - 1];
	if (stack->elem == NULL)
	{
		printf("pop() == 0\n\n");
		printstacks(tank->stacks, tank->n);
		return(0);
	}
	elem = stack->elem;
	ret = elem->energy;
	stack->sum -= ret;
	if (elem->next)
		stack->elem = elem->next;
	else
		stack->elem = NULL;
	if (tank->n > 1)
	{
		free(stack);
		tank->n--;
		tank->stacks = (t_stack **)realloc(tank->stacks, sizeof(t_stack *) * (tank->n + 1));
		tank->stacks[tank->n] = NULL;
	}
	printf("pop() == %d\n\n", ret);
	printstacks(tank->stacks, tank->n);
	return (ret);
}
