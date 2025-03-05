/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dernst <dernst@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:28:44 by dernst            #+#    #+#             */
/*   Updated: 2025/03/04 22:16:06 by dernst           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	sa(t_stack *a, int *count_action)
{
	int	temp;
	ft_printf("sa\n");
	if (a->len > 1)
	{
		temp = a->stack[0];
		a->stack[0] = a->stack[1];
		a->stack[1] = temp;
	}
	*count_action += 1;
}

void	sb(t_stack *b, int *count_action)
{
	int	temp;
	
	ft_printf("sb\n");
	if (b->len > 1)
	{
		temp = b->stack[0];
		b->stack[0] = b->stack[1];
		b->stack[1] = temp;
	}
	*count_action += 1;
}
void	ss(t_stack *a, t_stack *b, int *count_action)
{
	ft_printf("ss\n");
	sa(a, 0);
	sb(b, 0);
	*count_action += 1;
}

void	pa(t_stack *b, t_stack *a, int *count_action)
{
	int	i;
	size_t	j;

	*count_action +=1;
	ft_printf("pa\n");
	if (b->len >= 1)
	{
		i = a->len;
		i--;
		j = 0;
		while (i >= 0)
		{
			a->stack[i + 1] = a->stack[i]; 
			i--;
		}
		a->stack[0] = b->stack[0];
		while (j < b->len)
		{
			b->stack[j] = b->stack[j + 1];
			j++;
		}
		a->len += 1;
		b->len -= 1;
	}
}


//Why did the 9 disapeared
void	pb(t_stack *a, t_stack *b, int *count_action)
{
	int	i;
	size_t	j;

	*count_action += 1;
	ft_printf("pb\n");
	if (a->len >= 1)
	{
		i = b->len;
		i--;
		j = 0;
		while (i >= 0)
		{
			b->stack[i + 1] = b->stack[i]; 
			i--;
		}
		b->stack[0] = a->stack[0];
		while (j < a->len)
		{
			a->stack[j] = a->stack[j + 1];
			j++;
		}
		b->len += 1;
		a->len -= 1;
	}
}

void	ra(t_stack *a, int *count_action)
{
	size_t	i;
	int temp;

	*count_action +=1;
	ft_printf("ra\n");
	if (a->len > 1)
	{
		i = 0;
		temp = a->stack[0];
		while (i < a->len)
		{
			a->stack[i] = a->stack[i + 1];
			i++;
		}
		a->stack[a->len - 1] = temp;
	}
}

void	rb(t_stack *b, int *count_action)
{
	size_t	i;
	int temp;

	ft_printf("rb\n");
	if (b->len > 1)
	{
		i = 0;
		temp = b->stack[0];
		while (i < b->len)
		{
			b->stack[i] = b->stack[i + 1];
			i++;
		}
		b->stack[b->len - 1] = temp;
	}
	*count_action += 1;
}

void	rr(t_stack *a, t_stack *b, int *count_action)
{
	ft_printf("rr\n");
	ra(a, 0);
	rb(b, 0);
	*count_action += 1;
}

void	rra(t_stack *a)
{
	int	i;
	int temp;

	ft_printf("rra\n");
	if (a->len > 1)
	{
		i = a->len - 1;
		temp = a->stack[a->len - 1];
		while (i > 0)
		{
			a->stack[i] = a->stack[i - 1];
			i--;
		}
		a->stack[0] = temp;
	}
}

void	rrb(t_stack *b)
{
	int	i;
	int temp;

	ft_printf("rrb\n");
	if (b->len > 1)
	{
		i = b->len - 1;
		temp = b->stack[b->len - 1];
		while (i > 0)
		{
			b->stack[i] = b->stack[i - 1];
			i--;
		}
		b->stack[0] = temp;
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_printf("rrr\n");
	rra(a);
	rrb(b);
}