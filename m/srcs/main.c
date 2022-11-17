/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achretie <achretie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:42:40 by achretie          #+#    #+#             */
/*   Updated: 2022/11/09 19:47:23 by achretie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ret_v;												//valeur de return de notre prompt qui sera a actualiser a chaque nouveau prompt

void	ft_trap(int signal)
{	
	(void)signal;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	ret_v = 130;
}

int	main(int ac, char **av, char **envp)
{
	(void)av;
	(void)ac;
	/*char	*input;
	char	*new;
	char	**new_tab;
	t_args	*l_args;*/
	t_data	data;
	ft_init_data(&data, envp);
	ft_export(&data, "test");
	ft_export(&data, "test=test");
	ft_export(&data, "test");
	ft_export(&data, NULL);
	//ft_unset(&data, "OLDPWD");
	//data.cd_str = ft_strdup("..");
	//ft_env(&data);
	//ft_unset(&data, "SHELL");
	//ft_cd(&data);
	//ft_env(&data);
	/*input = NULL;
	new = NULL;
	new_tab = NULL;
	l_args = NULL;
	input = NULL;
	ret_v = 0;
	signal(SIGINT, ft_trap);							//Catch le Ctrl + C et relance le prompt via ft_trap
	signal(SIGQUIT, SIG_IGN);							//Catch le Ctrl + '\'
	if (ac != 1)
	{
		write(2, "No arguments needed !\n", 23);
		return (0);
	}
	while (1)
	{
		if (init_create_list(&l_args) == -1)
			exit (2);
		input = readline("$> ");
		if (!input)
		{
			printf("exit\n");
			list_free(&l_args);
			exit (0);
		}
		//ft_start_exec(&data, envp); 					//test pour exec une commande
		if (!ft_strncmp(input, "exit", 4))				//test pour exit, exit marche aussi avec "       exit       "
			break ;
		if (!ft_strncmp(input, "env", 3))				//test pour env
			ft_env(&data);
		if (!ft_strncmp(input, "pwd", 3))				//test pour env
			ft_pwd();
		add_history(input);
		new = ft_remove_space(input);					//test de parsing, remplace les caracteres par des 0, ceux entre '' par des 1, ceux entre "" par des 2 et les $ entre "" par des 3
		new_tab = ft_mini_split(new, ' ');
		ft_verify_cmd(l_args, new_tab, envp);
		for (int y = 0; new_tab[y]; y++)
			printf("y = %d : %s\n", y, new_tab[y]);
		check_data_cmd(&l_args, new_tab);
		//free(new);
		int y;
		y=-1;
		while (new_tab[++y])
			free(new_tab[y]);
		free(new_tab);
		free(new);
		free(input);
		list_free(&l_args);
	}
	list_free(&l_args);
	printf("exit\n");*/
	return (0);
}
