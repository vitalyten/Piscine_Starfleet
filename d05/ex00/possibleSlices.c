/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 18:47:43 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/28 20:21:06 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

void recSlices(int size, t_array *arr, int k)
{
	arrayAppend(arr, k);
	if (arr->sum == size)
		arrayPrint(arr);
	else if (arr->sum < size)
		for (int i = size; i > 0; i--)
			recSlices(size, arrayClone(arr), i);
	free(arr);
}

void printPossibleSlices(int pizzaSize)
{
	if (pizzaSize < 1)
		return ;

	t_array *arr = arrayInit();

	for (int i = pizzaSize; i > 0; i--)
		recSlices(pizzaSize, arrayClone(arr), i);
	free(arr);
}
