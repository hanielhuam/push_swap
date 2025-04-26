/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:24:22 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/25 20:36:04 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_nodes(t_stack **a, t_stack **b, int first)
{
	if (first)
		ft_printf("  A  |  B  \n");
	if (*a && ((*a)->index != 0 || first))
	{
		ft_printf(" %d  |", *((int *)(*a)->content));
		*a = (*a)->next;
	}
	else
		ft_printf("    |");
	if (*b && ((*b)->index != 0 || first))
	{
		ft_printf("  %d \n", *((int *)(*b)->content));
		*b = (*b)->next;
	}
	else
		ft_printf("    \n");
}

void	show_stacks(t_stack **a, t_stack **b)
{
	if (!a || !b)
		return ;
	print_nodes(a, b, 1);
	while ((*a && (*a)->index != 0) || (*b && (*b)->index != 0))
	{
		print_nodes(a, b, 0);
	}
}
