/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junkFood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 21:26:11 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/31 15:15:38 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addseller(t_sellers *sellers, char *name, int dist)
{
	int i;

	i = 0;
	if (sellers->distance == 0)
		sellers->distance = dist;
	if (sellers->distance == dist)
	{
		while (sellers->placeNames[i])
			i++;
		sellers->placeNames[i] = strdup(name);
	}
}

struct s_sellers *closestSellers(struct s_graph *graph, char *youAreHere)
{
	int i;
	int dist = 1;
	t_node **places = graph->places;

	while (*places && strcmp(youAreHere, (*places)->name))
		places++;
	if (!*places)
		return (NULL);
	t_node *node = *places;
	t_sellers *sellers = (t_sellers *)malloc(sizeof(t_sellers));
	if (!sellers)
		return (NULL);
	sellers->placeNames = (char **)malloc(sizeof(char *) * 100);
	sellers->distance = 0;
	for (i = 0; i < 100; i++)
		sellers->placeNames[i] = NULL;
	if (node->hasCerealBar)
	{
		sellers->placeNames[0] = strdup(node->name);
		return (sellers);
	}
	node->visited = -1;
	t_queue *queue = queueInit();
	enqueue(queue, node);
	while (queue->first)
	{
		node = dequeue(queue);
		if (node->visited > 0)
			dist = node->visited + 1;
		places = node->connectedPlaces;
		while (*places)
		{
			if ((*places)->visited == 0)
			{
				(*places)->visited = dist;
				enqueue(queue, *places);
				if ((*places)->hasCerealBar)
				 	addseller(sellers, (*places)->name, dist);
			}
			places++;
		}
	}
	return (sellers);
}
