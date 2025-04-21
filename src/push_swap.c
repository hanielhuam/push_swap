/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:48:56 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/20 22:48:25 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include "ft_stack.h"
#include <stdio.h>

int	main(void)
{
	t_stack *stack;
	int		nu;

	nu = 42;
	stack = ft_stcknew(&nu);
	printf("nó da posição núemro %d com número = %d\n", stack->index, *((int *)stack->content));
	return (0);
}
