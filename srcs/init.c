/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:53:12 by dernst            #+#    #+#             */
/*   Updated: 2025/03/28 10:47:56 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_list(t_sort *list)
{
	list->a.l = 0;
	list->a.st = NULL;
	list->b.l = 0;
	list->b.st = NULL;
}

int	init_stack(t_stack *stack, size_t len)
{
	int	*number;

	(void)len;
	number = malloc (len * sizeof(int));
	stack->st = number;
	if (!number)
		return (1);
	stack->l = 0;
	return (0);
}

int	init_limits(t_sort *list, t_limits *lim, int len)
{
	if (len < 0)
		len = 0;
	lim->mem_len = len;
	lim->len = 0;
	lim->borders = malloc(len * sizeof(lim->borders));
	if (!lim->borders)
		exit_free(&list->a, &list->b, 0);
	return (0);
}
