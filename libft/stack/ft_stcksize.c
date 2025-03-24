

#include "ft_stack.h"

int	ft_stcksize(t_stack **stack)
{
	if (ft_stckcheck(stack))
		return (0);
	return ((*stack)->before->index + 1);
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

int	main(void)
{
	t_stack	**stack;
	t_stack *tmp;

	tmp = ft_stcknew(newint_point(42));
	stack = &tmp;
	printf("primeiro print\n");
	printf("size of stack = %d\n", ft_stcksize(stack));
	print_stack(stack);
	ft_stckadd_front(stack, ft_stcknew(newint_point(24)));
	printf("segundo print\n");
	printf("size of stack = %d\n", ft_stcksize(stack));
	print_stack(stack);
	ft_stckadd_front(stack, ft_stcknew(newint_point(84)));
	printf("terceiro print\n");
	printf("size of stack = %d\n", ft_stcksize(stack));
	print_stack(stack);
	return (0);
}
