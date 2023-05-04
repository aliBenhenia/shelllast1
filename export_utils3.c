#include "minishell.h"
int	check_append(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if(s[i] == '+' && s[i + 1] == '=')
			return 1;
		i++;
	}
	return (0);
}
void	append_string(char *name, char *value,t_export **export, t_env_list **env_list)
{
	int	no_created;
	t_export *head;
	t_env_list *lst;

	head = (*export);
	lst = (*env_list);
	no_created = 0;
	while (head)
	{
		if (ft_strcmp(head->var, name) == 0)
		{
			head->value = ft_strjoin(head->value,value);
			break ;
		}
		head = head->next;
	}
	while (lst)
	{
		if (ft_strcmp(lst->name, name) == 0)
		{
			no_created = 1;
			lst->value = ft_strjoin(lst->value ,value);
			break ;
		}
		lst = lst->next;
	}
	if(!no_created)
		addback_env(env_list, addnew_env(name, value));
}

void	error_od_export(char *s)
{
	g_var.exit_state = 1;
	printf("error : %s not identifier\n", s);
}

int correct_name(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i]) 
	{
		if(ft_isalnum(s[i]) == 0)
		{
			if(s[i] == '+' && s[i + 1] == '\0' && i != 0)
				return (1);
			return (0);
		}
		i++;
	}
	return (1);
}
int	eqaul_last_only(char *s)
{
	int 	i;

	i = 0;
	while (s[i])
	{
		if(s[i] == '=' && s[i + 1])
			return 0;
		if(s[i] == '=' && s[i + 1] == '\0')
			return(1);
		i++;
	}
	return(0);
}