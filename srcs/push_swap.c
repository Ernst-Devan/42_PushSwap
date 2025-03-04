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


// Don't forget to manage the error report for each function if a malloc failed for exemple or other potentiel error
// Check all malloc and set each one to NULL

#include <stdbool.h>
#include "push_swap.h"
#include "ft_printf.h"

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


int check_sorted(t_stack *a)
{
	size_t i;

	i = 0;
	while (i < a->len - 1)
	{
		if (a->stack[i] > a->stack[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	*push_swap(t_stack *a)
{ 
	t_stack	*b;
	int *stack_b;
	int count_action;
	int i;

	stack_b = malloc(a->len * sizeof(int));
	b = malloc(sizeof(t_stack));
	b->len = 0;
	b->stack = stack_b;
	i = 0;
	count_action = 0;
	
// Pre SORT
	count_action+= pre_sort(a, b);

// Final SORT
	return (a->stack);
}

int init(const int size, const char **start_argv)
{
	t_nb	*list_nb;
	t_stack	a;
	int		*stack_a;

	stack_a = parsing_check(start_argv, size);
	if (stack_a == NULL)
		return(2);
	a.len = size;
	a.stack = stack_a;
	list_nb = malloc(a.len * sizeof(t_nb));
	if (!list_nb)
		return (1);
	push_swap(&a);
	return (0);
}

int main(const int argc, const char **argv)
{
	int error;

	if (argc <= 1)
		return 0;
		
	error = init(argc-1, argv + 1);
	if (error == 2)
	{
		//!-! Need to write in error output we cant use ft_print we maybe need to use fd_write();
		ft_printf("Error\n");
		return (1);
	}
	else
		return (1);
	return (0);
}
