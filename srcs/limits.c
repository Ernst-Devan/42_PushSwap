/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:35:10 by dernst            #+#    #+#             */
/*   Updated: 2025/03/11 11:17:35 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void sort_limits(t_limits *limits)
{
	size_t	i;
	int	temp;
	
	temp = limits->borders[1];
	i = 1;
	while (i < limits->mem_len - 1)
	{
		limits->borders[i] = limits->borders[i + 1];
		i++;
	}
	limits->borders[i] = temp;
}

void	calculate_border(t_limits *limits)
{
	int	range;
	size_t	i;

	range = limits->borders[1] - limits->borders[0];
	limits->border_size = range / (limits->mem_len - 1);
	i = 2;
	while(i < limits->mem_len)
	{
		limits->borders[i] = limits->borders[0] + (limits->border_size * (i - 2));
		i++;
	}
	sort_limits(limits);
}
void	find_limits(t_stack a, t_limits *limits)
{
	int	min;
	int max;
	size_t	i;

	i = 0;
	max = a.stack[0];
	min = a.stack[0];
	while (i < a.len)
	{
		if (a.stack[i] > max)
			max = a.stack[i];
		if (a.stack[i] < min)
			min = a.stack[i];
		i++;
	}
	limits->borders[0] = min;
	limits->borders[1] = max;
	limits->len = 2;
	calculate_border(limits);
}

size_t	nb_inside_limits(t_stack a, int limit1, int limit2, int a_len)
{
	size_t	i;
	size_t	count;
	
	i = 0;
	count = 0;
	while (i < a.len)
	{
		if (((a.stack[i] >= limit1 && a.stack[i] < limit2) && a.stack[i] < (a_len - 2)))
			count++;
		i++;
	}
	return (count);
}