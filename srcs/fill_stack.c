/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:19:59 by dernst            #+#    #+#             */
/*   Updated: 2025/03/20 13:23:28 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>

void	fill_stack(const int size, const char **start_argv)
{
	t_sort	list;
	t_stack	a;

	init_list(&list);
	if (init_stack(&a, size) == 1)
		exit_free(&a, NULL, 1);
	a.l = size;
	list.a = a;
	parsing_check(start_argv, &a);
	push_swap(&list);
}

size_t	find_next_min(t_stack *a, int last_min)
{
	size_t	i;
	size_t	index_min;

	i = 0;
	while (i < a->l)
	{
		if (a->st[i] != INT_MIN)
			index_min = i;
		i++;
	}
	i = 0;
	while (i < a->l)
	{
		if (a->st[i] > last_min && a->st[i] < a->st[index_min])
			index_min = i;
		i++;
	}
	return (index_min);
}

int	simplify(t_stack *a)
{
	int		*temp;
	int		last_min;
	size_t	i;
	size_t	index_min;

	temp = malloc(a->l * sizeof(int));
	if (!temp)
		return (1);
	i = 0;
	last_min = INT_MIN;
	index_min = 0;
	while (i < a->l)
	{
		index_min = find_next_min(a, last_min);
		temp[index_min] = i;
		last_min = a->st[index_min];
		a->st[index_min] = INT_MIN;
		i++;
	}
	free(a->st);
	a->st = temp;
	return (0);
}
