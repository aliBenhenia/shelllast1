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

// t_export	*addnew_export(char *var, char *value)
// {
// 	t_export	*new;

// 	new = malloc(sizeof(t_export));
// 	if (!new)
// 		return (NULL);
// 	new->var = var;
// 	new->value = value;
// 	new->next = NULL;
// 	return (new);
// }
// void	addback_export(t_export **a, t_export *new)
// {
//   t_export  *head;
// 	if((*a) == NULL)
// 	{
// 		(*a) = new;
// 	}
// 	else
// 	{
// 		head = (*a);
// 		new->next = NULL;
// 		head = (*a);
// 		while (head->next)
// 			head = head->next;
// 		head->next = new;
// 	}
// }

// t_env_list	*addnew_env(char *var, char *value)
// {
// 	t_env_list	*new;

// 	new = malloc(sizeof(t_env_list));
// 	if (!new)
// 		return (NULL);
// 	new->name = var;
// 	new->value = value;
// 	new->next = NULL;
// 	return (new);
// }
// void	addback_env(t_env_list **a, t_env_list *new)
// {
//   	t_env_list	*head;

// 	new->next = NULL;
// 	head = (*a);
// 	if(head == NULL)
// 		 (*a) = new;
// 	else
// 	{ 
// 		head = (*a);
// 		while (head->next)
// 			head = head->next;
// 		head->next = new;
// 	}
// }
// void    do_env(char *env[])
// {
// 	int i;

// 	i = 0;
// 	while (env[i])
// 	{
// 		ft_putstr(env[i]);
// 		ft_putstr("\n");
// 		i++;
// 	}
// }

// int check_if_equal_is(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '=' && str[i + 1])
// 			return(1);
// 		i++;
// 	}
// 	return(0);
// }
// int check_if_exist(char *name, t_export *export)
// {
// 	t_export *head;

// 	head = export;
// 	while (head)
// 	{
// 		if(strchr(head->var, '='))
// 		{
// 			name = ft_strjoin(name, "=");
// 		}
// 		if (ft_strcmp(head->var, name) == 0)
// 			return(1);
// 		head = head->next;
// 	}
// 	return(0);
// }

// char *get_name(char *s)
// {
// 	int i;
// 	char *p;

// 	i = 0;
// 	if(s[0] == '=')
// 		return (NULL);
// 	while (s[i] && s[i] != '=')
// 	{
// 		if(s[i] == '+' && s[i + 1] == '=')
// 			break;
// 		else if (s[i] == '+' && s[i + 1] == '+')
// 			return (NULL) ;
// 		i++;
// 	}
// 	return (ft_strndup(s, i));
// }

// char *get_value(char *s)
// {
// 	int i;
// 	int j;
// 	int f;
// 	char *p;

// 	i = 0;
// 	f = 0;
// 	while (s[i] != '=')
// 		i++;
// 	i++;
// 	j = i;
// 	while (s[i++])
// 		f++;
// 	p = malloc(f + 1);
// 	i = 0;
// 	while (s[j])
// 		p[i++] = s[j++];
// 	p[i] = '\0';
// 	return (p);
// }
// void	edit_value(char *name, char *value, t_export **data, t_env_list **env_list)
// {
// 	t_export *head;
// 	t_env_list *lst;
// 	int no_created;

// 	head = (*data);
// 	no_created = 0;
// 	while (head)
// 	{
// 		if (ft_strcmp(head->var, name) == 0)
// 		{
// 			head->value = NULL;
// 			head->value = value;
// 			break ;
// 		}
// 		head = head->next;
// 	}
// 	lst = (*env_list);
// 	while (lst)
// 	{
// 		if (ft_strcmp(lst->name, name) == 0)
// 		{
// 			no_created = 1;
// 			lst->value = NULL;
// 			lst->value = value;
// 			return ;
// 		}
// 		lst = lst->next;
// 	}
// 	if(!no_created)
// 		addback_env(env_list,addnew_env(name,value));
// }
// int	check_append(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if(s[i] == '+' && s[i + 1] == '=')
// 			return 1;
// 		i++;
// 	}
// 	return (0);
// }
// void	append_string(char *name, char *value,t_export **export, t_env_list **env_list)
// {
// 	int	no_created;
// 	t_export *head;
// 	t_env_list *lst;

// 	head = (*export);
// 	lst = (*env_list);
// 	no_created = 0;
// 	while (head)
// 	{
// 		if (ft_strcmp(head->var, name) == 0)
// 		{
// 			head->value = ft_strjoin(head->value,value);
// 			break ;
// 		}
// 		head = head->next;
// 	}
// 	while (lst)
// 	{
// 		if (ft_strcmp(lst->name, name) == 0)
// 		{
// 			no_created = 1;
// 			lst->value = ft_strjoin(lst->value ,value);
// 			break ;
// 		}
// 		lst = lst->next;
// 	}
// 	if(!no_created)
// 		addback_env(env_list, addnew_env(name, value));
// }

// void	error_od_export(char *s)
// {
// 	g_var.exit_state = 1;
// 	printf("error : %s not identifier\n", s);
// }

// int correct_name(char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (s == NULL)
// 		return (0);
// 	while (s[i]) 
// 	{
// 		if(ft_isalnum(s[i]) == 0)
// 		{
// 			if(s[i] == '+' && s[i + 1] == '\0' && i != 0)
// 				return (1);
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }
// int	eqaul_last_only(char *s)
// {
// 	int 	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if(s[i] == '=' && s[i + 1])
// 			return 0;
// 		if(s[i] == '=' && s[i + 1] == '\0')
// 			return(1);
// 		i++;
// 	}
// 	return(0);
// }

//ss
void    add_var_in_list(t_export **export,t_env_list **env_list, char *str)
{
	char    **name_value;
	t_env_list *env;
	t_export *export_head;

	name_value = malloc(sizeof(char *) * 3);
	if (check_if_equal_is(str) && eqaul_last_only(str) == 0)
	{
		name_value[0] = get_name(str);
		name_value[1] = get_value(str);
		if(check_if_exist(name_value[0],*export)) 
		{
			if(check_append(str))
			{
				append_string(name_value[0],name_value[1],export,env_list);
				return;
			}
			edit_value(name_value[0], name_value[1], export, env_list);
			return;
		}
		export_head = addnew_export(name_value[0], name_value[1]);
		addback_export(export, export_head);
		env = addnew_env(name_value[0], name_value[1]);
		addback_env(env_list, env);
	}
	else
	{
		name_value[0] = get_name(str);
		if(check_if_exist(name_value[0],*export))
			return ;
		if(eqaul_last_only(str))
		{
			name_value[0] = ft_strjoin(name_value[0],"=");
			env = addnew_env(name_value[0],"");
			addback_env(env_list,env);
		}
		export_head = addnew_export(name_value[0],"\0");
		addback_export(export,export_head);
	}
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
