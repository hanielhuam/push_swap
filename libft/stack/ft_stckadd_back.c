/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:29:06 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/08 21:15:54 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stckadd_back(t_stack **stack, t_stack *new)
{
	if (ft_stckcheck(stack) || !new)
		return ;
	new->index = (*stack)->before->index + 1;
	new->next = *stack;
	new->before = (*stack)->before;
	(*stack)->before->next = new;
	(*stack)->before = new;
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
	t_stack	**stack;
	t_stack *tmp;

	tmp = ft_stcknew(newint_point(42));
	stack = &tmp;
	printf("primeiro print\n");
	print_stack(stack);
	ft_stckadd_back(stack, ft_stcknew(newint_point(24)));
	printf("segundo print\n");
	print_stack(stack);
	ft_stckadd_back(stack, ft_stcknew(newint_point(84)));
	printf("terceiro print\n");
	print_stack(stack);
	return (0);
}*/
