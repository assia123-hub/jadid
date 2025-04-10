/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschalh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:31:15 by aschalh           #+#    #+#             */
/*   Updated: 2025/04/09 20:53:51 by aschalh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*last_node(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	assia(int value, t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (value == tmp->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	position(t_list **a, int value)
{
	t_list	*current;
	int		pos;

	current = *a;
	pos = 0;
	while (current)
	{
		if (value == current->content)
			return (pos);
		pos++;
		current = current->next;
	}
	return (-1);
}

int	search(int *sorted_arr, t_list **a, int start, int end)
{
	t_list	*tmp;
	int		i;

	tmp = *a;
	i = start;
	while (tmp)
	{
		while (i <= end)
		{
			if (sorted_arr[i] == tmp->content)
				return (sorted_arr[i]);
			i++;
		}
		tmp = tmp->next;
	}
	return (sorted_arr[start]);
}

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
