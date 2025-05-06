/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:40:16 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/06 20:19:34 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*smoller;

	smoller = find_minnode(a);
	if (move_2b(a, b, smoller) && !*b)
		return ;
	sort_three(a);
	move_2a(a, b, *b);
}

static int	bring_minors_2b(t_stack **a, t_stack **b, t_list *minors, int size)
{
	t_list	*init;
	t_stack	*temp;

	init = minors;
	find_minnodes(a, minors, size / 2);
	while (exist_content(minors))
	{
		temp = best_node_2push(minors, ft_stcksize(a));
		if (move_2b(a, b, temp))
		{
			erase_content(init);
			return (1);
		}
	}
	return (0);
}

static void	bring_majors_2a(t_stack **a, t_stack **b, t_list *majors)
{
	t_stack	*temp;

	if (!ft_stcksize(b))
		return ;
	find_maxnodes(b, majors, 2);
	while (exist_content(majors))
	{
		temp = best_node_2push(majors, ft_stcksize(b));
		move_2a(a, b, temp);
		if (compare_nodes(*a, (*a)->next) > 0)
			swap_a(a);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	int		size;
	t_list	**minors;

	size = ft_stcksize(a);
	if (size < 5)
	{
		sort_four(a, b);
		return ;
	}
	minors = init_minorlist((size / 2));
	if (!minors)
		return ;
	if (!bring_minors_2b(a, b, *minors, size))
		sort_three(a);
	bring_majors_2a(a, b, *minors);
	clear_minorlist(minors);
}
