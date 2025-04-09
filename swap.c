#include "push_swap.h"

void swap(t_list **stack)
{
    t_list *tmp;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    tmp->next = *stack;
    *stack = tmp;
}
void sa(t_list **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void sb(t_list **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void ss(t_list **a, t_list **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}
