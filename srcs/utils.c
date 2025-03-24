/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:17:01 by dernst            #+#    #+#             */
/*   Updated: 2025/03/20 13:27:11 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static	int	check_overflow(int n, int sign, int last)
{
	if (n >= 214748364)
	{
		if (n > 214748364)
			return (1);
		else if (sign == -1 && last > 8)
			return (1);
		else if (sign == 1 && last > 7)
			return (1);
	}
	return (0);
}

int	ps_atoi(const char *nptr, int *overflow)
{
	size_t	i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		if (check_overflow(result, sign, nptr[i] - '0') == 1)
			*overflow = 1;
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	return (result * sign);
}
