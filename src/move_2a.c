/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:19:35 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/03 17:00:30 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_2a(t_stack **a, t_stack **b, t_stack *node)
{
	int	size;

	size = ft_stcksize(a);
	while (node->index != 0)
	{
		if (node->index <= size / 2)
			rotate_b(b, 0);
		else
			rotate_b(b, 1);
	}
	push_a(a, b);
}
