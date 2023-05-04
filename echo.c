#include "minishell.h"

int check_n(char *s)
{
    int i;

    i = 0; 
    if(s[i] != '-')
        return (0);
    i++;
    while (s[i] && s[i] == 'n')
        i++;
    if(s[i] == '\0')
        return (1);
    return (0);
}
void    ft_echo(char **str, int flag)
{
    int is_line;
    int i;

    i = 1;
    is_line = 0;
    while (check_n(str[i]))
    {
        is_line = 1;
        i++;
    }
    while (str[i])
    {
        printf("%s",str[i]);
        if(str[i + 1])
            printf(" ");
        i++;
    }
    if (is_line == 0)
        printf("\n");
    g_var.exit_state = 0;
     if (flag)
        exit(g_var.exit_state);
}