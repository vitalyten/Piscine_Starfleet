/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rightmostCar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:07:59 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/28 16:10:07 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int rightmostCar(unsigned int parkingRow)
{
	int ret = 0;

	if (parkingRow == 0)
		return (-1);
	while ((parkingRow & 1) == 0)
	{
		parkingRow >>= 1;
		ret++;
	}
	return (ret);
}
