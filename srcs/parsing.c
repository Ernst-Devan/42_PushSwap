/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 02:22:11 by dernst            #+#    #+#             */
/*   Updated: 2025/01/04 16:12:28 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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