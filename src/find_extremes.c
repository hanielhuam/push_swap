/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_extremes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:41:25 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/04 16:18:10 by hmacedo-         ###   ########.fr       */
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

int	find_maxint(t_stack **stack)
{
	return (*((int *)find_maxnode(stack)->content));
}

int	find_minint(t_stack **stack)
{
	return (*((int *)find_minnode(stack)->content));
}
