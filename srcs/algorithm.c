/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:35:16 by dernst            #+#    #+#             */
/*   Updated: 2025/01/09 15:19:45 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// Check the first element of a stack if equals 1 push it into b stack
// Else rotate the stack a to have a new element to check it
// Again and again until to have check the all element of the list


// Need to have all acces to the a stack to switch element inside it 
// Maybe not i will true to forcepass
// Check too the lenght if the lenght is of the nb of the list is 
// smaller also defined it likes 0;



// !-! If we rotate the diffrent stack and merge it after the order of 
// !-! the list_nb not will be true so we need to rotate it to ???

//Check if other number need to push after else not need to ra again and again

#include "libft.h"
#include "push_swap.h"

int	check_next_null(t_nb *list_nb,t_stack *a, int index_bytes)
{
	int i;

	i = 0;
	while (i < a->len)
	{
		if (list_nb[find_index_nb(a, list_nb, a->stack[i])].binary[ft_strlen((list_nb[i].binary) + index_bytes + 1)] == '1' && ft_strlen(list_nb[i].binary) > (size_t)index_bytes)
			return (1);
		i++;
	}
	return (0);
}

void	check_bytes(t_nb *list_nb, t_stack *a, t_stack *b, int index_check, int *count_action)
{
	int i;
	int	j;
	int a_len;

	i = 0;
	j = 0;
	a_len = a->len;

	while (i < a_len)
	{
		while (a->stack[0] != list_nb[j].nb)
			j++;
		if (a->stack[0] == list_nb[j].nb)
		{
			if (list_nb[j].binary[ft_strlen((list_nb[j].binary) + index_check + 1)] == '1' && ft_strlen(list_nb[j].binary) > (size_t)index_check)
					pb(a, b, count_action);
			else 
				ra(a, count_action);
		}
		i++;
		j = 0;
	}
}

//void	check_bytes(t_nb *list_nb, t_stack *a, t_stack *b, int index_check, int *count_action)
//{
//	int i;
//	int	a_len;
//	int first_number;

//	printf("test");
//	i = 0;
//	a_len = a->len;

//	while (i < a_len)
//	{
//		first_number = find_index_nb(a, list_nb, a->stack[0]);
//		if (list_nb[first_number].binary[ft_strlen((list_nb[first_number].binary) + index_check + 1)] == '1' && ft_strlen(list_nb[first_number].binary) > (size_t)index_check)
//			pb(a, b, count_action);
//		else
//			ra(a, count_action);
//		i++;
//	}
	
//}

void merge_stack(t_stack *a, t_stack *b, int *count_action)
{
	while (b->len > 0)
	{
		pa(b, a, count_action);
	}
}
