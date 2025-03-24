/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:50:04 by dernst            #+#    #+#             */
/*   Updated: 2025/03/19 09:51:32 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	sb(t_stack *b)
{
	int	temp;

	ft_printf("sb\n");
	if (b->l > 1)
	{
		temp = b->st[0];
		b->st[0] = b->st[1];
		b->st[1] = temp;
	}
}

void	pb(t_stack *a, t_stack *b)
{
	int		i;
	size_t	j;

	ft_printf("pb\n");
	if (a->l >= 1)
	{
		i = b->l;
		i--;
		j = 0;
		while (i >= 0)
		{
			b->st[i + 1] = b->st[i];
			i--;
		}
		b->st[0] = a->st[0];
		while (j < a->l - 1)
		{
			a->st[j] = a->st[j + 1];
			j++;
		}
		b->l += 1;
		a->l -= 1;
	}
}

void	rb(t_stack *b, size_t rr)
{
	size_t	i;
	int		temp;

	if (!rr)
		ft_printf("rb\n");
	if (b->l > 1)
	{
		i = 0;
		temp = b->st[0];
		while (i < b->l)
		{
			b->st[i] = b->st[i + 1];
			i++;
		}
		b->st[b->l - 1] = temp;
	}
}

void	rrb(t_stack *b, size_t rrr)
{
	int	i;
	int	temp;

	if (!rrr)
		ft_printf("rrb\n");
	if (b->l > 1)
	{
		i = b->l - 1;
		temp = b->st[b->l - 1];
		while (i > 0)
		{
			b->st[i] = b->st[i - 1];
			i--;
		}
		b->st[0] = temp;
	}
}
