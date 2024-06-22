#include "../push_swap.h"

void    ra(t_stack *a)
{
    Struct  *first;
    Struct  *temp;

    first = a->top;
    temp = a->top;
    while (temp->next)
        temp = temp->next;
    a->top = first->next;
    first->next = NULL;
    temp->next = first;
}

void    rb(t_stack *b)
{
    ra(b);
}

void    rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
}