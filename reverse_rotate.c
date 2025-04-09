#include "push_swap.h"

void reverse_rotate(t_list **stack)
{
    t_list *second_last;
    t_list *last;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    second_last = *stack;
    while (second_last->next && second_last->next->next)
        second_last = second_last->next;

    last = second_last->next;
    second_last->next = NULL;
    last->next = *stack;
    *stack = last;
}
void rra(t_list **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}

void rrb(t_list **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void rrr(t_list **a, t_list **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}
