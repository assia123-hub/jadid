/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschalh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:30:22 by aschalh           #+#    #+#             */
/*   Updated: 2025/04/09 21:49:33 by aschalh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	return_number(t_list *lst)
{
	int		size;
	t_list	*current;

	size = 0;
	current = lst;
	while (current)
	{
		current = current->next;
		size++;
	}
	return (size);
}

int	main(int ac, char **av)
{
	int		i;
	char	*k;
	char	**ar;
	t_list	*j;
	t_list	*b;

	i = -1;
	k = NULL;
	j = NULL;
	b = NULL;
	if (ac == 1)
		exit(1);
	k = join(av);
	check_arguments(k);
	ar = ft_split(k, ' ');
	while (ar[++i])
		add_node_last(&j, new_node(update_atoi(ar[i])));
	if (wach_mertba(&j))
		return (0);
	if (return_number(j) <= 5)
		sort_small(&j, &b);
	else if (return_number(j) <= 250)
		sort100(&j, &b);
	else
		sort500(&j, &b) free(k);
}
