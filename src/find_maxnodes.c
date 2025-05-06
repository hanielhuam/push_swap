/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_maxnodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:18:57 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/06 20:15:38 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	contains(t_list *list, t_stack *node)
{
	while (list)
	{
		if (list->content == node)
			return (1);
		list = list->next;
	}
	return (0);
}

static t_stack	*find_next_max(t_stack *max_node, t_stack *init, t_list *list)
{
	t_stack	*temp;

	temp = max_node->next;
	while (temp != init)
	{
		if (compare_nodes(max_node, temp) < 0 && !contains(list, temp))
			max_node = temp;
		temp = temp->next;
	}
	return (max_node);
}

t_list	*find_maxnodes(t_stack **stack, t_list *majors, int size)
{
	int		i;
	t_stack	*max_node;
	t_list	*init_list;

	if (ft_stcksize(stack) < size)
		size = ft_stcksize(stack);
	init_list = majors;
	i = 0;
	while (i < size)
	{
		max_node = *stack;
		while (contains(init_list, max_node))
			max_node = max_node->next;
		max_node = find_next_max(max_node, *stack, init_list);
		i++;
		majors->content = max_node;
		majors = majors->next;
	}
	return (init_list);
}
