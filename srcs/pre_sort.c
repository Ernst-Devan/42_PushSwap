/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:10:18 by dernst            #+#    #+#             */
/*   Updated: 2025/03/20 13:26:13 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	three_sorting(t_stack *a, int len)
{
	if ((a->st[1] == len - 1 && a->st[0] == len))
		sa(a);
	if (len >= 2)
	{
		if (a->st[1] == len - 2 && a->st[2] == len)
			sa(a);
		if (a->st[1] == len - 2 && a->st[0] == len)
		{
			rra(a, 0);
			rra(a, 0);
		}
		if (a->st[0] == len - 2 && a->st[1] == len)
		{
			sa(a);
			ra(a, 0);
		}
		if (a->st[2] == (len - 2) && a->st[1] == len)
			rra(a, 0);
		if ((a->st [1] == (len - 2) && a->st[2] == (len - 1)))
		{
			sa(a);
			rra(a, 0);
		}
	}
}

void	parse_push_lim(t_sort *list, int *lim)
{
	int		a_temp;
	int		remaining;

	a_temp = list->a.l + list->b.l;
	remaining = nb_inside_limits(list->a, lim, a_temp);
	while (remaining > 0 && list->a.l > 3)
	{
		if (list->a.st[0] >= a_temp - 3)
			ra(&list->a, 0);
		else if (list->a.st[0] >= lim[0] && list->a.st[0] < lim[1])
		{
			pb(&list->a, &list->b);
			remaining--;
		}
		else if (list->a.st[0] >= lim[2] && list->a.st[0] < lim[3])
		{
			pb(&list->a, &list->b);
			rb(&list->b, 0);
			remaining--;
		}
		else
			ra(&list->a, 0);
	}
	free(lim);
}

int	*fill_lim(t_limits limits, t_sort *list, int j, int i)
{
	int	*lim;

	lim = malloc(4 * sizeof(int));
	if (!lim)
	{
		free(limits.borders);
		exit_free(&list->a, &list->b, 1);
	}
	if (!(limits.len % 2) && i == 0)
	{
		lim[0] = limits.borders[0];
		lim[1] = limits.borders[0];
		lim[2] = limits.borders[0];
		lim[3] = limits.borders[1];
	}
	else
	{
		lim[0] = limits.borders[j];
		lim[1] = limits.borders[j + 1];
		lim[2] = limits.borders[i];
		lim[3] = limits.borders[i + 1];
	}
	return (lim);
}

void	pre_sort(t_sort *list)
{
	t_limits	limits;
	int			j;
	int			i;

	if (list->a.l < 10)
		init_limits(&limits, ft_sqrt(list->a.l));
	else
		init_limits(&limits, ft_sqrt(list->a.l) - 2);
	if (limits.mem_len != 0)
	{
		find_limits(list->a, &limits);
		i = (limits.len / 2) - 1;
		j = i + 1;
		while (i >= 0)
		{
			if (!(limits.len % 2) && i == 0)
				parse_push_lim(list, fill_lim(limits, list, j, i));
			else
				parse_push_lim(list, fill_lim(limits, list, j, i));
			i--;
			j++;
		}
	}
	three_sorting(&list->a, (int)(list->a.l + list->b.l) - 1);
	free(limits.borders);
}
