#include "push_swap.h"

void check_errors(void)
{
    write(2, "Error\n", 6);
    exit(1);
}
int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}
void	check_double(t_list **a)
{
	t_list *current = *a;
	while (current)
	{
		t_list *scanner = current->next;
		while (scanner)
		{
			if (scanner->content == current->content)
				check_errors();
			scanner = scanner->next;
		}
		current = current->next;
	}
}
void	check_arguments(char *av)
{
	int	i = 0;

	while (av[i])
	{
		char c = av[i];
		char next = av[i + 1];

		if (ft_isdigit(c) && (next == '+' || next == '-'))
			check_errors();
		if ((c == '+' || c == '-') && !ft_isdigit(next))
			check_errors();
		if (!(ft_isdigit(c) || c == ' ' || c == '+' || c == '-'))
			check_errors();
		i++;
	}
}
