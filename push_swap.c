#include "push_swap.h"

int	return_number(t_list *lst)
{
	int		size = 0;
	t_list	*current = lst;

	while (current)
	{
		current = current->next;
		size++;
	}
	return (size);
}
int main(int ac, char **av)
{
    int     i;
    char    *k;
    char    **ar;
    t_list  *j;
    t_list  *b;

    j = NULL;
    b = NULL;
    k = NULL;
    if (ac == 1)
        exit(1);
    k = av_join(av);
    check_arguments(k);
    ar = ft_split(k, ' ');
    i = -1;
    while (ar[++i])
        add_node_last(&j, new_node(update_atoi(ar[i])));
    if (wach_mertba(&j))
        return (0);
    if (return_number(j) <= 5)
        sort_small(&j, &b);
    else if (return_number(j) <= 250)
        sort100(&j, &b);
    else
        sort500(&j, &b);
    free(k);
}
