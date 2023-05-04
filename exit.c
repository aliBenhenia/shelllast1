#include "minishell.h"
void    do_exit(char *s[])
{
    if(s[1] == NULL)
        exit(1);
    exit(atoi(s[1]));
}