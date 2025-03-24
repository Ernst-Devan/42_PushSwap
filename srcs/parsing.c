/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 02:22:11 by dernst            #+#    #+#             */
/*   Updated: 2025/03/20 13:26:04 by dernst           ###   ########lyon.fr   */
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

bool	is_str_number(const char *str)
{
	if (*str == '\0')
		return (false);
	if (*str == '-' || (*str == '+'))
		str++;
	if (*str == '\0')
		return (false);
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

void	parsing_check(const char **numbers, t_stack *a)
{
	size_t	i;
	int		overflow;

	i = 0;
	overflow = 0;
	while (i < a->l)
	{
		a->st[i] = ps_atoi(numbers[i], &overflow);
		if (!is_str_number(numbers[i]))
			exit_free(a, NULL, 1);
		if (overflow == 1)
			exit_free(a, NULL, 1);
		if (check_duplicata(a->st[i], a->st, i) == 1)
			exit_free(a, NULL, 1);
		i++;
	}
}
