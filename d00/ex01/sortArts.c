/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:50:40 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/20 17:19:29 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>

void	merge(struct s_art **arr, int l, int m, int r)
{
	int	i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	struct s_art *L[n1];
	struct s_art *R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (strcmp(L[i]->name, R[j]->name) <= 0)
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void	mergeSort(struct s_art **arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void	sortArts(struct s_art **arts)
{
	int len;
	int i;

	len = 0;
	while (arts[len])
		len++;
	mergeSort(arts, 0, len - 1);
	i = 0;
	while (i < len)
	{
		printf("%11d => %.60s\n", arts[i]->price, arts[i]->name);
		i++;
	}
}
