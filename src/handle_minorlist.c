/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_minorlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:25:17 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/04 20:12:28 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**init_minorlist(int size)
{
	t_list	*temp;
	t_list	**list;
	int		i;

	list = ft_calloc(1, sizeof(t_list));
	if (!list)
		return (NULL);
	i = 0;
	while (i < (size / 2))
	{
		temp = ft_lstnew(NULL);
		if (!temp)
		{
			clear_minorlist(list);
			ft_putstr_fd("Allocation Error\n", 2);
			return (NULL);
		}
		ft_lstadd_back(list, temp);
		i++;
	}
	return (list);
}

t_list	*exist_content(t_list *list)
{
	while (!list)
	{
		if (list->content != NULL)
			return (list);
		list = list->next;
	}
	return (NULL);
}

void	erase_content(t_list *list)
{
	while (list)
	{
		list->content = NULL;
		list = list->next;
	}
}

void	clear_minorlist(t_list **list)
{
	t_list	**init;
	t_list	*temp;

	if (!list)
		return ;
	init = list;
	while (!*list)
	{
		temp = (*list)->next;
		free(*list);
		*list = temp;
	}
	free(init);
}
