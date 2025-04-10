/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschalh <aschalh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:20:22 by aschalh           #+#    #+#             */
/*   Updated: 2025/04/10 22:25:13 by aschalh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks(t_list **a, t_list **b, int *tab, int size)
{
	int	chunk_size;
	int	i;
	int	current;

	chunk_size = 30;
	i = 0;
	while (*a)
	{
		current = (*a)->content;
		if (current <= tab[i])
		{
			pb(a, b);
			i++;
		}
		else if (current <= tab[i + chunk_size])
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
}

static int	max_value(t_list *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->content;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

void	push_back_sorted(t_list **a, t_list **b)
{
	int	max;
	int	pos;

	while (*b)
	{
		max = max_value(*b);
		pos = position(b, max);
		if (pos <= return_number(*b) / 2)
			while ((*b)->content != max)
				rb(b);
		else
			while ((*b)->content != max)
				rrb(b);
		pa(a, b);
	}
}
