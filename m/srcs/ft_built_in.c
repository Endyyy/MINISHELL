/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achretie <achretie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:13:52 by achretie          #+#    #+#             */
/*   Updated: 2022/11/15 17:55:23 by achretie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_print_tabl(char **tabl)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (tabl[i])
	{
		if (tabl[i][0] == '_' && tabl[i][1] == '=')
		{
			i++;
			continue ;
		}
		printf("declare -x ");
		while (tabl[i][j] != '=' && tabl[i][j])
		{
			printf("%c", tabl[i][j]);
			j++;
		}
		if (tabl[i][j])
		{
			printf("=\"");
			j++;
		}
		while (tabl[i][j])
		{
			printf("%c", tabl[i][j]);
			j++;
		}
		i++;
		j = 0;
		printf("\"\n");
	}
	ft_free_path(tabl);
}

void	ft_print_export_bis(char **tabl)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 1;
	while (tabl[j])
	{
		while (tabl[i])
		{
			if (ft_strcmp(tabl[i], tabl[j]) > 0)
			{
				tmp = tabl[i];
				tabl[i] = tabl[j];
				tabl[j] = tmp;
			}
			i++;
		}
		i = 0;
		j++;
	}
	ft_print_tabl(tabl);
}

void	ft_print_export(t_data *data)
{
	t_env	*save;
	char	**tabl;
	int		i;

	i = 0;
	save = data->envp;
	while (data->envp->next)
	{
		i++;
		data->envp = data->envp->next;
	}
	data->envp = save;
	tabl = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (data->envp->next)
	{
		tabl[i] = ft_strdup(data->envp->content);
		data->envp = data->envp->next;
		i++;
	}
	data->envp = save;
	ft_print_export_bis(tabl);
}

int	ft_setenv(t_data *data, char *var, char *content) //Permet de modifier une variable de notre env
{
	t_env	*save;

	save = data->envp;
	while (data->envp->next)
	{
		if (ft_strncmp(data->envp->content, var, ft_strlen(var)) == 0 && ft_strlen(var) == ft_strlen(data->envp->key))
		{
			free(data->envp->content);
			data->envp->content = ft_strdup(var);
			data->envp->content = ft_strjoin(data->envp->content, "=");
			data->envp->content = ft_strjoin(data->envp->content, content);
			data->envp = save;
			return (1);
		}
		data->envp = data->envp->next;
	}
	data->envp = save;
	return (0);
}

char	*ft_getenv(t_data *data, char *var) //Permet de recuperer la valeur d'une variable de notre env
{
	t_env	*save;
	char	*content;

	save = data->envp;
	while (data->envp->next)
	{
		if (ft_strncmp(data->envp->content, var, ft_strlen(var)) == 0 && ft_strlen(var) == ft_strlen(data->envp->key))
		{
			content = ft_strdup(data->envp->content + ft_strlen(var) + 1);
			data->envp = save;
			return (content);
		}
		data->envp = data->envp->next;
	}
	data->envp = save;
	return (NULL);
}

void	ft_unset(t_data *data, char *var)
{
	t_env	*save;
	t_env	*tmp;

	save = data->envp;
	if (ft_strncmp(data->envp->content, var, ft_strlen(var)) == 0 && ft_strlen(var) == ft_strlen(data->envp->key))
	{
		tmp = data->envp;
		data->envp = data->envp->next;
		free(tmp);
		return ;
	}
	while (data->envp->next)
	{
		if (ft_strncmp(data->envp->next->content, var, ft_strlen(var)) == 0 && ft_strlen(var) == ft_strlen(data->envp->next->key))
		{
			tmp = data->envp->next;
			data->envp->next = tmp->next;
			free(tmp);
			break ;
		}
		data->envp = data->envp->next;
	}
	data->envp = save;
}

void	ft_init_data(t_data *data, char **envp)
{
	int		i;
	t_env	*head;

	head = NULL;
	i = 0;
	while (envp[i])
		i++;
	head = ft_fill_list(head, envp, i);
	data->envp = head;
}

void	ft_echo(t_data *data)
{
	if (!data->echo_flag)
		printf("%s\n", data->echo_str);
	else if (data->echo_flag)
		printf("%s", data->echo_str);
	
}
void	ft_pwd(void)
{
	char	buffer[10000];

	getcwd(buffer, 10000);
	printf("%s\n", buffer);
}

int	ft_cd(t_data *data) //Penser a verifier si les $var sont accessibles et on pas etait unset ?
{
	char	str[10000];
	char	*stock;
	char	*old_pwd;

	old_pwd = ft_getenv(data, "PWD");
	if (!data->cd_str) //cd sans argument, renvoie a HOME
	{
		stock = ft_getenv(data, "HOME");
		if (chdir(stock) == -1)
		{
			free(stock);
			return (-1);
		}
		ft_setenv(data, "PWD", stock);
	}
	else
	{
		if (chdir(data->cd_str) == -1)
		{
			free(old_pwd);
			return (-1);
		}
		getcwd(str, 10000);
		ft_setenv(data, "PWD", str);
	}
	ft_setenv(data, "OLDPWD", old_pwd);
	return (0);
}

void	ft_env(t_data *data)
{
	t_env *tmp;

	tmp = data->envp;
	while (data->envp)
	{
		printf("%s\n", data->envp->content);
		data->envp = data->envp->next;
	}
	data->envp = tmp;
}

void	ft_add_to_env_plus(t_data *data, char *arg)
{
	t_env	*save;
	char	*key;

	key = ft_get_key(arg);
	key = ft_strtrim(key, "+");
	save = data->envp;
	while (data->envp->next)
	{
		if (ft_strncmp(data->envp->key, key, ft_strlen(key)) == 0 && ft_strlen(key) == ft_strlen(data->envp->key))
		{
			data->envp->content = ft_strjoin(data->envp->content, arg + ft_strlen(key) + 2);
			data->envp = save;
			free(key);
			return ;
		}
		data->envp = data->envp->next;
	}
	data->envp = save;
	data->envp = ft_lstadd_front_env(key, data->envp);
	free(key);
}


int	ft_check_export_key(t_data *data, char *arg, int i)
{
	int	j;

	j = 1;
	while (j < i)
	{
		if ((arg[j] < 'A' || arg[j] > 'Z') && (arg[j] < 'a' || arg[j] > 'z') && (arg[j] < '0' || arg[j] > '9') && arg[j] != '+')
			return (1);
		if (arg[j] == '+')
		{
			if (j + 1 != i)
				return (1);
			else
			{
				ft_add_to_env_plus(data, arg);
				return (2);
			}
		}
		j++;
	}
	return (0);
}

void	ft_add_to_env(t_data *data, char *arg)
{
	t_env	*save;
	char	*key;

	key = ft_get_key(arg);
	save = data->envp;
	while (data->envp->next)
	{
		if (ft_strncmp(data->envp->content, arg, ft_strlen(arg)) == 0 && ft_strlen(key) == ft_strlen(data->envp->key))
		{
			free(data->envp->content);
			data->envp->content = ft_strdup(arg);
			data->envp = save;
			free(key);
			return ;
		}
		data->envp = data->envp->next;
	}
	data->envp = save;
	data->envp = ft_lstadd_front_env(arg, data->envp);
	free(key);
}

int	ft_parse_export_arg(t_data *data, char *arg)
{
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	if ((arg[0] < 'A' || arg[0] > 'Z') && (arg[0] < 'a' || arg[0] > 'z'))
		return (1);
	while (arg[i])
	{
		if (arg[i] == '=')
		{
			ret = ft_check_export_key(data, arg, i);
			if (ret == 1)
				return (1);
			else if (ret == 2)
				return (0);
			else
			{
				ft_add_to_env(data, arg);
				return (0);
			}
		}
		i++;
	}
	//strcmp
	data->envp = ft_lstadd_front_env(arg, data->envp);
	return (0);
}

void	ft_export(t_data *data, char *arg)
{
	if (!arg)
	{
		ft_print_export(data);
		return ;
	}
	if (ft_strlen(arg) == 1 && arg[0] == '_')
		return ;
	if (ft_parse_export_arg(data, arg))
	{
		printf("ERROR\n");
		return ;
	}
}
