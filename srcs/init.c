/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:53:12 by dernst            #+#    #+#             */
/*   Updated: 2025/03/05 15:27:23 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_stack		init_stack(size_t len)
{
	t_stack	stacks;
	int *number;

	number  = malloc (len * sizeof(int));
	stacks.len = 0;
	stacks.stack = number;
	return (stacks);
}

t_limits	init_limits(size_t len)
{
	t_limits limits;
	limits.mem_len = len;
	limits.len = 0;
	limits.borders = malloc(len * sizeof(limits.borders)); 
	if (!limits.borders)
		exit(1);
	return (limits);
}