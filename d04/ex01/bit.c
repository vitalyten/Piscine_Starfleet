/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:28:59 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/27 14:44:10 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *negate(char *a)
{
	for (int i = 0; i < 4; i++)
		a[i] = (a[i] == '1') ? '0' : '1';
	return (a);
}

char *getAnd(char *a, char *b)
{
	if (a[0] == '~')
		a = negate(a + 1);
	if (b[0] == '~')
		b = negate(b + 1);
	for (int i = 0; i < 4; i++)
		if (a[i] != '1' || b[i] != '1')
			a[i] = '0';
	return (a);
}

char *getOr(char *a, char *b)
{
	if (a[0] == '~')
		a = negate(a + 1);
	if (b[0] == '~')
		b = negate(b + 1);
	for (int i = 0; i < 4; i++)
		if (a[i] == '1' || b[i] == '1')
			a[i] = '1';
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
