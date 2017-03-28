/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 14:34:06 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/28 14:42:36 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int carPosition(unsigned int parkingRow)
{
	int count = 0;

	if (parkingRow == 0 || (parkingRow & (parkingRow - 1)))
		return (-1);
	while (parkingRow > 1)
	{
		parkingRow >>= 1;
		count++;
	}
	return (count);
}
