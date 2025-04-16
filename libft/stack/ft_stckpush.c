/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:52:19 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/15 21:26:52 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

static void	minus_one(void *content)
{
	int	*temp;

	temp = (int *)content;
	*temp -=1;
	content = (void *)temp;
}

static void	plus_one(void *content)
{
	int	*temp;

	temp = (int *)content;
	*temp -=1;
	content = (void *)temp;
}

void	ft_stckpush(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*temp;

	if (ft_stckcheck(stack_from) || ft_stckcheck(stack_to))
		return ;
	temp = *stack_from;
	*stack_from = (*stack_from)->next;
	(*stack_from)->before = temp->before;
	(*stack_from)->before->next = *stack_from;
	ft_stckiter(*stack_from, minus_one);
	ft_stckiter(*stack_to, plus_one);
	temp->next = *stack_to;
	temp->before = (*stack_to)->before;
	*stack_to = temp;
}

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
	t_stack	**stack_b;
	t_stack *tmp;

	tmp = ft_stcknew(newint_point(11));
	stack_a = &tmp;
	ft_stckadd_front(stack_a, ft_stcknew(newint_point(10)));
	ft_stckadd_back(stack_a, ft_stcknew(newint_point(12)));
	printf("STACK A\n");
	print_stack(stack_a);
	tmp = ft_stcknew(newint_point(111));
	stack_b = &tmp;	
	ft_stckadd_front(stack_a, ft_stcknew(newint_point(110)));
	ft_stckadd_back(stack_a, ft_stcknew(newint_point(112)));
	printf("STACK B\n");
	print_stack(stack_b);
	printf("\ndepois da ft_stckpush\n");
	ft_stckpush(stack_a, stack_b);
	printf("STACK A\n");
	print_stack(stack_a);
	printf("STACK B\n");
	print_stack(stack_b);
	return (0);
}
