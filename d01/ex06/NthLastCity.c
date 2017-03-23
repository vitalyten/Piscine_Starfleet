/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NthLastCity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:13:20 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/22 19:29:08 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

char *NthLastCity(struct s_city *city, int n)
{
	t_city	*last = city;
	t_city	*nth = city;
	int		i = 0;

	while (i < n + 1)
	{
		if (last == NULL)
			return (NULL);
		last = last->next;
		i++;
	}
	while (last)
	{
		last = last->next;
		nth = nth->next;
	}
	return (nth->name);
}
