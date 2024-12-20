/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 02:22:11 by dernst            #+#    #+#             */
/*   Updated: 2024/12/20 02:26:47 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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