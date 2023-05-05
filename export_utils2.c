/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:29:16 by abenheni          #+#    #+#             */
/*   Updated: 2023/05/05 12:29:18 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_if_equal_is(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=' && str[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	check_if_exist(char *name, t_export *export)
{
	t_export	*head;

	head = export;
	while (head)
	{
		if (strchr(head->var, '='))
		{
			name = ft_strjoin(name, "=");
		}
		if (ft_strcmp(head->var, name) == 0)
			return (1);
		head = head->next;
	}
	return (0);
}

char	*get_name(char *s)
{
	int		i;
	char	*p;

	i = 0;
	if (s[0] == '=')
		return (NULL);
	while (s[i] && s[i] != '=')
	{
		if (s[i] == '+' && s[i + 1] == '=')
			break ;
		else if (s[i] == '+' && s[i + 1] == '+')
			return (NULL);
		i++;
	}
	return (ft_strndup(s, i));
}

char	*get_value(char *s)
{
	int		i;
	int		j;
	int		f;
	char	*p;

	i = 0;
	f = 0;
	while (s[i] != '=')
		i++;
	i++;
	j = i;
	while (s[i++])
		f++;
	p = malloc(f + 1);
	i = 0;
	while (s[j])
		p[i++] = s[j++];
	p[i] = '\0';
	return (p);
}

void	edit_value(char *name, char *value, t_export **data,
	t_env_list **env_list)
{
	t_export	*head;

	head = (*data);
	while (head)
	{
		if (ft_strcmp(head->var, name) == 0)
		{
			head->value = NULL;
			head->value = value;
			break ;
		}
		head = head->next;
	}
	edit_env(env_list, name, value);
}
