/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:50:49 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/20 14:26:47 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int  searchPrice(struct s_art **arts, char *name)
{
	int i;

	i = 0;
	while (arts[i] && strcmp(name, arts[i]->name))
		i++;
	if (arts[i])
		return (arts[i]->price);
	return (-1);
}
