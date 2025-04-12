/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:46:26 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/11 21:30:46 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stckdelone(t_stack *element, void (*del)(void*))
{
	if (!element)
		return ;
	del(element->content);
	free(element);
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

void	del_stck(void * content)
{
	free(content);
}

int	main(void)
{
	int	*nu;
	t_stack *el;

	nu = newint_point(42);
	el = ft_stcknew(nu);
	printf("index of el is %d\nint of nu is %d\n", el->index, *nu);
	ft_stckdelone(el, del_stck);
	printf("after delone\n");
	printf("index of el is %d\nint of nu is %d\n", el->index, *nu);
	return (0);
}
