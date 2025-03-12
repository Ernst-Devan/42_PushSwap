/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:31:12 by dernst            #+#    #+#             */
/*   Updated: 2025/03/11 11:18:30 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

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
	size_t	border_size;
}	t_limits;


void	parsing_check(const char **numbers, t_stack *a);

//Init.c
t_limits	init_limits(size_t len);
t_stack		init_stack(size_t len);

//Utils.c
void	display_stack(t_stack a, t_stack b);
void	display_limits(t_limits limits);


//Limits.c
void	calculate_border(t_limits *limits);
void	find_limits(t_stack a, t_limits *limits);
size_t	nb_inside_limits(t_stack a, int limit1, int limit2, int a_len);

size_t	pre_sort(t_stack *a, t_stack *b);
size_t	sort(t_stack *a, t_stack *b);
void sort_limits(t_limits *limits);

void	sa(t_stack *a, size_t *count_action);
void	sb(t_stack *b, size_t *count_action);
void	ss(t_stack *a, t_stack *b, size_t *count_action);
void	pa(t_stack *b, t_stack *a, size_t *count_action);
void	pb(t_stack *a, t_stack *b, size_t *count_action);
void	ra(t_stack *a, size_t *count_action, size_t rr);
void	rb(t_stack *b, size_t *count_action, size_t rr);
void	rr(t_stack *a, t_stack *b, size_t *count_action);

//! Missing the count_action is important for the next so add it
void	rra(t_stack *a, size_t *count_action, size_t rrr);
void	rrb(t_stack *b, size_t *count_action, size_t rrr);
void	rrr(t_stack	*a, t_stack *b, size_t *count_action);

#endif