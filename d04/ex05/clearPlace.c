/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearPlace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:58:39 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/27 22:01:12 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int clearPlace(unsigned int parkingRow, int pos)
{
	int i = 1;

	i <<= pos;
	parkingRow ^= i;
	return (parkingRow);
}
