/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:28:44 by dernst            #+#    #+#             */
/*   Updated: 2025/03/28 10:42:07 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	sa(t_stack *a)
{
	int	temp;

	ft_printf("sa\n");
	if (a->l > 1)
	{
		temp = a->st[0];
		a->st[0] = a->st[1];
		a->st[1] = temp;
	}
}

void	pa(t_stack *b, t_stack *a)
{
	int		i;
	size_t	j;

	ft_printf("pa\n");
	if (b->l >= 1)
	{
		i = a->l;
		i--;
		j = 0;
		while (i >= 0)
		{
			a->st[i + 1] = a->st[i];
			i--;
		}
		a->st[0] = b->st[0];
		while (j < b->l)
		{
			b->st[j] = b->st[j + 1];
			j++;
		}
		a->l += 1;
		b->l -= 1;
	}
}

void	ra(t_stack *a, size_t rr)
{
	size_t	i;
	int		temp;

	if (!rr)
		ft_printf("ra\n");
	if (a->l > 1)
	{
		i = 0;
		temp = a->st[0];
		while (i < a->l - 1)
		{
			a->st[i] = a->st[i + 1];
			i++;
		}
		a->st[a->l - 1] = temp;
	}
}

void	rra(t_stack *a, size_t rrr)
{
	int	i;
	int	temp;

	if (!rrr)
		ft_printf("rra\n");
	if (a->l > 1)
	{
		i = a->l - 1;
		temp = a->st[a->l - 1];
		while (i > 0)
		{
			a->st[i] = a->st[i - 1];
			i--;
		}
		a->st[0] = temp;
	}
}
