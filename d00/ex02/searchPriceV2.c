/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 20:42:58 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/20 21:15:00 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int	binarySearch(struct s_art **arr, int l, int r, char *x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;
		if (strcmp(arr[mid]->name, x) == 0)
			return (arr[mid]->price);
		if (strcmp(arr[mid]->name, x) > 0)
			return (binarySearch(arr, l, mid - 1, x));
		return binarySearch(arr, mid + 1, r, x);
	}
	return (-1);
}

int	searchPrice(struct s_art **arts, char *name)
{
	int len;

	len = 0;
	while (arts[len])
		len++;
	return (binarySearch(arts, 0, len - 1, name));
}
