/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 14:00:50 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/30 16:32:53 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>

struct MaxHeap
{
	int size;
	struct s_art **array;
};

void swap(t_art **a, t_art **b)
{
	t_art *t = *a;
	*a = *b;
	*b = t;
}

void maxHeapify(struct MaxHeap* maxHeap, int idx)
{
	int largest = idx;
	int left = (idx << 1) + 1;  // left = 2*idx + 1
	int right = (idx + 1) << 1; // right = 2*idx + 2

	if (left < maxHeap->size && strcmp(maxHeap->array[left]->name, maxHeap->array[largest]->name) > 0)
		largest = left;
	if (right < maxHeap->size && strcmp(maxHeap->array[right]->name, maxHeap->array[largest]->name) > 0)
		largest = right;
	if (largest != idx)
	{
		swap(&maxHeap->array[largest], &maxHeap->array[idx]);
		maxHeapify(maxHeap, largest);
	}
}

struct MaxHeap* createAndBuildHeap(struct s_art **masterpiece, int size)
{
	int i;
	struct MaxHeap* maxHeap = (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
	maxHeap->size = size;
	maxHeap->array = masterpiece;
	for (i = (maxHeap->size - 2) / 2; i >= 0; --i)
		maxHeapify(maxHeap, i);
	return maxHeap;
}

void heapSort(struct s_art **masterpiece, int n)
{
	struct MaxHeap* maxHeap = createAndBuildHeap(masterpiece, n);
	while (maxHeap->size > 1)
	{
		swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
		--maxHeap->size;
		maxHeapify(maxHeap, 0);
	}
}
