/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: aschalh <marvin@42.fr>                     +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/04/09 20:30:34 by aschalh           #+#    #+#             */
/*   Updated: 2025/04/09 20:30:36 by aschalh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tab(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*change_array(t_list **a)
{
	int		size;
	int		*arr;
	t_list	*tmp;
	int		i;

	size = return_number(*a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	tmp = *a;
	i = 0;
	while (tmp)
	{
		arr[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	sort_tab(arr, size);
	return (arr);
}

void	sort100(t_list **a, t_list **b)
{
	int		len;
	int		mid;
	int		*tab;

	len = return_number(*a);
	mid = len / 2 - 1;
	tab = change_array(a);
	push_a(a, b, tab, mid);
	push_b(a, b, tab);
}

void	sort500(t_list **a, t_list **b)
{
	int		len;
	int		mid;
	int		*tab;

	len = return_number(*a);
	mid = len / 2 - 1;
	tab = change_array(a);
	push_a(a, b, tab, mid);
	push_b(a, b, tab);
	while (tab[return_number(*a) - 1] != last_node(*a)->content)
		rra(a);
}
