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
                write(1, "Error\n", 6);
                return (0);
            }
        }
        j = 0;
        i++;
    }
    return (result);
}

long *ft_no_repeat_num(long *value, int count)
{
    int i;
    int j;

    i = 0;
    j = 1;
    while (i < count)
    {
        while (j < count)
        {
            if (value[i] == value[j])
            {
                write(1, "ErrorR\n", 7);
                free(value);
                return (0); 
            }
            j++;
        }
        i++;
        j = i + 1;
    }
    return (value);
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

    i = 1;
    k = 0;
    result = malloc(sizeof(char*) * (count + 1));
    if (!result)
        return (0);
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

long *ft_value(long *value, char **result, int count)
{
    int i;
    int j;

    i = 0;
    j = 0;
    value = malloc(sizeof(int) * (count + 1));
    if (!value)
        return (0);
    while (result[i])
    {
        value[j] = ft_atoi(result[i]);
        if (value[j] > 2147483647 || value[j] < -2147483648)
        {
            write(1, "ErrorV\n", 7);
            free(value);
            return (0); 
        }
        i++;
        j++;
    }
    value[j] = 0;
    return (value);
}

int main(int argc, char **argv)
{
    int i;
    char    **result;
    long *value;
    long *temp;
    int count;

    count = ft_count_words(0, argc, argv);
    printf("count : %d\n", count);
    result = ft_result_split(count, result, argv, argc);
    if (ft_numeric(result) == 0)
        return (0);
    value = ft_value(value, result, count);
    printf("%s\n", "ICI1");
    if (ft_no_repeat_num(value, count) == 0)
    {
        printf("%s\n", "ICI2");
        return (0);
    }
    printf("%s\n", "ICI3");
    i = 0;
    while (i < count)
    {
        printf("%ld\n", value[i]);
        i++;
    }
    free(result);
    free(value);
    return (0);
}