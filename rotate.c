#include "push_swap.h"

void rotate(t_list **stack)
{
    t_list *tmp;
    t_list *last;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    tmp = *stack;
    *stack = tmp->next;
    tmp->next = NULL;

    last = *stack;
    while (last->next)
        last = last->next;
    last->next = tmp;
}
void ra(t_list **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void rb(t_list **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void rr(t_list **a, t_list **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}
