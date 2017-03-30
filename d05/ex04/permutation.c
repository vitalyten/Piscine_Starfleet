/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 15:26:26 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/29 19:25:10 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>

void swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	permute(char *str, int l, int r)
{
	if (l == r)
		printf("%s\n", str);
	else
		for (int i = l; i <= r; i++)
		{
			swap((str + l), (str + i));
			permute(str, l + 1, r);
			swap((str + l), (str + i));
		}
}

void	printPermutations(char *str)
{
	permute(str, 0, strlen(str) - 1);
}
