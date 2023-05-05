/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaroua <mazaroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 02:20:21 by mazaroua          #+#    #+#             */
/*   Updated: 2023/05/04 16:05:19 by mazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	if_exist(char *str, char **name_value, t_export **export,
	t_env_list **env_list)
{
	name_value[0] = get_name(str);
	if (check_if_exist(name_value[0], *export))
		return ;
	if (eqaul_last_only(str))
	{
		name_value[0] = ft_strjoin(name_value[0], "=");
		addback_env(env_list, addnew_env(name_value[0], ""));
	}
	addback_export(export, addnew_export(name_value[0], "\0"));
}

void	add_var_in_list(t_export **export, t_env_list **env_list, char *str)
{
	char		**name_value;

	name_value = malloc(sizeof(char *) * 3);
	if (check_if_equal_is(str) && eqaul_last_only(str) == 0)
	{
		name_value[0] = get_name(str);
		name_value[1] = get_value(str);
		if (check_if_exist(name_value[0], *export))
		{
			if (check_append(str))
			{
				append_string(name_value[0], name_value[1], export, env_list);
				return ;
			}
			edit_value(name_value[0], name_value[1], export, env_list);
			return ;
		}
		addback_export(export, addnew_export(name_value[0], name_value[1]));
		addback_env(env_list, addnew_env(name_value[0], name_value[1]));
	}
	else
		if_exist(str, name_value, export, env_list);
}

void	print_export(t_export *head)
{
	while (head)
	{
		if (*(head->value) == '\0')
		{
			if (eqaul_last_only(head->var))
				printf("declare -x %s\"\"\n", head->var);
			else
				printf("declare -x %s\n", head->var);
		}
		else
			printf("declare -x %s=\"%s\"\n", head->var, head->value);
		head = head->next;
	}
}

void	edit_env(t_env_list	**env_list, char *name, char *value)
{
	t_env_list	*lst;
	int			no_created;

	no_created = 0;
	lst = (*env_list);
	while (lst)
	{
		if (ft_strcmp(lst->name, name) == 0)
		{
			no_created = 1;
			lst->value = NULL;
			lst->value = value;
			return ;
		}
		lst = lst->next;
	}
	if (!no_created)
		addback_env(env_list, addnew_env(name, value));
}

void	do_export(char *str[], t_export **export,
t_env_list **env_list, int flag)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	j = 0;
	g_var.exit_state = 0;
	if (str[1] == NULL)
		print_export(*export);
	while (str[i])
	{
		if (correct_name(get_name(str[i])) && !isdigit(str[i][0]))
			add_var_in_list(export, env_list, str[i]);
		else
			error_od_export(str[i]);
		i++;
	}
	sort(export);
	if (flag)
		exit(g_var.exit_state);
}
