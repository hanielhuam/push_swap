/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:34:38 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/25 19:56:09 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	**fill_stack(t_stack **stack, int **numbers)
{
	t_stack	*temp;

	*stack = ft_stcknew(*numbers++);
	if (!*stack)
		return (NULL);
	while (*numbers)
	{
		temp = ft_stcknew(*numbers++);
		if (!temp)
			return (NULL);
		ft_stckadd_back(stack, temp);
	}
	return (stack);
}

t_stack	**init_stack(int **numbers)
{
	t_stack	**stack;

	if (!numbers)
		return (NULL);
	stack = ft_calloc(1, sizeof(t_stack *));
	if (!stack)
	{
		ft_putstr_fd("Allocation Erro!", 2);
		clear_numbers(numbers);
		return (NULL);
	}
	if (!fill_stack(stack, numbers))
	{
		ft_putstr_fd("Allocation Error!", 2);
		clear_numbers_stack(numbers, stack);
		return (NULL);
	}
	free(numbers);
	return (stack);
}
