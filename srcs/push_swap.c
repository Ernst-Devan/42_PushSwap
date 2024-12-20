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


//Make the parsing to check duplicata and all my element is an int !

int	check_duplicata(int nb, int *array, int len)
{
	int	i;

	if (len > 0)
	{
		i = 0;
		while (i < len)
		{
			if (nb == array[i])
				return (1);
			i++;
		}
	}
	return (0);
}

int	parsing_check(char **args, int argc, int *stockage)
{
	int	i;
	size_t	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j < ft_strlen(args[i]))
		{
			if (ft_isdigit(args[i][j]) == 0 && args[i][j] != '-')
				return (1);
			j++;
		}
		stockage[i] = ft_atoi(args[i]);
		if (check_duplicata(ft_atoi(args[i]), stockage, i))
				return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int	*stack_a;
	t_stack		*a;

	stack_a = malloc((argc - 1) * sizeof(int));
	a = malloc(sizeof(t_stack));
	if (parsing_check(++argv, --argc, stack_a) == 1 || argc == 0)
	{
		ft_printf("ERROR : NUMBERS INPUTS");
		return (1);
	}


	a->len = argc;
	a->stack = stack_a;

	push_swap(a);
	free(a);
	return (0);
}
