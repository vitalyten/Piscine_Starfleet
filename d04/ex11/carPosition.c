/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 14:34:06 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/28 15:25:25 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

int carPosition(unsigned int parkingRow)
{
	if (parkingRow == 0 || (parkingRow & (parkingRow - 1)))
		return (-1);
	return ((int)log2(parkingRow1));
}
