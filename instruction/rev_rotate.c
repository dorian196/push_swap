#include "../push_swap.h"

void    rra(t_stack *a)
{
    Struct  *prev;
    Struct  *last;

    prev = NULL;
    last = a->top;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    if (prev)
        prev->next = NULL;
    last->next = a->top;
    a->top = last;
}

void    rrb(t_stack *b)
{
    rra(b);
}

void    rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
}