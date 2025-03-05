/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:10:18 by dernst            #+#    #+#             */
/*   Updated: 2025/03/05 13:46:14 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <math.h>

void	display_limits(t_limits limits)
{
	size_t	i;

	i = 0;
	while (i < limits.mem_len)
	{
		ft_printf("|%d|", limits.borders[i]);
		i++;
	}
}

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
	int	border_size;
	size_t	i;

	range = limits->borders[1] - limits->borders[0];
	border_size = range / (limits->mem_len - 1);
	i = 2;
	while(i < limits->mem_len)
	{
		limits->borders[i] = limits->borders[0] + (border_size * (i - 1));
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

int	nb_inside_limits(t_stack a, int limit1, int limit2)
{
	size_t	i;
	int count;
	
	i = 0;
	count = 0;
	while (i < a.len)
	{
		if (a.stack[i] >= limit1 && a.stack[i] < limit2)
			count++;
		i++;
	}
	return (count);
}

int	parse_push_lim(t_stack *a, t_stack *b,int limit1, int limit2, int limit3, int limit4)
{
//	ft_printf("\nlimits1:%d\n", limit1);
//	ft_printf("limits2:%d\n", limit2);
//	ft_printf("limits3:%d\n", limit3);
//	ft_printf("limits4:%d\n", limit4);
	size_t i;
	int	count_action;
	size_t len_a;
	int remaining;

	count_action = 0;
	i = 0;
	len_a = a->len;
	remaining = nb_inside_limits(*a, limit1, limit2) + nb_inside_limits(*a, limit3, limit4);
	while (i < len_a && remaining > 0)
	{
		if (a->stack[0] >= limit1 && a->stack[0] < limit2)
		{
			pb(a, b, &count_action);
			remaining--;
		}
		else if (a->stack[0] >= limit3 && a->stack[0] < limit4)
		{
			pb(a,b,&count_action);
			rb(b, &count_action);
			remaining--;
		}
		else
			ra(a, &count_action);
		i++;
	}
	return (count_action);
}

//! Need to start to the middle of the limits int* to go more in more near of the end and the start of the list
//! Two case if limits->mem_len is even(pair) or odd(impair)
//! If we use rb and ra also make a rr
//! Sort better the presort
//! Start to do the sort algo
int	pre_sort(t_stack *a, t_stack *b)
{
	int	count_action;
	t_limits limits;
	int	i;
	size_t	j;

	count_action = 0;
	limits = init_limits(sqrt(a->len + 2) + 2); //! Math library not allowed
	i = (limits.mem_len / 2) - 1;
	j = i + 1;
	find_limits(*a, &limits);
	while(i >= 0)
	{
		if (!(limits.mem_len % 2) && i == 0)
			count_action += parse_push_lim(a, b, limits.borders[0], limits.borders[1], limits.borders[0], limits.borders[0]);
		else
			count_action += parse_push_lim(a, b, limits.borders[i], limits.borders[i + 1], limits.borders[j], limits.borders[j + 1]);
		i--;
		j++;
	}
	return (count_action);
}