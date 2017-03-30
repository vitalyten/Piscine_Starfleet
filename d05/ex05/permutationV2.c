/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutationV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:53:14 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/29 20:54:28 by vtenigin         ###   ########.fr       */
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

void	permute(char *str, int l, int r, t_dict *dict)
{
	if (l == r)
	{
		if (dictSearch(dict, str) != 1)
		{
			puts(str);
			dictInsert(dict, str, 1);
		}
	}
	else
		for (int i = l; i <= r; i++)
		{
			swap((str + l), (str + i));
			permute(str, l + 1, r, dict);
			swap((str + l), (str + i));
		}
}

void	printUniquePermutations(char *str)
{
	int len = strlen(str);
	int exp = 1;
	for (int i = 1; i <= len; i++)
		exp *= i;
	t_dict *dict = dictInit(exp);
	permute(str, 0, len - 1, dict);
}
