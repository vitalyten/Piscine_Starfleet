/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mostUsedWords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:11:06 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/21 18:45:56 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void	merge(struct s_elem **arr, int l, int m, int r)
{
	int	i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	struct s_elem *L[n1];
	struct s_elem *R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i]->occurence >= R[j]->occurence)
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void	mergeSort(struct s_elem **arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void	sortwords(struct s_list *words)
{
	struct s_elem **elems = words->elems;
	int len;

	len = 0;
	while (elems[len])
		len++;
	mergeSort(elems, 0, len - 1);
}

int is_alpha (char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	return 0;
}


int wordcmp (struct s_elem *a, struct s_elem *b) {
	if (a->occurence < b->occurence) return +1;
	if (a->occurence > b->occurence) return -1;
	return 0;
}

int		findword(struct s_elem **elems, char *word)
{
	int i = 0;
	while (elems[i] && strcmp(elems[i]->word, word))
		i++;
	if (elems[i] && strcmp(elems[i]->word, word) == 0)
	{
		elems[i]->occurence++;
		return (1);
	}
	return (0);
}


int insert_word (struct s_list *words, char *word)
{
	struct s_elem **elem;
	struct s_elem *new;
	int i = 0;

	elem = words->elems;
	new = (struct s_elem *)malloc(sizeof(struct s_elem));
	strcpy(new->word, word);
	new->occurence = 1;
	if (elem[0])
	{
		if ((findword(words->elems, word)) == 0)
		{
			while (elem[i])
				i++;
			elem[i] = new;
		}
		else
			free(new);
	}
	else
		words->elems[0] = new;
	return (i);
}

char **mostUsedWords(char *book)
{
	int i, j, n, m;
	char s[100];
	char **ret;
	struct s_list *words;

	ret = (char **)malloc(sizeof(char *) * 255);
	words = (struct s_list *)malloc(sizeof(struct s_list));
	words->elems = (struct s_elem **)malloc(sizeof(struct s_elem *) * 100000);
	words->len = 100000;
	for (i = 0; i < 100000; i++)
		words->elems[i] = NULL;
	i = 0;
	while (book[i])
	{
		j = 0;
		while (book[i] && !is_alpha(book[i]))
			i++;
		while (book[i + j] && is_alpha(book[i + j]) && j < 100)
		{
			s[j] = book[i + j];
			j++;
		}
		s[j] = '\0';
		i += j;
		m = 0;
		if (strlen(s) > 4)
			m = insert_word(words, s);
		if (m)
			n = m + 1;
	}
	sortwords(words);
	i = -1;
	while (++i < 255)
	{
		ret[i] = strdup(words->elems[i]->word);
		printf("count = %5d word = %.10s\n", words->elems[i]->occurence, words->elems[i]->word);
	}
	return (ret);
}
