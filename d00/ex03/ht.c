// typedef struct  s_art {
//   char *name;
//   int  price;
// }               t_art;

// typedef struct  s_item {
//   char           *key; //here the key will be the name
//   struct s_art   *value;
//   struct s_item  *next;
// }               t_item;

// typedef struct  s_dict {
//   struct s_item **items;
//   int           capacity; //the capacity of the array 'items'
// }               t_dict;

#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>


int hash(char *input)
{
	int i = 0;
	unsigned int h = 0;

	while (h < INT_MAX && input[i])
	{
		h <<= 8;
		h += input[i++];
	}
	return ((int)(h % INT_MAX));
}
//initialize the dictionnary, given as parameter the capacity of the array.
struct s_dict *dictInit(int capacity)
{
	t_dict *dict;

	if (capacity < 1 || !(dict = (t_dict *)malloc(sizeof(t_dict))))
		return NULL;
	if (!(dict->items = (t_item **)malloc(sizeof(t_item *) * capacity)))
		return NULL;
	for (int i = 0; i < capacity; i++)
		dict->items[i] = NULL;
	dict->capacity = capacity;
	return (dict);
}
//add one element in the dictionnary, if FAIL return 0, otherwise 1
int	dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	t_item	*new;
	t_item	*item;
	int 	h;

	if (!(new = (t_item *)malloc(sizeof(t_item))))
		return (0);
	new->key = key;
	new->value = value;
	new->next = NULL;
	h = hash(key) % dict->capacity;
	// printf("%d\n", h);
	if (!dict->items[h])
		dict->items[h] = new;
	else
	{
		item = dict->items[h];
		while (item)
		{
			if (!strcmp(key, item->key))
			{
				free(new);
				return (0);
			}
			item = item->next;
		}
		new->next = dict->items[h];
		dict->items[h] = new;
	}
	return (1);
}
//find one element in the dictionnary, if not found, return NULL
struct s_art *dictSearch(struct s_dict *dict, char *name)
{
	t_item *item = dict->items[hash(name) % dict->capacity];
	while (item && strcmp(item->key, name))
		item = item->next;
	if (!item)
		return (NULL);
	return (item->value);
}

int searchPrice(struct s_dict *dict, char *name)
{
	t_art *art = dictSearch(dict, name);
	if (!art)
		return (-1);
	return (art->price);
}















