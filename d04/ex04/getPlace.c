/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getPlace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:23:49 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/27 21:56:10 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "header.h"

#include <stdio.h>

int getPlace(unsigned int parkingRow, int pos)
{
	unsigned int i = 1;

	i <<= pos;
	if (parkingRow & i)
		return (1);
	else
		return (0);
}
