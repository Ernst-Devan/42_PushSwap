/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:48:07 by dernst            #+#    #+#             */
/*   Updated: 2025/03/28 10:38:22 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted_input(t_stack *a)
{
	size_t	i;

	i = 0;
	while (i < a->l - 1)
	{
		if (a->st[i] > a->st[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	push_swap(t_sort *list)
{
	t_stack	b;

	if (check_sorted_input(&list->a) == 1)
		exit_free(&list->a, &list->b, 0);
	if (init_stack(&b, list->a.l) == 1)
		exit_free(&list->a, &list->b, 0);
	list->b = b;
	if (simplify(&list->a) == 1)
		exit_free(&list->a, &list->b, 0);
	pre_sort(list);
	sort(list);
	exit_free(&list->a, &list->b, 0);
}

int	main(const int argc, const char **argv)
{
	if (argc <= 1)
		return (1);
	fill_stack(argc - 1, argv + 1);
	return (0);
}
