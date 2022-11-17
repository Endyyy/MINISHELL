/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:17:36 by mafissie          #+#    #+#             */
/*   Updated: 2022/10/08 02:00:33 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mini.h"

void	test_display_type(t_args **args, char *str)
{
	t_args *tmp;
	static int nbr;
	/* return ; */
	if (args == NULL)
	{
		printf("%s%sfun :[%s]\n%s",  C_BLUE, C_REVERSE, str, C_RESET);
		return ;
	}
	printf("%s%sfun :[%s]\n%s",  C_BLUE, C_REVERSE, str, C_RESET);
	tmp = *args;
	printf("%s%s%d/)[t_args *content]\n%s", C_BLUE, C_BLINK, nbr++, C_RESET);
	if (args == NULL)
		printf("%s%sfun :[%s] t_args *[NULL]\n%s",  C_RED, C_REVERSE, str, C_RESET);

	while (tmp->next != NULL)
	{

		if (tmp->type == WRITE)
			printf("%sindex [%d]: WRITE   \n%s", C_BRIGHT, tmp->index, C_RESET);
		if (tmp->type == CMD)
			printf("%sindex [%d]: CMD     \n%s", C_BRIGHT, tmp->index, C_RESET);
		if (tmp->type == BUILTINS)
			printf("%sindex [%d]: BUILTINS\n%s", C_BRIGHT, tmp->index, C_RESET);
		if (tmp->type == ENV)
			printf("%sindex [%d]: ENV     \n%s", C_BRIGHT, tmp->index, C_RESET);
		if (tmp->type == GREAT)
			printf("%sindex [%d]: GREAT   \n%s", C_BRIGHT, tmp->index, C_RESET);
		if (tmp->type == D_GREAT)
			printf("%sindex [%d]: D_GREAT \n%s", C_BRIGHT, tmp->index, C_RESET);
		if (tmp->type == LESS)
			printf("%sindex [%d]: LESS    \n%s", C_BRIGHT, tmp->index, C_RESET);
		if (tmp->type == D_LESS)
			printf("%sindex [%d]: D_LESS  \n%s", C_BRIGHT, tmp->index, C_RESET);
		if (tmp->type == NEW_PATH)
			printf("%sindex [%d]: NEW_PATH\n%s", C_BRIGHT, tmp->index, C_RESET);
		if (tmp->type == PIPE)
			printf("%sindex %d: PIPE\n%s", C_BRIGHT, tmp->index, C_RESET);
		printf("%s%scontent : [%s]\n%s", C_GREEN, C_BRIGHT, tmp->content, C_RESET);
		tmp = tmp->next;
	}
		if (tmp->type == WRITE)
			printf("%sindex [%d]: WRITE   \n%s", C_BRIGHT, tmp->index, C_RESET);
		if (tmp->type == CMD)
			printf("%sindex [%d]: CMD     \n%s", C_BRIGHT, tmp->index, C_RESET);
		if (tmp->type == BUILTINS)
			printf("%sindex [%d]: BUILTINS\n%s", C_BRIGHT, tmp->index, C_RESET);
		if (tmp->type == ENV)
			printf("%sindex [%d]: ENV     \n%s", C_BRIGHT, tmp->index, C_RESET);
		if (tmp->type == GREAT)
			printf("%sindex [%d]: GREAT   \n%s", C_BRIGHT, tmp->index, C_RESET);
		if (tmp->type == D_GREAT)
			printf("%sindex [%d]: D_GREAT \n%s", C_BRIGHT, tmp->index, C_RESET);
		if (tmp->type == LESS)
			printf("%sindex [%d]: LESS    \n%s", C_BRIGHT, tmp->index, C_RESET);
		if (tmp->type == D_LESS)
			printf("%sindex [%d]: D_LESS  \n%s", C_BRIGHT, tmp->index, C_RESET);
		if (tmp->type == NEW_PATH)
			printf("%sindex [%d]: NEW_PATH\n%s", C_BRIGHT, tmp->index, C_RESET);
		if (tmp->type == PIPE)
			printf("%sindex %d: PIPE\n%s", C_BRIGHT, tmp->index, C_RESET);
		printf("%s%scontent : [%s]\n%s", C_GREEN, C_BRIGHT, tmp->content, C_RESET);
}

int	identify_parse(char *sstr)
{
	if (ft_strstr(sstr, "<<"))
		return (D_LESS);
	else if (ft_strstr(sstr, ">>"))
		return (D_GREAT);
	else if (ft_strstr(sstr, ">"))
		return (GREAT);
	else if (ft_strstr(sstr, "<"))
		return (LESS);
	else if (ft_strstr(sstr, ".")
		|| ft_strstr(sstr, "./")
		|| ft_strstr(sstr, ".."))
		return (NEW_PATH);
	else if (ft_strstr(sstr, "$"))
		return (ENV);
	else if (ft_strstr(sstr, "|"))
		return (PIPE);
	else if (ft_strstr(sstr, "echo") || ft_strstr(sstr, "cd")
		|| ft_strstr(sstr, "pwd")
		|| ft_strstr(sstr, "export")
		|| ft_strstr(sstr, "unset")
		|| ft_strstr(sstr, "env")
		|| ft_strstr(sstr, "exit"))
		return (BUILTINS);
	else
		return (WRITE);
}

// type cmd + flag => tab [2];

void	fill_data_cmd(t_args **list, int *index, t_args **args)
{
	ft_cd_list(list, args, *index);
	if (identify_parse((*list)->content) == D_LESS)
		construct_d_less(list, index, (*list)->content, args);
	else if (identify_parse((*list)->content) == D_GREAT)
		construct_d_great(list, index, (*list)->content, args);
	else if (identify_parse((*list)->content) == GREAT)
		construct_great(list, index, (*list)->content, args);
	else if (identify_parse((*list)->content) == LESS)
		construct_less(list, index, (*list)->content, args);
	else if (identify_parse((*list)->content) == NEW_PATH)
		construct_new_path(list, index, (*list)->content, args);
	else if (identify_parse((*list)->content) == ENV)
		construct_env(list, index, (*list)->content, args);
	else if (identify_parse((*list)->content) == PIPE)
		construct_pipe(list, index, (*list)->content, args);
	else if (identify_parse((*list)->content) == BUILTINS)
		construct_builtins(list, index, (*list)->content, args);
	//else if ==> check cmd 
	else // si ce n'est pas tout ça c'est forcément quelque chose à écrire
		(*list)->type = WRITE;
	*index += 1;
}

int		fill_list_args(t_args **args, char **sstr)
{
	int i;
	t_args	*tmp;
	i = 0;

	tmp = NULL;
	tmp = *args;
	tmp->content = NULL;
	tmp->content = ft_strdup(sstr[i]);
	ft_cd_list(&tmp, args, i);
	//free(sstr[i])
	printf("%sstr[%d]%s%s\n", C_UNDERLINE, i,  sstr[i],  C_RESET);
	i++;
	while (sstr[i] != NULL)
	{
		printf("%sstr[%d]%s%s\n", C_UNDERLINE, i,  sstr[i],  C_RESET);
		add_start_list(args);
		/* add_last_list(args); */
		ft_cd_list(&tmp, args, i);
		tmp->content = ft_strdup(sstr[i]);
		//free(sstr[i])
		i++;
	}
	test_display_type(args, "fill_list_args");
	//free(sstr);
	return(0);
}

int	check_data_cmd(t_args **args, char **sstr)
{
	t_args	*tmp;
	int		i;

	i = 0;
	fill_list_args(args, sstr);
	tmp = (*args);
// --->> ALGO PARSING <---- AND CHECK LIST
	while (tmp->next != NULL)
		fill_data_cmd(&tmp, &i, args);
// --->> ALGO PARSING <---- AND CHECK LIST
	test_display_type(args, "check_data_cmd");
	return (0);
}
