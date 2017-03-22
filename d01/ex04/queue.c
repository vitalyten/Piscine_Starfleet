/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 22:47:51 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/21 23:56:57 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

int isEmpty(struct s_queue *queue)
{
	if (queue->first == NULL)
		return (1);
	return (0);
}


struct s_queue *queueInit(void)
{
	t_queue *queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}


void enqueue(struct s_queue *queue, char *message)
{
	t_node *elem;

	elem = (t_node *)malloc(sizeof(t_node));
	elem->message = strdup(message);
	if (queue->last == NULL)
	{
		queue->first = elem;
		queue->last = elem;
		return;
	}
	queue->last->next = elem;
	queue->last = elem;
}

char *dequeue(struct s_queue *queue)
{
	if (queue->first == NULL)
		return (NULL);
	t_node *elem = queue->first;
	queue->first = queue->first->next;
	if (queue->first == NULL)
		queue->last = NULL;
	char *ret = strdup(elem->message);
	free(elem);
	return (ret);
}

char *peek(struct s_queue *queue)
{
	if (queue->first == NULL)
		return (NULL);
	char *ret = strdup(queue->first->message);
	return (ret);
}
