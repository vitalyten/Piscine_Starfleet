/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPriceV2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 20:28:05 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/29 14:55:38 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

double recSlices(int size, double *best, double *prices)
{
	if (best[size])
		return (best[size]);
	if (best[size] == 0)
		best[size] = prices[size];
	double tmp;
	for (int i = 1; i <= size / 2; i++)
		if ((tmp = (recSlices(i, best, prices) + recSlices(size - i, best, prices))) > best[size])
			best[size] = tmp;
	return (best[size]);
}

double optimizedBestPrice(int pizzaSize, double *prices)
{
	double *best = malloc(sizeof(double) * (pizzaSize + 1));
	for (int i = 0; i <= pizzaSize; i++)
		best[i] = 0;
	return (recSlices(pizzaSize, best, prices));
}
