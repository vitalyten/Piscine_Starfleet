/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longestSequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:26:43 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/28 16:27:55 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int longestSequence(unsigned int parkingRow)
{
	int ret = 0;

	while (parkingRow)
	{
		parkingRow &= (parkingRow << 1);
		ret++;
	}
	return (ret);
}
