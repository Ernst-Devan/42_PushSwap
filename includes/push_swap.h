/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:31:12 by dernst            #+#    #+#             */
/*   Updated: 2025/01/09 14:05:22 by dernst           ###   ########lyon.fr   */
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
	int		size;
}	t_nb;

int		insert_list_binaries(t_nb *list_nb, t_stack a);

void	check_bytes(t_nb *list_nb, t_stack *a, t_stack *b, int index_check, int *count_action);
void	merge_stack(t_stack *a, t_stack *b, int *count_action);
int find_index_nb(t_stack *a, t_nb *list_nb, int number_to_find);

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