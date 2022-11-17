/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:39:09 by mafissie          #+#    #+#             */
/*   Updated: 2022/10/18 18:41:50 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mini.h"

void	construct_cmd(t_args **content, int *index, char *str, t_args **args)
{
	//access
	(void)content;
	(void)index;
	(void)str;
	(void)args;
	(*content)->type = CMD;
}

void	construct_builtins(t_args **content, int *index, char *str, t_args **args)
{
	//access	
	(void)content;
	(void)index;
	(void)str;
	(void)args;
	(*content)->type = BUILTINS;
}

void	construct_env(t_args **content, int *index, char *str, t_args **args)
{
	(void)content;
	(void)index;
	(void)str;
	(void)args;
	(*content)->type = ENV;
}

void	construct_great(t_args **content, int *index, char *str, t_args **args) 
{
	// << fonction generique pour substr [subtr]""<<""[substr]
	(void)content;
	(void)index;
	(void)str;
	(void)args;
	(*content)->type = GREAT;
}// >

void	construct_d_great(t_args **content, int *index, char *str, t_args **args)
{
	// << fonction generique pour substr [subtr]""<<""[substr]
	(void)content;
	(void)index;
	(void)str;
	(void)args;
	(*content)->type = D_GREAT;
} //>>

void	construct_less(t_args **content, int *index, char *str, t_args **args)
{
	// << fonction generique pour substr [subtr]""<<""[substr]
	(void)content;
	(void)index;
	(void)str;
	(void)args;
	(*content)->type = LESS;
} // <

void	construct_d_less(t_args **content, int *index, char *str, t_args **args) 
{
	// << fonction generique pour substr [subtr]""<<""[substr]
	(void)content;
	(void)index;
	(void)str;
	(void)args;
	(*content)->type = D_LESS;
}// <<


void	construct_new_path(t_args **content, int *index, char *str, t_args **args)
{
	(void)content;
	(void)index;
	(void)str;
	(void)args;
	(*content)->type = NEW_PATH;
}

void	construct_pipe(t_args **content, int *index, char *str, t_args **args)
{
	// << fonction generique pour substr [subtr]""<<""[substr]
	(void)content;
	(void)index;
	(void)str;
	(void)args;
	(*content)->type = PIPE;
}

void	construct_cmd_opt(t_args **content, int *index, char *str, t_args **args)
{
	(void)content;
	(void)index;
	(void)str;
	(void)args;
	(*content)->type = CMD_OPT;
}
