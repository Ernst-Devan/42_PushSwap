/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:16:48 by dernst            #+#    #+#             */
/*   Updated: 2025/01/07 22:44:35 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

char	*reverse_str(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(str) - 1;

	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}
char	*to_binary(int number)
{
	char	*binary;
	int		i;  

	binary = malloc(32 + 1);
	if (!binary)
		return(NULL);
	i = 0;
	while (number != 0)
	{
		binary[i] = (number % 2) + '0';
		number /= 2;
		i++;
	}
	binary[i] = '\0';
	binary = reverse_str(binary);
 	return (binary);
}

// Free all the binary number one by one

int cleanup(t_nb **list_nb, int i)
{
	if (!list_nb)
	{
		while (i > 0)
		{
			free(list_nb[i]->binary);
			i--;
		}
	}
	list_nb = NULL;
	return (0);
}

int insert_list_binaries(t_nb *list_nb, t_stack a)
{
	int		i;

	i = 0;
	while (i < a.len)
	{
		list_nb[i].nb = a.stack[i];
		list_nb[i].binary = to_binary(a.stack[i]);
		list_nb[i].size = ft_intlen(a.stack[i]);
		if (list_nb[i].binary == NULL)
		{
			cleanup(&list_nb, i);
			return (1);
		}
		i++;
	}
	return (0);
}