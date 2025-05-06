/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   performance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:10:16 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/05 20:57:06 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int which_way_2rotate(t_list *candidates, int size)
{
	int	rotate_steps;
	int r_rotate_steps;

	rotate_steps = 0;
	r_rotate_steps = 0;
	while (candidates)
	{
		if (candidates->content)
		{
			rotate_steps += ((t_stack *)candidates->content)->index;
			r_rotate_steps += (((t_stack *)candidates->content)->index - size);
		}
		candidates = candidates->next;
	}
	if (rotate_steps + r_rotate_steps < 0)
		return (0);
	return (1);
}

static t_stack	*zero_index(t_list *candidates)
{
	t_stack	*temp;
	while (candidates)
	{
		if (candidates->content && !((t_stack *)candidates->content)->index)
		{
			temp = (t_stack *)candidates->content;
			candidates->content = NULL;
			return (temp);
		}
		candidates = candidates->next;
	}
	return (NULL);
}

static t_stack	*closser_2end(t_list *candidates)
{
	t_stack	*temp;
	t_list	*closser;

	closser = exist_content(candidates);
	if (!closser)
		return (NULL);
	candidates = closser->next;
	while (candidates)
	{
		if (candidates->content && compare_positions(closser, candidates) < 0)
			closser = candidates;
		candidates = candidates->next;
	}
	temp = (t_stack *)closser->content;
	closser->content = NULL;
	return (temp);
}

static t_stack	*closser_2start(t_list *candidates)
{
	t_stack	*temp;
	t_list	*closser;

	closser = exist_content(candidates);
	if (!closser)
		return (NULL);
	candidates = closser->next;
	while (candidates)
	{
		if (candidates->content && compare_positions(closser, candidates) > 0)
			closser = candidates;
		candidates = candidates->next;
	}
	temp = (t_stack *)closser->content;
	closser->content = NULL;
	return (temp);
}

t_stack	*best_node_2push(t_list *candidates, int stack_size)
{
	t_stack	*is_zero;

	if (!exist_content(candidates))
		return (NULL);
	is_zero = zero_index(candidates);
	if (is_zero)
		return (is_zero);
	if (which_way_2rotate(candidates, stack_size))
		return (closser_2end(candidates));
	return (closser_2start(candidates));
}
