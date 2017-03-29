/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinkIsland.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 15:10:35 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/29 15:18:19 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

void sinkIsland(int **map, int row, int col)
{
	if (row < 0 || map[row] == NULL || col < 0 || map[row][col] != 1)
		return;
	map[row][col] = 0;
	sinkIsland(map, row, col - 1);
	sinkIsland(map, row, col + 1);
	sinkIsland(map, row + 1, col);
	sinkIsland(map, row - 1, col);
}
