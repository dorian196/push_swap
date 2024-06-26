#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>

int ft_count(const char *s, char c);
int ft_len(const char *s, char c, int i);
char    **ft_split(const char *s, char c);
int  ft_strlen(const char *s);
long ft_atoi(const char *s, int *error);

typedef struct Struct {
    long    value;
    struct  Struct *next;
} Struct;

typedef struct s_stack {
    Struct  *top;
} t_stack;

Struct *tab_list(long *tab, int count);
Struct *create_node(long value);

void    sa(t_stack *a);

#endif