#include "push_swap.h"

int small(t_list **a)
{
	t_list *tmp;
	int i;

	tmp = (*a);
	i = (*a)->content;
	while (tmp)
	{
		if (i > tmp->content)
		{
			i = tmp->content;
		}
		tmp = tmp->next;
	}
	return (i);
}

void sort_two(t_list **a)
{
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

void sort_three(t_list **a)
{
	int first = (*a)->content;
	int second = (*a)->next->content;
	int third = (*a)->next->next->content;

	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void sort_four_five(t_list **a, t_list **b)
{
	int size;
	int min_pos;

	while (return_number(*a) > 3)
	{
		size = return_number(*a);
		min_pos = position(a, small(a));
		if (min_pos <= size / 2)
		{
			while (min_pos-- > 0)
				ra(a);
		}
		else
		{
			min_pos = size - min_pos;
			while (min_pos-- > 0)
				rra(a);
		}
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

void sort_small(t_list **a, t_list **b)
{
	int size;

	size = return_number(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4 || size == 5)
		sort_four_five(a, b);
}
