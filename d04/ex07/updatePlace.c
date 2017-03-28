/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatePlace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 22:22:01 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/27 22:29:37 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int updatePlace(unsigned int parkingRow, int pos, int value)
{
	unsigned int i = 1;

	i <<= pos;
	if (value == 0)
		parkingRow &= ~i;
	else
		parkingRow |= i;
	return (parkingRow);
}
