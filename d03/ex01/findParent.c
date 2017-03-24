/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:34:40 by vtenigin          #+#    #+#             */
/*   Updated: 2017/03/23 20:37:36 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

int	checksp(t_node *root, char *sp)
{
	int r;
	int i;

	r = 0;
	i = -1;
	if (root == NULL)
		return (0);
	if (!strcmp(root->name, sp))
		return (1);
	if (root->children)
		while (root->children[++i])
			if (checksp(root->children[i], sp))
				return (1);
	return (0);
}

t_node	*findrec(t_node *root, char *sp1, char *sp2)
{
	t_node *tmp;
	t_node *r;
	int i;
	int n;

	tmp = NULL;
	r = NULL;
	if (root == NULL)
		return (NULL);
	n = 0;
	if (!strcmp(root->name, sp1) || !strcmp(root->name, sp2))
		return root;
	if (root->children)
	{
		i = -1;
		while (root->children[++i])
		{
			r = findrec(root->children[i], sp1, sp2);
			if (r)
			{
				n++;
				tmp = r;
			}
		}
	}
	if (n == 2)
		return (root);
	return (tmp);
}

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	if (checksp(root, firstSpecies) && checksp(root, secondSpecies))
		return (findrec(root, firstSpecies, secondSpecies));
	return (NULL);
}














