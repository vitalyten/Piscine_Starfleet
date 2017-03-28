/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occupiedPlaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 23:58:15 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/28 14:29:20 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int occupiedPlaces(unsigned int parkingRow)
{
	int count = 0;
	while (parkingRow != 0)
	{
		parkingRow = parkingRow & (parkingRow - 1);
		count++;
	}
	return (count);
}
