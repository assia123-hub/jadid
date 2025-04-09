#include "push_swap.h"

void range_update(int *s, int *e, int offset, int max)
{
    if (*s - offset < 0)
        *s = 0;
    else
        *s -= offset;
    
    if (*e + offset > max)
        *e = max;
    else
        *e += offset;
}
void push_a(t_list **a, t_list **b, int *tab, int mid)
{
    int s = mid - (return_number(*a) / 8);
    int e = mid + (return_number(*a) / 8);
    int current;
    int pos;
    int offset = (e - s) / 2;
    int len = return_number(*a);
    
    while ((*a))
    {
        current = search(tab, a, s, e);
        pos = position(a, current);
        if (pos != -1)
        {
            while (current != (*a)->content && pos > return_number(*a) / 2)
                rra(a);
            while (current != (*a)->content && pos <= return_number(*a) / 2)
                ra(a);
            pb(a, b);
            if (current < tab[mid])
                rb(b);
        }
        else
            range_update(&s, &e, offset, len);
    }
}

void push_b(t_list **a, t_list **b, int *tab)
{
    int size_tab = return_number(*a) + return_number(*b) - 1;
    int count = 0;
    int y;
    int pos;

    while ((*b))
    {
        y = return_number(*b);
        if (assia(tab[size_tab], b))
        {
            if (tab[size_tab] == (*b)->content)
            {
                pa(a, b);
                size_tab--;
            }
            else if (count == 0 || (*b)->content > last_node((*a))->content)
            {
                pa(a, b);
                ra(a);
                count++;
            }
            else
            {
                pos = position(b, tab[size_tab]);
                if (tab[size_tab] != (*b)->content && pos > y / 2)
                    rrb(b);
                else if (tab[size_tab] != (*b)->content && pos <= y / 2)
                    rb(b);
            }
        }
        else
        {
            rra(a);
            count--;
            size_tab--;
        }
    }
}

