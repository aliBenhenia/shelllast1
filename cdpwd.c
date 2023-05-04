/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdpwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaroua <mazaroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:09:06 by mazaroua          #+#    #+#             */
/*   Updated: 2023/05/04 17:30:23 by mazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_cd(char *path, t_env_list **env_list, int flag)
{
    g_var.exit_state = 0;
    if (!path || path[0] == '~')
        path = get_home_var(env_list);
    if (!path)
    {
        g_var.exit_state = 1;
        perror("Error: HOME directory not found");
        return;
    }
    if (chdir(path) == -1)
    {
        g_var.exit_state = 1; 
        write (2, "minishell: ", 11);
		write (2, path, ft_strlen(path));
		write (2, ": No such file or directory\n", 29);
        return ;
    }
    if (flag)
        exit(g_var.exit_state);
}

void    ft_pwd(int flag)
{
    char cwd[2000];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
	    ft_putstr(cwd);
    else
    {
	    perror("getcwd() error");
        exit(1);
    }
	ft_putstr("\n");
    if (flag)
        exit(0);
}
