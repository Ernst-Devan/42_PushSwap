/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:52:16 by dernst            #+#    #+#             */
/*   Updated: 2025/03/28 10:39:06 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ss(t_stack *a, t_stack *b)
{
	ft_printf("ss\n");
	sa(a);
	sb(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ft_printf("rr\n");
	ra(a, 1);
	rb(b, 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_printf("rrr\n");
	rra(a, 1);
	rrb(b, 1);
}
