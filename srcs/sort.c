/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:59:32 by dernst            #+#    #+#             */
/*   Updated: 2025/03/28 10:38:16 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bottom_sort(t_stack *a, t_stack *b, int *temp, int *cost)
{
	if (a->st[a->l - 1] == (int)((a->l + b->l) - 1))
		*temp = 0;
	else
		*temp = a->st[a->l - 1];
	if (b->st[0] > *temp && b->st[0] != a->st[0] - 1)
	{
		*temp = b->st[0];
		pa(b, a);
		ra(a, 0);
		*cost -= 1;
	}
}

int	check_rrb(t_stack *b, int nb)
{
	int	i;
	int	cost;

	i = b->l - 1;
	cost = 1;
	while (i > 0)
	{
		if (b->st[i] == nb)
			return (cost);
		cost++;
		i--;
	}
	return (cost);
}

void	push_best(t_sort *list, int cost, size_t rotate, int	*temp_reverse)
{
	if (rotate == 0)
	{
		while (cost > 0)
		{
			bottom_sort(&list->a, &list->b, temp_reverse, &cost);
			rb(&list->b, 0);
			cost--;
		}
	}
	else
	{
		while (cost > 0)
		{
			bottom_sort(&list->a, &list->b, temp_reverse, &cost);
			rrb(&list->b, 0);
			cost--;
		}
	}
	if (list->b.st[0] == list->a.st[0] - 1)
		pa(&list->b, &list->a);
}

void	find_next(t_sort *list, int *temp_reverse)
{
	int		cost1;
	int		temp;
	int		cost2;

	cost1 = 0;
	temp = list->b.st[0];
	if (list->a.st[list->a.l - 1] == list->a.st[0] - 1)
		rra(&list->a, 0);
	else
	{
		while ((size_t)cost1 < list->b.l)
		{
			if (list->b.st[cost1] == list->a.st[0] - 1)
				break ;
			cost1++;
		}
		temp = list->b.st[cost1];
		cost2 = check_rrb(&list->b, temp);
		if (cost1 < cost2)
			push_best(list, cost1, 0, temp_reverse);
		else
			push_best(list, cost2, 1, temp_reverse);
	}
}

void	sort(t_sort *list)
{
	int		temp_reverse;

	temp_reverse = 0;
	while (list->b.l > 0)
		find_next(list, &temp_reverse);
}
