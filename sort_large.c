#include "push_swap.h"

void	sort_tab(int *arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
int	*change_array(t_list **a)
{
	int		size = return_number(*a);
	int		*arr = malloc(sizeof(int) * size);
	t_list	*tmp = *a;
	int		i = 0;

	if (!arr)
		return (NULL);
	while (tmp)
	{
		arr[i++] = tmp->content;
		tmp = tmp->next;
	}
	sort_tab(arr, size);
	return (arr);
}
void sort100(t_list **a, t_list **b)
{
    int len = return_number(*a);
    int mid = len / 2 - 1;
    int *tab = change_array(a);
    
    push_a(a, b, tab, mid);
    push_b(a, b, tab);
}

void sort500(t_list **a, t_list **b)
{
    int len = return_number(*a);
    int mid = len / 2 - 1;
    int *tab = change_array(a);
    
    push_a(a, b, tab, mid);
    push_b(a, b, tab);
    
    while (tab[return_number(*a) - 1] != last_node(*a)->content)
        rra(a);
}
