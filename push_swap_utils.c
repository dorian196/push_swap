#include "push_swap.h"

int ft_count(const char *s, char c)
{
    int count;
    int onoff;
    int i;

    count = 0;
    onoff = 0;
    i = 0;
    while (s[i])
    {
        if (s[i] != c)
        {
            if (onoff == 0)
            {
                count++;
                onoff = 1;
            }
        }
        else
            onoff = 0;
        i++;
    }
    return (count);
}

int ft_len(const char *s, char c, int i)
{
    int j;

    j = 0;
    while (s[i] && s[i] != c)
    {
        i++;
        j++;
    }
    return (j);
}

char    **ft_split(const char *s, char c)
{
    char **tab;
    int i;
    int j;
    int start;
    int word_count = ft_count(s, c);

    i = 0;
    tab = malloc(sizeof(char *) * (word_count + 1));
    if (!tab)
        return (0);
    start = 0;
    while (start < word_count)
    {
        while (s[i] == c)
            i++;
        j = 0;
        tab[start] = malloc(sizeof(char) * ft_len(s, c, i) + 1);
        if (!tab[start])
            return (0);
        while (s[i] && s[i] != c)
            tab[start][j++] = s[i++];
        tab[start][j] = '\0';
        start++;
    }
    tab[start] = 0;
    return (tab);
}

long ft_atoi(const char *s, int *error)
{
    int i;
    int sign;
    int count;
    long result;

    i = 0;
    sign = 1;
    count = 0;
    result = 0;
    while (s[i] >= 9 && s[i] <= 13 || s[i] == 32)
        i++;
    while (s[i] == '+' || s[i] == '-')
    {
        count++;
        if (count > 1)
        {
            *error = 1;
            return (0);
        }
        if (s[i] == '-')
            sign *= -1;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9')
        result = result * 10 + (s[i++] - '0');
    if (s[i] == '-' || s[i] == '+')
        {
            *error = 1;
            return (0);
        }
    return (result *= sign);
}

int  ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}