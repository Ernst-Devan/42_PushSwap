/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:48:07 by dernst            #+#    #+#             */ 
/*   Updated: 2024/12/16 20:44:49 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "push_swap.h"
#include "ft_printf.h"

void	display_stack(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	printf("\na: ");
	while (i < a->len)
	{
		printf("%d ", a->stack[i]);
		i++;
	}
	i = 0;
	printf("\nb: ");
	while (i < b->len)
	{
		printf("%d ", b->stack[i]);
		i++;
	}
	printf("\n");
}

int	*push_swap(t_stack *a)
{
	t_stack	*b;
	int *stack_b;
	stack_b = malloc(a->len * sizeof(int));

	b = malloc(sizeof(t_stack));
	b->len = 0;
	b->stack = stack_b;

	display_stack(a, b);
	return (a->stack);
}




int main(const int argc, const char **argv)
{
	int			*stack_a;
	t_stack		a;
	const int	size = argc - 1;

	if (argc <= 1)
		return 0;
	stack_a = parsing_check(argv + 1, size);
	if (stack_a == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	a.len = size;
	a.stack = stack_a;
	push_swap(&a);

	return (0);
}