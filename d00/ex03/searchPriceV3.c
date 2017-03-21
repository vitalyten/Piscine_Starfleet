/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:27:21 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/21 00:05:16 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>

// struct  s_art {
//   char *name;
//   int  price;
// };

// struct s_item {
//   char           *key; //here the key will be the name
//   struct s_art   *value;
//   struct s_item  *next;
// };

// struct s_dict {
//   struct s_item **items;
//   int           capacity; //the capacity of the array 'items'
// };

int hash(char *input) //return hash result
{
	unsigned long long	h;
	unsigned char	*us;

	us = (unsigned char *)input;
	h = 0;
	while (*us != '\0')
	{
		h = (h * 37 + *us) % 2147483647;
		us++;
	}
	return ((int)h);
}

struct s_dict *dictInit(int capacity) //initialize the dictionnary, given as parameter the capacity of the array.
{
	struct s_dict *hashtable = NULL;
	int i;

	if (capacity < 1)
		return (NULL);
	if ((hashtable = (struct s_dict *)malloc(sizeof(struct s_dict))) == NULL)
		return (NULL);
	if ((hashtable->items = (struct s_item **)malloc(sizeof(struct s_item *) * capacity)) == NULL)
		return (NULL);
	for (i = 0; i < capacity; i++)
		hashtable->items[i] = NULL;
	hashtable->capacity = capacity;
	return (hashtable);
}

int	dictInsert(struct s_dict *dict, char *key, struct s_art *value) //add one element in the dictionnary, if FAIL return 0, otherwise 1
{
	int bin = 0;
	struct s_item *newpair = NULL;
	struct s_item *next = NULL;
	struct s_item *last = NULL;

	bin = hash(key);
	next = dict->items[bin];
	while (next != NULL && next->key != NULL && strcmp(key, next->key) > 0)
	{
		last = next;
		next = next->next;
	}
	if (next != NULL && next->key != NULL && strcmp(key, next->key) == 0)
	{
		// free(next->value);
		next->value = value;
	}
	else
	{
		if ((newpair = (struct s_item *)malloc(sizeof(struct s_item))) == NULL)
			return (0);
		newpair->key = strdup(key);
		newpair->value = value;
		newpair->next = NULL;
		if (next == dict->items[bin])
		{
			newpair->next = next;
			dict->items[bin] = newpair;
		}
		else if (next == NULL)
		{
			last->next = newpair;
		}
		else
		{
			newpair->next = next;
			last->next = newpair;
		}
	}
	return (1);
}

struct s_art *dictSearch(struct s_dict *dict, char *name) //find one element in the dictionnary, if not found, return NULL
{
	int bin = 0;
	struct s_item *pair;

	bin = hash(name);
	pair = dict->items[bin];
	while (pair != NULL && pair->key != NULL && strcmp(name, pair->key) > 0)
		pair = pair->next;
	if (pair == NULL || pair->key == NULL || strcmp(name, pair->key) != 0)
		return (NULL);
	else
		return (pair->value);
}
// OTHER

int searchPrice(struct s_dict *dict, char *name)
{
	struct s_art *item;

	item = dictSearch(dict, name);
	if (item)
		return (item->price);
	return (-1);
}
