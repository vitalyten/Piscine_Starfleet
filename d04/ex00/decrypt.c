/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:55:17 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/27 14:25:46 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *getSum(char *a, char *b)
{
	int c = 0;

	for (int i = 5; i >= 0; i--)
	{
		if (a[i] - '0' + b[i] - '0' + c == 1)
		{
			a[i] = '1';
			c = 0;
		}
		else if (a[i] - '0' + b[i] - '0' + c == 2)
		{
			a[i] = '0';
			c = 1;
		}
	}
	return (a);
}

int toInt(char *bits)
{
	int	ret;

	ret = 0;
	while (*bits)
	{
		ret = ret * 2 + *bits - '0';
		bits++;
	}
	return (ret);
}
