/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:42:56 by abenheni          #+#    #+#             */
/*   Updated: 2023/05/05 12:43:00 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_append(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '+' && s[i + 1] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	append_string(char *name, char *value, t_export **export,
	t_env_list **env_list)
{
	t_export	*head;

	head = (*export);
	while (head)
	{
		if (ft_strcmp(head->var, name) == 0)
		{
			head->value = ft_strjoin(head->value, value);
			break ;
		}
		head = head->next;
	}
	append_env(env_list, name, value);
}

void	error_od_export(char *s)
{
	g_var.exit_state = 1;
	printf("error : %s not identifier\n", s);
}

int	correct_name(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (ft_isalnum(s[i]) == 0)
		{
			if (s[i] == '+' && s[i + 1] == '\0' && i != 0)
				return (1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	eqaul_last_only(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=' && s[i + 1])
			return (0);
		if (s[i] == '=' && s[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}
