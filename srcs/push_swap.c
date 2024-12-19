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

	display_stack(a, b);
	return (a->stack);
}


//Make the parsing to check duplicata and all my element is an int !
int	parsing_check(char **args)
{
	
	//while (i < ft_strlen(array))
	//{
		//if (is_number(args[0]) == 0)
		//i++;
	//}
	int	i;

	i = 0;
	while (i < 10)
	{
		printf("%c", *args[i]);
		i++;
	}
	(void)args;
	return (0);
}


//void	fill_stack(char *array)
//{

//}

int main(int argc, char **argv)
{
	//t_stack		*a;

	(void)argc;
	//a = malloc(sizeof(t_stack));
	parsing_check(++argv);
	//int	stack_a[10] = {0,1,2,3,4,5,6,7,8,9};


	//a->len = 10;
	//a->stack = stack_a;

	//push_swap(a);
	//free(a);
	return (0);
}
