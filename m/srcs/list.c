/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:04:03 by mafissie          #+#    #+#             */
/*   Updated: 2022/10/07 18:58:43 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mini.h"
#include <stdlib.h>

int	init_create_list(t_args **list)
{
	t_args	*tmp;

	tmp = NULL;
	tmp = malloc(sizeof(t_args));
	if (tmp == NULL)
		return (-1);
	tmp->next = NULL;
	tmp->prev = NULL;
	*list = tmp;
	return (1);
}

int	add_last_list(t_args **list)
{
	t_args	*tmp;
	t_args	*tmp_prev;

	tmp = NULL;
	tmp = (*list);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp_prev = tmp;
	tmp->next = malloc(sizeof(t_args));
	if (tmp->next == NULL)
		return (list_free(list));
	tmp = tmp->next;
	tmp->prev = tmp_prev;
	tmp->next = NULL;
	tmp->content_test = NULL;
	tmp->index_start = 0;
	tmp->index_next = 0;
	tmp->index = tmp_prev->index + 1;
	tmp->content = NULL;
	tmp->path = NULL;
	tmp->type = 0;
	tmp->error = 0;
	return (1);
}

int	add_start_list(t_args **list)
{
	t_args	*tmp;
	t_args	*tmp_prev;

	tmp = NULL;
	tmp = (*list);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp_prev = tmp;
	tmp->next = malloc(sizeof(t_args));
	if (tmp->next == NULL)
	{
		list_free(list);
		return (-1);
	}
	tmp = tmp->next;
	tmp->prev = tmp_prev;
	tmp->next = NULL;
	tmp->content_test = NULL;
	tmp->index_start = 0;
	tmp->index_next = 0;
	ft_indexage_list(list);
	tmp->content = NULL;
	tmp->path = NULL;
	tmp->type = 0;
	tmp->error = 0;
	return (1);
}

int	list_free(t_args **list)
{
	t_args	*tmp;
	static int i;

	tmp = NULL;
	tmp = *(list);
	if (tmp == NULL)
		return (-1);
	if (*list == NULL)
		return (-1);
	while ((*list)->next != NULL)
	{
		test_display_type(list , "list_free");
		printf("%slist_free - [%d]\n%s", C_RED, i++, C_RESET);
		tmp = tmp->next;
		/* free((*list)->content_test); */
		free((*list)->content);
		(*list)->content = NULL;
		/* free((*list)->path); */
		free((*list));
		*list = NULL;
		(*list) = tmp;
	}
	test_display_type(list , "list_free");
	/* printf("%slist_free - [%d]\n%s", C_RED, i++, C_RESET); */
	/* free((*list)->content_test); */
	/* if (*list == NULL) */
		/* return (1); */
	/* (*list)->content = NULL; */
	/* free((*list)->path); */
	free(*list);
	list = NULL;
	test_display_type(list , "list_free[END FUN]");
	return (1);
}
