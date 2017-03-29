/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 20:28:05 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/28 21:18:37 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

double g_max = 0;

void recSlices(double cur, int rem, double *prices)
{
	if (rem == 0 && cur > g_max)
		g_max = cur;
	else if (rem > 0)
		for (int i = rem; i > 0; i--)
			recSlices(cur + prices[i], rem - i, prices);
}

double bestPrice(int pizzaSize, double *prices)
{
	g_max = prices[pizzaSize];
	for (int i = pizzaSize; i > 0; i--)
		recSlices(0, pizzaSize, prices);
	return (g_max);
}
