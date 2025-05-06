/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_minnodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:16:37 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/06 20:14:56 by hmacedo-         ###   ########.fr       */
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

static t_stack	*find_next_min(t_stack *min_node, t_stack *init, t_list *list)
{
	t_stack	*temp;

	temp = min_node->next;
	while (temp != init)
	{
		if (compare_nodes(min_node, temp) > 0 && !contains(list, temp))
			min_node = temp;
		temp = temp->next;
	}
	return (min_node);
}

t_list	*find_minnodes(t_stack **stack, t_list *minors, int size)
{
	int		i;
	t_stack	*min_node;
	t_list	*init_list;

	if (ft_stcksize(stack) <= size)
		size = ft_stcksize(stack) - 5;
	init_list = minors;
	i = 0;
	while (i < size)
	{
		min_node = *stack;
		while (contains(init_list, min_node))
			min_node = min_node->next;
		min_node = find_next_min(min_node, *stack, init_list);
		i++;
		minors->content = min_node;
		minors = minors->next;
	}
	return (init_list);
}
