/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:10:18 by dernst            #+#    #+#             */
/*   Updated: 2025/02/27 21:24:01 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	display_limits(t_limits limits)
{
	ft_printf("|%d-", limits.min);
	ft_printf("%d|", limits.border1);
	ft_printf("%d-", limits.border1);
	ft_printf("%d|", limits.border2);
	ft_printf("%d-", limits.border2);
	ft_printf("%d|", limits.border3);
	ft_printf("%d-", limits.border3);
	ft_printf("%d|", limits.max);
}
t_limits	find_limits(t_stack a)
{
	t_limits limits;
	int	i;

	init_limits(&limits);
	i = 0;
	limits.max = a.stack[0];
	limits.min = a.stack[0];
	while (i < a.len)
	{
		if (a.stack[i] > limits.max)
			limits.max = a.stack[i];
		if (a.stack[i] < limits.min)
			limits.min = a.stack[i];
		i++;
	}
	limits.border2 = limits.max / 2;
	limits.border1 = limits.border2 / 2;
	limits.border3 = limits.border1 + limits.border2;
	return (limits);
}

int	check_switch(t_stack *a, t_stack *b)
{
	int	count_action;

	count_action = 0;
	if (a->stack[0] > b->stack[0] || b->len <= 1)
	{
		pb(a, b, &count_action);
	}
	else
	{
		rb(b);
		pb(a, b, &count_action);
		rrb(b);
	}
	return (count_action);
}

int	nb_inside_limits(t_stack a, int limit1, int limit2)
{
	int	i;
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

int	parse_push_lim(t_stack *a, t_stack *b,int limit1, int limit2)
{
	int i;
	int	count_action;
	int len_a;
	int remaining;
	
	count_action = 0;
	i = 0;
	len_a = a->len;
	remaining = nb_inside_limits(*a, limit1, limit2);
	while (i < len_a && remaining > 0)
	{
		if (a->stack[0] >= limit1 && a->stack[0] < limit2)
		{
			pb(a,b,&count_action);
			remaining--;
		}
		else
			ra(a, &count_action);
		i++;
	}
	return (count_action);
}

int	pre_sort(t_stack *a, t_stack *b)
{
	int	count_action;
	
	count_action = 0;
	t_limits limits;
	limits = find_limits(*a);
	count_action += parse_push_lim(a, b, limits.min, limits.border1);
	count_action += parse_push_lim(a, b, limits.border1, limits.border2);
	count_action += parse_push_lim(a, b, limits.border2, limits.border3);
	count_action += parse_push_lim(a, b, limits.border3, limits.max);
	return (count_action);
}

