/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschalh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:29:16 by aschalh           #+#    #+#             */
/*   Updated: 2025/04/09 21:23:10 by aschalh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_node(int content)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}

void	add_node_last(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst || !new)
		return ;
	current = *lst;
	if (*lst != NULL)
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
	else
		*lst = new;
}

void	check_digits(char *str)
{
	int		i;
	int		has_digit;

	i = 0;
	has_digit = 0;
	if (str[0] == '\0')
		check_errors();
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			has_digit = 1;
			break ;
		}
		i++;
	}
	if (!has_digit)
		check_errors();
}

char	*join(char **av)
{
	char	*k;
	int		i;

	i = 1;
	k = NULL;
	while (av[i])
	{
		check_digits(av[i]);
		k = ft_strjoin(k, av[i]);
		k = ft_strjoin(k, " ");
		i++;
	}
	return (k);
}

int	wach_mertba(t_list **lst)
{
	t_list	*current;

	current = *lst;
	while (current && current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}
