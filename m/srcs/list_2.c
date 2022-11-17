/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:45:14 by mafissie          #+#    #+#             */
/*   Updated: 2022/10/07 18:48:29 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
#include "./mini.h" 

void	ft_cd_list(t_args **tmp, t_args **source, int i)
{
	t_args	*mv;

	mv = NULL;
	mv = *source;
	if (mv == NULL)
		return ;
	while (mv->next != NULL)
	{
		if (mv->index == i)
			break ;
		mv = mv->next;
	}
	*tmp = mv;
}
