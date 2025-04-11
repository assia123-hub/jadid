/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschalh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:30:22 by aschalh           #+#    #+#             */
/*   Updated: 2025/04/10 12:51:51 by aschalh          ###   ########.fr       */
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

static void	helper(t_list **a, char **av)
{
	int		i;
	char	*k;
	char	**ar;

	k = join(av);
	check_arguments(k);
	ar = ft_split(k, ' ');
	i = -1;
	while (ar[++i])
		add_node_last(a, new_node(update_atoi(ar[i])));
	free(k);
	ft_free(ar);
	check_double(a);
}

void    free_stack(t_list **stack)
{
    t_list  *tmp;
    t_list  *current;

    if (!stack || !*stack)
        return;
    current = *stack;
    while (current)
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    *stack = NULL;
}

int main(int ac, char **av)
{
    t_list  *a;
    t_list  *b;

    a = NULL;
    b = NULL;
    if (ac == 1)
        exit(1);
    helper(&a, av);
    if (wach_mertba(&a))
    {
        free_stack(&a);
        return (0);
    }
    if (return_number(a) <= 5)
        sort_small(&a, &b);
    else if (return_number(a) <= 250)
        sort100(&a, &b);
    else
        sort500(&a, &b);
    free_stack(&a);
    free_stack(&b);
    return (0);
}
