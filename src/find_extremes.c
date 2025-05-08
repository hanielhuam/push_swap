/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_extremes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:41:25 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/07 21:49:42 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_maxnode(t_stack **stack)
{
	t_stack	*max;
	t_stack	*temp;

	if (!stack || !*stack)
		return (NULL);
	max = *stack;
	temp = (*stack)->next;
	while (temp != *stack)
	{
		if (*((int *)max->content) < *((int *)temp->content))
			max = temp;
		temp = temp->next;
	}
	return (max);
}

t_stack	*find_minnode(t_stack **stack)
{
	t_stack	*min;
	t_stack	*temp;

	if (!stack || !*stack)
		return (NULL);
	min = *stack;
	temp = (*stack)->next;
	while (temp != *stack)
	{
		if (*((int *)min->content) > *((int *)temp->content))
			min = temp;
		temp = temp->next;
	}
	return (min);
}

static int	count_content(t_list *list)
{
	int	i;

	i = 0;
	while (list && list->content)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int	get_midian(t_list	*ordered_list)
{
	int	size;
	int	i;

	size = count_content(ordered_list);
	i = 0;
	while (i < size / 2)
	{
		ordered_list = ordered_list->next;
		i++;
	}
	return (*((int *)((t_stack *)ordered_list->content)->content));
}
