/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achretie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:31:34 by achretie          #+#    #+#             */
/*   Updated: 2022/09/28 20:31:42 by achretie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"

int	ft_free_path(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	free(data);
	return (0);
}

char	**ft_parse_path(char **envp)
{
	char	**path;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	path = ft_split(envp[i] + 5, ':');
	return (path);
}

char	*ft_execve_path(char **cmd, char **envp)
{
	char	**path;
	char	*word;
	char	*full_word;
	int		i;

	if (ft_strnstr(cmd[0], "/", ft_strlen(cmd[0])))
		return (cmd[0]);
	path = ft_parse_path(envp);
	i = -1;
	while (path[++i])
	{
		word = ft_strjoin(path[i], "/");
		full_word = ft_strjoin(word, cmd[0]);
		if (access(full_word, F_OK) == 0)
		{
			free(word);
			ft_free_path(path);
			return (full_word);
		}
		free(word);
		free(full_word);
	}
	ft_free_path(path);
	return (0);
}

int	ft_start_exec(t_data *data, char **envp, char *input)
{
	data->full_cmd = ft_split(input, ' ');
	data->cmd = ft_execve_path(data->full_cmd, envp);
	data->pid = fork();
	if (data->pid < 0)
		return (-1);
	if (data->pid == 0)
		execve(data->cmd, data->full_cmd, envp);
	waitpid(data->pid, NULL, 0);
	return (0);
}