#include "push_swap.h"

int main(int argc, char **argv)
{
    int i;
    int j;
    int k;
    char    **result;
    char    **temp;
    int *value;
    int count;

    i = 1;
    count = 0;
    if (argc < 2)
        return (0);
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
        {
            result[k] = temp[j];
            k++;
            j++;
        }
        i++;
        free(temp);
    }
    result[k] = 0;
    
    j = 0;
    k = 0;
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
    i = 0;
    while (i < count)
    {
        printf("%d\n", value[i]);
        i++;
    }
    free(result);
    return (0);
}