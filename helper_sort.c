/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschalh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:29:59 by aschalh           #+#    #+#             */
/*   Updated: 2025/04/09 20:56:42 by aschalh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	range_update(int *s, int *e, int offset, int max)
{
	if (*s - offset < 0)
		*s = 0;
	else
		*s -= offset;
	if (*e + offset > max)
		*e = max;
	else
		*e += offset;
}

void	push_a(t_list **a, t_list **b, int *tab, int mid)
{
	int	s;
	int	e;
	int	current;
	int	pos;
	int	offset;
	int	len;

	s = mid - (return_number(*a) / 8);
	e = mid + (return_number(*a) / 8);
	offset = (e - s) / 2;
	len = return_number(*a);
	while (*a)
	{
		current = search(tab, a, s, e);
		pos = position(a, current);
		if (pos != -1)
		{
			while (current != (*a)->content && pos > return_number(*a) / 2)
				rra(a);
			while (current != (*a)->content && pos <= return_number(*a) / 2)
				ra(a);
			pb(a, b);
			if (current < tab[mid])
				rb(b);
		}
		else
			range_update(&s, &e, offset, len);
	}
}

void	push_b(t_list **a, t_list **b, int *tab)
{
	int	size_tab;
	int	count;
	int	y;
	int	pos;

	size_tab = return_number(*a) + return_number(*b) - 1;
	count = 0;
	while (*b)
	{
		y = return_number(*b);
		if (assia(tab[size_tab], b))
		{
			if (tab[size_tab] == (*b)->content)
			{
				pa(a, b);
				size_tab--;
			}
			else if (count == 0 || (*b)->content > last_node(*a)->content)
			{
				pa(a, b);
				ra(a);
				count++;
			}
			else
			{
				pos = position(b, tab[size_tab]);
				if (tab[size_tab] != (*b)->content && pos > y / 2)
					rrb(b);
				else if (tab[size_tab] != (*b)->content && pos <= y / 2)
					rb(b);
			}
		}
		else
		{
			rra(a);
			count--;
			size_tab--;
		}
	}
}
