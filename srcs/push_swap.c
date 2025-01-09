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
	int	i;

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


int find_index_nb(t_stack *a, t_nb *list_nb, int number_to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < a->len)
	{
		while (list_nb[j].nb != number_to_find && j < a->len)
			j++;
		if (list_nb[j].nb == number_to_find)
			return (j);
		i++;
	}
	return (-1);
}

int check_sorted(t_stack *a)
{
	int i;

	i = 0;
	while (i < a->len - 1)
	{
		if (a->stack[i] > a->stack[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	*push_swap(t_stack *a, t_nb *list_nb)
{ 
	t_stack	*b;
	int *stack_b;
	int count_action;
	stack_b = malloc(a->len * sizeof(int));

	b = malloc(sizeof(t_stack));
	b->len = 0;
	b->stack = stack_b;

	size_t i;
	count_action = 0;
	
	int j;
	int b_len;

	i = 0;
	j = 0;
	while (check_sorted(a) != 0)
	{
		check_bytes(list_nb, a, b, i, &count_action);
		b_len = b->len;
		merge_stack(a,b, &count_action);
		while (j < b_len)
		{
			ra(a, &count_action);
			j++;
		}
		i++;
		j = 0;
		display_stack(*a,*b);
	}
	printf(" ACTION :%d", count_action);
	return (a->stack);
}

// Divide the list of int by bucket and sort each bucket with radix
// To define the number of bucket we use this relation Range = (maximum-minimum) / number of elements


// Lenght max represent the lenght of the bigger number in decimal values so we have a probleme cause we need the function to swap it into binary base 
// If a negative number is present the lenght_max is 32
// If the lenght is 32 inside the list they have a negative number it's sure



// !-! Free each malloc one by one cause the function binarry make one malloc for each numbers of the list

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
	insert_list_binaries(list_nb, a);
	push_swap(&a, list_nb);
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
