/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 02:22:11 by dernst            #+#    #+#             */
/*   Updated: 2025/03/05 17:07:59 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <libft.h>
#include <stdbool.h>

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

void parsing_check(const char **numbers, t_stack *a)
{
	size_t	i;

	i = 0;
	while (i < a->len)
	{
		if (!is_str_number(numbers[i]))
		{
			free(a->stack);
			return;
		}
		a->stack[i] = ft_atoi(numbers[i]);
		if (check_duplicata(a->stack[i], a->stack, i))
		{
			free(a->stack);
			return;
		}
		i++;
	}
}