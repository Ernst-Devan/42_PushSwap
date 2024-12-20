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

int	check_duplicata(int nb, int *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (nb == array[i])
			return (1);
		i++;
	}
	return (0);
}

bool is_str_number(const char* str)
{
	if (*str == '\0')
		return (false);
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

int	*parsing_check(const char **numbers, const int size)
{
	int		*result;
	int		i;

	result = malloc(size * sizeof(*result));
	i = 0;
	while (i < size)
	{
		if (!is_str_number(numbers[i]))
		{
			free(result);
			return (NULL);
		}
		result[i] = ft_atoi(numbers[i]);
		if (check_duplicata(result[i], result, i))
		{
			free(result);
			return (NULL);
		}
		i++;
	}
	return (result);
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