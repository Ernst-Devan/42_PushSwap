/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:14:35 by dernst            #+#    #+#             */
/*   Updated: 2025/03/28 10:40:48 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include "unistd.h"

void	exit_free(t_stack *a, t_stack *b, size_t error)
{
	if (error == 1)
		write(2, "Error\n", 6);
	if (a != NULL && a->st)
		free(a->st);
	if (b != NULL && b->st)
		free(b->st);
	exit(0);
}
