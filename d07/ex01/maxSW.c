/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxSW.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:36:36 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/30 20:52:14 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <limits.h>

struct s_deque *dequeInit(void)
{
	t_deque *deque = (t_deque *)malloc(sizeof(t_deque));
	if (deque)
	{
		deque->first = NULL;
		deque->last = NULL;
	}
	return (deque);
}

void pushFront(struct s_deque *deque, int value)
{
	t_dequeNode *node = (t_dequeNode *)malloc(sizeof(t_dequeNode));
	if (node)
	{
		node->value = value;
		node->prev = deque->first;
		node->next = NULL;
		if (deque->last == NULL)
		{
			deque->first = node;
			deque->last = node;
		}
		else
		{
			deque->first->next = node;
			deque->first = node;
		}
	}
}

void pushBack(struct s_deque *deque, int value)
{
	t_dequeNode *node = (t_dequeNode *)malloc(sizeof(t_dequeNode));
	if (node)
	{
		node->value = value;
		node->next = deque->last;
		node->prev = NULL;
		if (deque->last == NULL)
		{
			deque->first = node;
			deque->last = node;
		}
		else
		{
			deque->last->prev = node;
			deque->last = node;
		}
	}
}

int popFront(struct s_deque *deque)
{
	if (deque->first == NULL)
		return (INT_MIN);
	int val = deque->first->value;
	t_dequeNode *node = deque->first;
	if (deque->first == deque->last)
	{
		deque->first = NULL;
		deque->last = NULL;
	}
	else
		deque->first = node->prev;
	free(node);
	return (val);
}

int popBack(struct s_deque *deque)
{
	if (deque->last == NULL)
		return (INT_MIN);
	int val = deque->last->value;
	t_dequeNode
	 *node = deque->last;
	if (deque->first == deque->last)
	{
		deque->first = NULL;
		deque->last = NULL;
	}
	else
		deque->last = node->next;
	free(node);
	return (val);
}

struct s_max *maxSlidingWindow(int *arr, int n, int k)
{
	t_deque *deque = dequeInit();
	t_max *max = (t_max *)malloc(sizeof(t_max));
	if (!max)
		return (NULL);
	max->length = n - k + 1;
	max->max = (int *)malloc(sizeof(int) * max->length);
	int i;
	for (i = 0; i < k; ++i)
	{
		while (deque->first != NULL && arr[i] >= arr[deque->last->value])
			popBack(deque);
		pushBack(deque, i);
	}
	int j = 0;
	for ( ; i < n; ++i)
	{
		max->max[j++] = arr[deque->first->value];
		while (deque->first != NULL && deque->first->value <= i - k)
			popFront(deque);
		while (deque->first != NULL && arr[i] >= arr[deque->last->value])
			popBack(deque);
		pushBack(deque, i);
	}
	max->max[j] = arr[deque->first->value];
	return (max);
}
