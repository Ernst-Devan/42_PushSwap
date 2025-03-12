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
//! If the args contain less than 5 number instruction not print inside the console i dont know why
//! Check no problem with 0 / 1 / 2  if 0 or 1 or chained already sorted do anything
//! Well read the mandatory part

#include <stdbool.h>
#include "push_swap.h"
#include "ft_printf.h"


size_t	find_next_min(t_stack *a, int last_min)
{
	size_t	i;
	size_t	index_min;


	i = 0;
	index_min = 0;
	while (i < a->len)
	{
		if (a->stack[i] > last_min)
			index_min = i;
		i++;
	}
	return (index_min);
}

void	simplify(t_stack *a)
{
	int		*temp;
	size_t	i;
	size_t	j;
	int		last_min;
	size_t	index_min;

	temp = malloc(a->len * sizeof(int));
	i = 0;
	j = 0;
	last_min = INT_MIN;
	index_min = 0;
	while (i < a->len)
	{
		while (j < a->len)
		{
			if (a->stack[j] < a->stack[index_min] && a->stack[j] > last_min)
				index_min = j;
			j++;
		}
		j = 0;
		temp[index_min] = i;
		last_min = a->stack[index_min];
		index_min = find_next_min(a, last_min);
		i++;
	}
	free(a->stack);
	a->stack = temp;
}
int	*push_swap(t_stack *a)
{ 
	t_stack	b;
	int i;
	size_t count_action;

	b = init_stack(a->len);
	i = 0;
	count_action = 0;
	
	simplify(a);
// Pre SORT
	count_action += pre_sort(a, &b);

// Final SORT
	count_action += sort(a, &b);

	return (a->stack);
}

int init(const int size, const char **start_argv)
{
	t_stack	a;

	a = init_stack(size);
	a.len = size;

	parsing_check(start_argv, &a);
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
