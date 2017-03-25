/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   understand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:20:11 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/24 23:06:26 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// typedef struct  s_node {
// 	char		    c;
// 	unsigned int	isWord:1;
// 	struct s_node	**child;
// }               t_node;

// typedef struct  s_trie {
// 	struct s_node *node;
// }               t_trie;

char *lookup(t_node *node, char *word, char *ret, int i)
{
	int j;

	puts(ret);
	if (!node)
		return (NULL);
	if (!word[i])
	{
		if (node->isWord)
			return (ret);
		return (NULL);
	}


	j = -1;
	if (word[i] == '?')
	{
		while (node->child[++j])
		{
			char *w;
			ret[i] = node->child[j]->c;
			if (word[i + 1] == '\0')
				return (ret);
			if ((w = lookup(node->child[j], word, ret, i + 1)))
				return (w);
			// ret[i] = '?';
		}
	}
	else
		while (node->child[++j])
			if (node->child[j]->c == word[i])
				return (lookup(node->child[j], word, ret, i + 1));
	return (NULL);
}

char *understand(char *word, struct s_trie *trie)
{
	char *ret;

	ret = strdup(word);
	return (lookup(trie->node, word, ret, 0));
}

t_node *makenode(char c, unsigned int isw)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->c = c;
	node->isWord = isw;
	node->child = NULL;
	return (node);
}

void	printtrie(t_node *node)
{
	// puts("test");
	if (node && node->c)
	{
		putchar(node->c);
		if (node->isWord)
			printf(" ");
		// printf("%d", node->isWord);
	}
	if (node->child)
		while (*(node->child))
		{
			printtrie(*(node->child));
			node->child++;
		}
}

struct s_trie *createTrie(char **dictionary)
{
	t_trie			*trie;
	t_node			*node;
	t_node			**nodes;
	int				i;
	int				j;
	unsigned int	isw;
	char			*word;

	trie = (t_trie *)malloc(sizeof(t_trie));
	trie->node = makenode(0, 0);
	while (*dictionary)
	{
		isw = 0;
		node = trie->node;
		word = *dictionary;
		j = -1;
		while (word[++j])
		{
			if (word[j + 1] == '\0')
				isw = 1;
			if (node->child)
			{
				nodes = node->child;
				i = -1;
				while (nodes[++i])
				{
					if (nodes[i]->c == word[j])
					{
						node = nodes[i];
						if (isw)
							nodes[i]->isWord = 1;
						break;
					}
				}
				if (nodes[i] == NULL)
				{
					node->child = (t_node **)realloc(node->child, (sizeof(t_node) * (i + 2)));
					node->child[i] = makenode(word[j], isw);
					node->child[i + 1] = NULL;
					node = node->child[i];
				}
			}
			else
			{
				node->child = (t_node **)malloc(sizeof(t_node) * 2);
				node->child[0] = makenode(word[j], isw);
				node->child[1] = NULL;
				node = node->child[0];
			}
		}
		dictionary++;
	}
	// printtrie(trie->node);
	return (trie);
}




