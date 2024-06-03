#include "push_swap.h"

int main(int argc, char **argv)
{
    int i;
    int j;
    int k;
    char    **result;
    int *value;
    int count;

    i = 1;
    j = 0;
    k = 0;
    count = 0;
    if (argc < 2)
        return (0);
    while (i < argc)
    {
        result = ft_split(argv[i], ' ');
        i++;
        while (result[j])
        {
            count++;
            j++;
        }
    }
    j = 0;
    i = 0;
    value = malloc(sizeof(int) * (count + 1));
    if (!value)
        return (0);
    while (result[j])
    {
        value[k] = ft_atoi(result[j]);
        j++;
        k++;
    }
    value[k] = 0;
    while (i < count)
    {
        printf("%d\n", value[i]);
        i++;
    }
    return (0);
}