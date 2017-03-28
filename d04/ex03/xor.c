/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:54:35 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/27 21:14:26 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *getXor(char *a, char *b)
{

	for (int i = 0; i < 6; i++)
		if ((a[i] == '1' && b[i] != '1') || (a[i] != '1' && b[i] == '1'))
			a[i] = '1';
		else
			a[i] = '0';
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
