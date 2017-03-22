/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printReverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 19:55:25 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/21 20:11:43 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void printRec(t_node *lst, int i)
{
	if (lst->next)
		printRec(lst->next, ++i);
	printf("%s", lst->word);
	if (i == 1)
		printf("\n");
	else
		printf(" ");
}

void printReverse(t_node *lst)
{
	printRec(lst, 0);
}
