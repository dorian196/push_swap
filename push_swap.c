#include "push_swap.h"

char    **ft_numeric(char **result)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (result[i])
    {
        while (result[i][j])
        {
            if ((result[i][j] >= 48 && result[i][j] <= 57) || result[i][j] == 43 || result[i][j] == 45)
                j++;
            else
            {
                write(1, "ErrorN\n", 7);
                return (0);
            }
        }
        j = 0;
        i++;
    }
    return (result);
}

int ft_no_repeat_num(Struct *value, int count)
{
    Struct  *current;
    Struct  *compare;
    Struct  *temp;

    current = value;
    while (current != NULL)
    {
        compare = current->next;
        while (compare != NULL)
        {
            if (current->value == compare->value)
            {
                write(1, "ErrorR\n", 7);
                while (value)
                {
                    temp = value;
                    value = value->next;
                    free(temp);
                }
                return (0); 
            }
            compare = compare->next;
        }
        current = current->next;
    }
    return (1);
}

int    ft_count_words(int count, int argc, char **argv)
{
    int i;
    int j;
    char **temp;

    i = 1;
    j = 0;
    while (i < argc)
    {
        temp = ft_split(argv[i], ' ');
        j = 0;
        while (temp[j])
        {
            count++;
            j++;
        }
        free(temp);
        i++;
    }
    return (count);
}

char    **ft_result_split(int count, char **result, char **argv, int argc)
{
    int i;
    int j;
    int k;
    char    **temp;

    result = malloc(sizeof(char*) * (count + 1));
    if (!result)
    {
        write(1, "Error\n", 6);
        free(result);
        return (0);
    }
    i = 1;
    k = 0;
    while (i < argc)
    {
        temp = ft_split(argv[i], ' ');
        j = 0;
        while (temp[j])
            result[k++] = temp[j++];
        i++;
        free(temp);
    }
    result[k] = 0;
    return (result);
}

Struct *ft_value(char **result, int count)
{
    int i;
    int error;
    Struct  *head;
    Struct  *current;
    Struct  *temp;
    Struct  *new;
    long    value;

    i = 0;
    error = 0;
    head = NULL;
    current = NULL;
    while (i < count)
    {
        value = ft_atoi(result[i], &error);
        if (value > 2147483647 || value < -2147483648 || error == 1) 
        {
            write(1, "ErrorV\n", 7);
            while (head)
            {
                temp = head;
                head = head->next;
                free(temp);
            }
            return (NULL); 
        }
        new = create(value);
        if (!new)
        {
            write(1, "ErrorV\n", 7);
            while (head)
            {
                temp = head;
                head = head->next;
                free(temp);
            }
            return (NULL); 
        }
        if (!head)
            head = new;
        else
            current->next = new;
        current = new;
        i++;
    }
    return (head);
}

int main(int argc, char **argv)
{
    char    **result;
    Struct  *tab;
    Struct  *current;
    Struct  *temp;
    int count;

    count = ft_count_words(0, argc, argv);
    result = ft_result_split(count, result, argv, argc);
    if (ft_numeric(result) == 0)
        return (0);
    tab = ft_value(result, count);
    if (tab == NULL)
        return (0);
    if (ft_no_repeat_num(tab, count) == 0)
        return (0);
    current = tab;
    while (current)
    {
        printf("%ld\n", current->value);
        current = current->next;
    }
    while (tab)
    {
        temp = tab;
        tab = tab->next;
        free(temp);
    }
    return (0);
}