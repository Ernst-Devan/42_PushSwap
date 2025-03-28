/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:35:10 by dernst            #+#    #+#             */
/*   Updated: 2025/03/28 10:39:13 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_limits(t_limits *limits)
{
	int	i;
	int	temp;

	temp = limits->borders[1];
	i = 1;
	while (i < limits->len - 1)
	{
		limits->borders[i] = limits->borders[i + 1];
		i++;
	}
	limits->borders[i] = temp;
}

void	calculate_border(t_limits *limits)
{
	int		range;
	int		i;

	range = limits->borders[1] - limits->borders[0];
	if (limits->mem_len - 1 == 0)
		limits->border_size = range / (limits->mem_len);
	else
		limits->border_size = range / (limits->mem_len - 1);
	i = 2;
	while (i < limits->mem_len)
	{
		limits->borders[i] = limits->borders[0]
			+ (limits->border_size * (i - 2));
		i++;
	}
	limits->len = i;
	sort_limits(limits);
}

void	find_limits(t_stack a, t_limits *limits)
{
	int		min;
	int		max;
	int		i;

	i = 0;
	max = a.st[0];
	min = a.st[0];
	while (i < (int)a.l)
	{
		if (a.st[i] > max)
			max = a.st[i];
		if (a.st[i] < min)
			min = a.st[i];
		i++;
	}
	limits->borders[0] = min;
	limits->borders[1] = max;
	calculate_border(limits);
}

size_t	nb_inside_limits(t_stack a, int *lim, int a_len)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < a.l)
	{
		if (((a.st[i] >= lim[0] && a.st[i] < lim[1] && a.st[i] < (a_len - 2))))
			count++;
		if (((a.st[i] >= lim[2] && a.st[i] < lim[3] && a.st[i] < (a_len - 2))))
			count++;
		i++;
	}
	return (count);
}
