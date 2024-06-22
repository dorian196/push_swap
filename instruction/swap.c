#include "../push_swap.h"

void    sa(t_stack *a)
{
    Struct  *first;
    Struct  *second;

    first = a->top;
    second = a->top->next;
    first->next = second->next;
    second->next = first;
    a->top = second;
}

void    sb(t_stack *b)
{
    sa(b);
}

void    ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}