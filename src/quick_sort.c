/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:42:13 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/08 20:35:00 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bring_minors_2b(t_stack **a, t_stack **b, t_list *minors, int size)
{
	t_list	*init;
	t_stack	*temp;
	int		midian;

	init = minors;
	find_minnodes(a, minors, size);
	midian = get_midian(minors);
	while (exist_content(minors))
	{
		temp = best_node_2push(minors, ft_stcksize(a));
		if (move_2b_midian(a, b, temp, midian))
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

static int	calc_list_size(t_stack **a)
{
	if (ft_stcksize(a) < 10)
		return (2);
	if (ft_stcksize(a) < 20)
		return (4);
	if (ft_stcksize(a) < 50)
		return (12);
	if (ft_stcksize(a) < 100)
		return (20);
	if (ft_stcksize(a) < 250)
		return (35);
	if (ft_stcksize(a) < 500)
		return (50);
	else
		return (ft_stcksize(a) / 10);
}

void	quick_sort(t_stack **a, t_stack **b)
{
	int		size;
	t_list	**minors;

	size = calc_list_size(a);
	minors = init_minorlist((size));
	if (!minors)
		return ;
	while (ft_stcksize(a) > 5)
	{
		if (bring_minors_2b(a, b, *minors, size))
			break ;
	}
	if (!check_order(*a))
		sort_algorithm(a, b);
	while (*b)
		bring_majors_2a(a, b, *minors);
	clear_minorlist(minors);
}
