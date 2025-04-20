/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:29:36 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/17 21:54:59 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

static void	minusone(t_stack *node)
{
	node->index -= 1;
}

static void	plusone(t_stack *node)
{
	node->index += 1;
}

void	ft_stckrotate(t_stack **stack, int reverse)
{
	if (ft_stckcheck(stack))
		return ;
	if (!reverse)
	{
		ft_stckiter_s(*stack, plusone);
		*stack = (*stack)->before;
		(*stack)->index = 0;
	}
	else
	{
		ft_stckiter_s(*stack, minusone);
		(*stack)->index = (*stack)->before->index + 1;
		*stack = (*stack)->next;
	}
}
/*
#include <stdio.h>

int	*newint_point(int nu)
{
	int	*nup;

	nup = ft_calloc(1, sizeof(int));
	*nup = nu;
	return (nup);
}

void	print_t_stack(t_stack *element)
{
	printf("element->index = %d\n", element->index);
	printf("element->before = %p\n", element->before);
	printf("element->next = %p\n", element->next);
	printf("element->content = %d\n", *((int *)element->content));
}

void	print_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
	{
		printf("stack está nula\n");
		return ;
	}
	print_t_stack(*stack);
	temp = (*stack)->next;
	while (temp != *stack)
	{
		printf("\n");
		print_t_stack(temp);
		temp = temp->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack	**stack_a;
	t_stack *tmp_a;

	tmp_a = ft_stcknew(newint_point(42));
	stack_a = &tmp_a;
	ft_stckadd_front(stack_a, ft_stcknew(newint_point(24)));
	ft_stckadd_back(stack_a, ft_stcknew(newint_point(84)));
	print_stack(stack_a);
	printf("\ndepois da ft_stckrotate\n");
	ft_stckrotate(stack_a, 0);
	print_stack(stack_a);
	printf("\ndepois da ft_stckrotate reverso\n");
	ft_stckrotate(stack_a, 1);
	print_stack(stack_a);
	return (0);
}*/
