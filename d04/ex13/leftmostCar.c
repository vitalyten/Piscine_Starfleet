/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftmostCar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 15:55:28 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/28 16:04:44 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int leftmostCar(unsigned int parkingRow)
{
	int ret = 0;

	if (parkingRow == 0)
		return (-1);
	while (parkingRow != 1)
	{
		parkingRow >>= 1;
		ret++;
	}
	return (ret);
}
