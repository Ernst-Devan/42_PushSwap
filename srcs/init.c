/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:53:12 by dernst            #+#    #+#             */
/*   Updated: 2025/03/03 21:34:47 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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