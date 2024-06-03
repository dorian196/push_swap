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

    i = 0;
    tab = malloc(sizeof(char *) * ft_count(s, c) + 1);
    if (!tab)
        return (0);
    start = 0;
    while (start < ft_count(s, c))
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

int ft_atoi(const char *s)
{
    int sign;
    int count;
    int result;

    sign = 1;
    count = 0;
    while (*s >= 9 && *s <= 13 || *s == 32)
        s++;
    while (*s == '+' || *s == '-')
    {
        count++;
        if (count > 1)
            return (0);
        if (*s == '-')
            sign *= -1;
        s++;
    }
    while (*s >= '0' && *s <= '9')
        result = result * 10 + (*s++ - '0');
    return (result * sign);
}

int  ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}