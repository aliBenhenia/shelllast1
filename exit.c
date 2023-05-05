/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:06:30 by abenheni          #+#    #+#             */
/*   Updated: 2023/05/05 13:06:32 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_if_number(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (isdigit(s[i]))
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

void	do_exit(char *s[])
{
	if (s[1] == NULL)
	{
		ft_putstr_fd("exit\n", 1);
		exit(g_var.exit_state);
	}
	if (s[1] && !s[2])
	{
		if (check_if_number(s[1]))
		{
			ft_putstr_fd("exit\n", 1);
			exit(atoi(s[1]));
		}
		else
		{
			g_var.exit_state = 255;
			ft_putstr_fd("exit\n", 1);
			ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
			exit(g_var.exit_state);
		}
	}
	if (s[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		g_var.exit_state = 1;
	}
}
