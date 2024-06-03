#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

int ft_count(const char *s, char c);
int ft_len(const char *s, char c, int i);
char    **ft_split(const char *s, char c);
int  ft_strlen(const char *s);

int ft_atoi(const char *s);

#endif