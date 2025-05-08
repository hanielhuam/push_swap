/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:45:20 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/07 20:40:09 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_2b(t_stack **a, t_stack **b, t_stack *node)
{
	int	size;

	size = ft_stcksize(a);
	while (node->index != 0)
	{
		if (node->index <= size / 2)
			rotate_a(a, 0);
		else
			rotate_a(a, 1);
		if (check_order(*a))
			return (1);
	}
	push_b(a, b);
	return (0);
}

int	move_2b_midian(t_stack **a, t_stack **b, t_stack *node, int midian)
{
	int	size;

	size = ft_stcksize(a);
	while (node->index != 0)
	{
		if (node->index <= size / 2)
			rotate_a(a, 0);
		else
			rotate_a(a, 1);
		if (check_order(*a))
			return (1);
	}
	push_b(a, b);
	if (ft_stcksize(b) > 1 && *((int *)(*b)->content) < midian)
		rotate_b(b, 0);
	return (0);
}
