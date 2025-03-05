/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:31:12 by dernst            #+#    #+#             */
/*   Updated: 2025/03/04 22:17:28 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

int	*parsing_check(const char **numbers, const int size);

typedef struct s_stack
{
	int		*stack;
	size_t	len;
}	t_stack;

typedef struct s_nb
{
	int		nb;
	char	*binary;
	int		len;
	int 	len_list;
}	t_nb;

typedef struct limits
{
	int		*borders;
	size_t	len;
	size_t	mem_len;
}	t_limits;

//Init.c
t_limits	init_limits(size_t len);

int	pre_sort(t_stack *a, t_stack *b);

void	sa(t_stack *a, int *count_action);
void	sb(t_stack *b, int *count_action);
void	ss(t_stack *a, t_stack *b, int *count_action);
void	pa(t_stack *b, t_stack *a, int *count_action);
void	pb(t_stack *a, t_stack *b, int *count_action);
void	ra(t_stack *a, int *count_action);
void	rb(t_stack *b, int *count_action);
void	rr(t_stack *a, t_stack *b, int *count_action);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack	*a, t_stack *b);

#endif