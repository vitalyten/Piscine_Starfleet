/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 13:22:32 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/21 13:46:05 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>

#define d 256 // number of characters in input alphabet
#define q 97 // prime number

int howManyJesus(char *bible, char *jesus)
{
	int M = strlen(jesus);
	int N = strlen(bible);
	int i, j;
	int p = 0; // hash value for jesus
	int t = 0; // hash value for bible
	int h = 1;
	int ret = 0;

	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;
	for (i = 0; i < M; i++)
	{
		p = (d * p + jesus[i]) % q;
		t = (d * t + bible[i]) % q;
	}
	for (i = 0; i < N - M; i++)
	{
		if (p == t)
		{
			for (j = 0; j < M; j++)
			{
				if (bible[i + j] != jesus[j])
					break;
			}
			if (j == M)
				ret++;
		}
		if (i < N - M)
		{
			t = (d * (t - bible[i] * h) + bible[i + M]) % q;
			if (t < 0)
				t = (t + q);
		}
	}
	return (ret);
}

