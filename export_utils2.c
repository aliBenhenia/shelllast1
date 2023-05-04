#include "minishell.h"
int check_if_equal_is(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=' && str[i + 1])
			return(1);
		i++;
	}
	return(0);
}
int check_if_exist(char *name, t_export *export)
{
	t_export *head;

	head = export;
	while (head)
	{
		if(strchr(head->var, '='))
		{
			name = ft_strjoin(name, "=");
		}
		if (ft_strcmp(head->var, name) == 0)
			return(1);
		head = head->next;
	}
	return(0);
}

char *get_name(char *s)
{
	int i;
	char *p;

	i = 0;
	if(s[0] == '=')
		return (NULL);
	while (s[i] && s[i] != '=')
	{
		if(s[i] == '+' && s[i + 1] == '=')
			break;
		else if (s[i] == '+' && s[i + 1] == '+')
			return (NULL) ;
		i++;
	}
	return (ft_strndup(s, i));
}
char *get_value(char *s)
{
	int i;
	int j;
	int f;
	char *p;

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
void	edit_value(char *name, char *value, t_export **data, t_env_list **env_list)
{
	t_export *head;
	t_env_list *lst;
	int no_created;

	head = (*data);
	no_created = 0;
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
	if(!no_created)
		addback_env(env_list,addnew_env(name,value));
}