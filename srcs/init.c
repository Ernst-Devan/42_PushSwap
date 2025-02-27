/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:53:12 by dernst            #+#    #+#             */
/*   Updated: 2025/02/27 14:54:12 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	init_limits(t_limits *limits)
{
	limits->border1 = 0;
	limits->border2 = 0;
	limits->max = 0;
	limits->min = 0;
}