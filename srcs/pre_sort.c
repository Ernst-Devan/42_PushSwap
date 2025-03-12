/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:10:18 by dernst            #+#    #+#             */
/*   Updated: 2025/03/11 13:36:53 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>
#include "push_swap.h"

void	three_sorting(t_stack *a, int len)
{
	size_t	count_action;

	count_action = 0;
	
	if (a->stack[1] == (len - 2) && a->stack[0] == (len - 0))
	{
		rra(a ,&count_action, 0);
		rra(a ,&count_action, 0);
	}
	else if (a->stack[1] == (len - 2) && a->stack[2] == (len - 0))
		sa(a, &count_action);
	else if ((a->stack[0] == (len - 0) && a->stack[1] == (len - 1)) && a->stack[2] == (len - 2))
	{
		ra(a, &count_action, 0);
		sa(a, &count_action);
	}
	else if (a->stack[0] == (len - 2) && a->stack[1] == (len - 0))
	{
		sa(a, &count_action);
		ra(a, &count_action, 0);
	}
	else if ((a->stack [1] == (len - 2) && a->stack[2] == (len - 1)))
	{
		sa(a, &count_action);
		rra(a, &count_action, 0);
	}
	else if ((a->stack[2] == (len - 2) || (a->stack[1] == len - 1 && a->stack[0] == len)))
		rra(a ,&count_action, 0);
}

size_t	parse_push_lim(t_stack *a, t_stack *b,int limit1, int limit2, int limit3, int limit4)
{
	size_t	i;
	size_t	count_action;
	int		remaining;
	int		a_temp;

	a_temp = a->len + b->len;
	i = 0;
	count_action = 0;
	remaining = nb_inside_limits(*a, limit1, limit2, a_temp) + nb_inside_limits(*a, limit3, limit4, a_temp);
	while (remaining > 0 && a->len > 3)
	{
		if (a->stack[0] >= a_temp - 3)
		{
			ra(a, &count_action, 0);
		}
		else if (a->stack[0] >= limit1 && a->stack[0] < limit2)
		{
			pb(a, b, &count_action);
			remaining--;
		}
		else if (a->stack[0] >= limit3 && a->stack[0] < limit4)
		{
			pb(a,b,&count_action);
			rb(b, &count_action, 0);
			remaining--;
		}
		else
			ra(a, &count_action, 0);
		i++;
	}
	i = 0;
	return (count_action);
}

size_t	pre_sort(t_stack *a, t_stack *b)
{
	t_limits	limits;
	size_t		count_action;
	int			j;
	int			i;

	limits = init_limits(sqrt(a->len + 2) + 2); //! Math library not allowed
	count_action = 0;
	i = (limits.mem_len / 2) - 1;
	j = i + 1;
	find_limits(*a, &limits);
	while(i >= 0)
	{
		if (!(limits.mem_len % 2) && i == 0)
			count_action += parse_push_lim(a, b, limits.borders[0], limits.borders[0], limits.borders[0], limits.borders[1]);
		else
			count_action += parse_push_lim(a, b, limits.borders[j], limits.borders[j + 1], limits.borders[i], limits.borders[i + 1]);
		i--;
		j++;
	}
	three_sorting(a, (int)(a->len + b->len - 1));
	return (count_action);
}