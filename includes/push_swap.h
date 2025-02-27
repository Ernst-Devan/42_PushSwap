/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:31:12 by dernst            #+#    #+#             */
/*   Updated: 2025/02/27 15:24:15 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

int	*parsing_check(const char **numbers, const int size);

typedef struct s_stack
{
	int	*stack;
	int len;
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
	int	min;
	int	max;
	int	border1;
	int border2;
	int border3;
}	t_limits;

//Init.c
void	init_limits(t_limits *limits);

int	pre_sort(t_stack *a, t_stack *b);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *b, t_stack *a, int *count_action);
void	pb(t_stack *a, t_stack *b, int *count_action);
void	ra(t_stack *a, int *count_action);
void	rb(t_stack *b);
//void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack	*a, t_stack *b);

#endif