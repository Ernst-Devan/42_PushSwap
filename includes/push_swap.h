/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:31:12 by dernst            #+#    #+#             */
/*   Updated: 2025/03/28 10:41:40 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//Includes
# include <stdlib.h>

//Stucts
typedef struct s_stack
{
	int		*st;
	size_t	l;
}	t_stack;

typedef struct s_limits
{
	int		*borders;
	int		len;
	int		mem_len;
	size_t	border_size;
}	t_limits;

typedef struct s_sort
{
	t_stack		a;
	t_stack		b;
}	t_sort;

//Parsing.c
void	parsing_check(const char **numbers, t_stack *a);

//Error.c
void	exit_free(t_stack *a, t_stack *b, size_t error);

//Init.c
void	init_list(t_sort *list);
int		init_limits(t_sort *list, t_limits *lim, int len);
int		init_stack(t_stack *stack, size_t len);

//Utils.c
int		ps_atoi(const char *nptr, int *overflow);

//Limits.c
void	calculate_border(t_limits *limits);
void	find_limits(t_stack a, t_limits *limits);
size_t	nb_inside_limits(t_stack a, int *lim, int a_len);

//Fill_stack.c
void	fill_stack(const int size, const char **start_argv);
size_t	find_next_min(t_stack *a, int last_min);
int		simplify(t_stack *a);

void	pre_sort(t_sort *list);
void	push_swap(t_sort *list);
void	sort(t_sort *list);
void	sort_limits(t_limits *limits);

//Operations.c
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *b, t_stack *a);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a, size_t rr);
void	rb(t_stack *b, size_t rr);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, size_t rrr);
void	rrb(t_stack *b, size_t rrr);
void	rrr(t_stack	*a, t_stack *b );

#endif