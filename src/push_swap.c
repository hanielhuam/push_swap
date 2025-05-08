/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:48:56 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/07 21:18:03 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_stacks(t_stack **a, t_stack **b)
{
	if (!a)
		return (1);
	if (!b)
	{
		clear_stack(a);
		ft_putstr_fd("Allocation Error!", 2);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = init_stack(to_int(treat_args(argc, argv)));
	stack_b = ft_calloc(1, sizeof(t_stack *));
	if (check_stacks(stack_a, stack_b))
		return (0);
	//show_stacks(stack_a, stack_b);
	sort_algorithm(stack_a, stack_b);
	//ft_printf("\nApós a ordeenação>\n\n");
	//show_stacks(stack_a, stack_b);
	clear_stack(stack_a);
	clear_stack(stack_b);
	return (0);
}
