/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:59:32 by dernst            #+#    #+#             */
/*   Updated: 2025/03/14 13:59:57 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

size_t bottom_sort(t_stack *a, t_stack *b, int *temp, int *cost)
{
	size_t	count_action;

	count_action = 0;
	if	(b->stack[0] > *temp && b->stack[0] != a->stack[0] - 1)
	{
		*temp = b->stack[0];
		pa(b, a, &count_action);
		ra(a, &count_action, 0);
		*cost -= 1;
	}
	return (count_action);
}

int	check_rrb(t_stack *b, int nb)
{
	size_t	i;
	int	cost;

	i = b->len;
	cost = 0;
	while (i > 0)
	{
		if(b->stack[i] == nb)
			return(cost);
		cost++;
		i--;
	}
	return (0);
}

//Eco instruction with rr when we use bottom_sort and cost != 0

size_t	push_best(t_stack *b, t_stack *a, int cost, size_t rotate, int	*temp_reverse)
{
	size_t	count_action;
	
	count_action = 0;
	if (rotate == 0)
	{
		while (cost > 0)
		{
			count_action += bottom_sort(a, b, temp_reverse, &cost);
			rb(b, &count_action, 0);
			cost--;
		}
	}
	else
	{
		while(cost > 0)
		{
			count_action += bottom_sort(a, b, temp_reverse, &cost);
			rrb(b, &count_action, 0);
			cost--;
		}
	}
	if (b->stack[0] == a->stack[0] - 1)
		pa(b, a, &count_action);
	return (count_action);
}

size_t find_next(t_stack *a, t_stack *b, int *temp_reverse)
{
	size_t	i;
	int		temp;
	size_t	count_action;
	int cost1;
	int	cost2;

	i = 0;
	cost1 = 0;
	count_action = 0;
	temp = b->stack[0];
	if (a->stack[a->len - 1] == a->stack[0] - 1)
	{
		rra(a, &count_action, 0);
		if (a->stack[a->len - 1] == (int)((a->len + b->len) - 1))
			*temp_reverse = 0;
		else
			*temp_reverse = a->stack[a->len - 1];
	}
	else
	{
		while (i < b->len)	//! Modify by the remaining size of limits or
		{
			if (b->stack[i] == a->stack[0] - 1)
			{
				temp = b->stack[i];
				cost1 = i;
				break;
			}
			i++;
		}
		cost2 = check_rrb(b, temp);
		if (cost1 < cost2)
			count_action += push_best(b, a, cost1, 0, temp_reverse);
		else
			count_action += push_best(b, a, cost2, 1, temp_reverse);
	}
	return (count_action);
}


size_t	sort(t_stack *a, t_stack *b)
{
	size_t	count_action;
	int	temp_reverse;

	
	temp_reverse = 0;
	count_action = 0;
	while (b->len > 0)
	{
		count_action += find_next(a, b, &temp_reverse);
	}
	return (count_action);
}