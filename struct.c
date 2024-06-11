#include "push_swap.h"

Struct *create(long value)
{
    Struct *new_node = (Struct *)malloc(sizeof(Struct));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->next = NULL;
    return (new_node);
}

Struct *tab_list(long *tab, int count)
{
    int i;
    Struct *head;
    Struct *temp;
    Struct *current;

    if (count == 0)
        return (NULL);
    head = create(tab[0]);
    if (!head)
        return (NULL);
    current = head;
    i = 1;
    while (i < count)
    {
        current->next = create(tab[i]);
        if (!current->next)
        {
            while (head)
            {
                temp = head;
                head = head->next;
                free(temp);
            }
            return (NULL);
        }
        current = current->next;
    }
    return (head);
}