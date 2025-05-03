/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:45:20 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/03 17:13:36 by hmacedo-         ###   ########.fr       */
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
