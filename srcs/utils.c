/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:17:01 by dernst            #+#    #+#             */
/*   Updated: 2025/03/11 11:17:39 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	display_stack(t_stack a, t_stack b)
{
	size_t	i;

	i = 0;
	printf("\na: ");
	while (i < a.len)
	{
		printf("%d ", a.stack[i]);
		i++;
	}
	i = 0;
	printf("\nb: ");
	while (i < b.len)
	{
		printf("%d ", b.stack[i]);
		i++;
	}
	printf("\n");
}