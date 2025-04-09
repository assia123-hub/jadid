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
	t_list	*tmp = *lst;

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
	t_list	*current = *a;
	int		pos = 0;

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
	t_list	*tmp = *a;

	while (tmp)
	{
		for (int i = start; i <= end; i++)
		{
			if (sorted_arr[i] == tmp->content)
				return (sorted_arr[i]);
		}
		tmp = tmp->next;
	}
	return (sorted_arr[start]);
}